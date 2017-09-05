<?php
class SENE_Engine{
  protected static $__instance;
	
	var $admin_url="";
	var $notfound=NOTFOUND_CONTROLLER;
	var $default=DEFAULT_CONTROLLER;
	public function __construct(){
		require_once SENEKEROSINE."/SENE_Controller.php";
		require_once SENEKEROSINE."/SENE_Model.php";
		$this->admin_url=ADMIN_URL;
		self::$__instance = $this;
	}
  public static function getInstance(){
    return self::$_instance;
  }
	public function SENE_Engine(){
		$this->newRouteFolder();
	}
	private function defaultController(){
		$cname = $this->default."";
		include SENECONTROLLER.$this->default.".php";
		$cname = new $cname();
		$cname->index();
	}
	private function notFound($newpath=""){
		$cname = $this->notfound."";
		if(file_exists($newpath.$this->notfound.".php")){
			require_once($newpath.$this->notfound.".php");
		}else{
			require_once(SENECONTROLLER.$this->notfound.".php");
		}
		$cname = new $cname();
		$cname->index();
	}
	private function globalHandlerCMSPage($path=array()){
		if(count($path)>1){
			$slug_parent = $path[1];
			$slug_child = "";
			if(isset($path[2])) $slug_child = $path[2];
			$filename = realpath(SENECONTROLLER."cms_handler.php");
			//die($filename);
			if(is_file($filename) && !empty($slug_parent)){
				require_once $filename;
				$cname = basename($filename, ".php");
				$cname = str_replace('-','_',$cname);
				if(class_exists($cname)){
					$cname = new $cname();
					$func = "slugParent";
					$reflection = new ReflectionMethod($cname, $func);
					$args = array();
					$args[0] = $slug_parent;
					$args[1] = $slug_child;
					$reflection->invokeArgs($cname,$args);
				}
			}
		}
	}
	private function newRouteFolder(){
		$found=0;
		$sene_method = $GLOBALS['sene_method'];
		if(isset($_SERVER[$sene_method])){
			$path=$_SERVER[$sene_method];
			$path=explode("/",$path);
			$i=0;
			foreach($path as $p){
				if(!empty($p)){
					$pos = strpos($p, '?');
					if ($pos !== false) {
						//echo "pos: ".$pos;
						unset($path[$i]);
					}
				}
				$i++;
			}
			unset($p);
			$path[1] = str_replace('-','_',$path[1]);
			if((!empty($path[1]))){
				if($path[1] == "admin" && $this->admin_url !="admin"){
					$newpath = realpath(SENECONTROLLER.$path[1]);
					$this->notFound($newpath);
					die();
				}
					
				if($this->admin_url==$path[1]){ 
					$path[1]="admin";
				}else{
					$this->globalHandlerCMSPage($path);
				}
				
				$newpath = realpath(SENECONTROLLER.$path[1]);
				
				if(is_dir($newpath)){
					$newpath = rtrim($newpath,'/');
					$newpath = $newpath.'/';
					if(empty($path[2])) $path[2] = 'home';
					$filename = realpath($newpath.''.$path[2].".php");
					//var_dump($filename);
					if(is_file($filename)){
						require_once $filename;
						$cname = basename($filename, ".php");
						$cname = str_replace('-','_',$cname);
						if (!class_exists($cname, false)) {
							trigger_error("Unable to load class: $cname", E_USER_WARNING);
							trigger_error("Please check classname on controller is exists in ".SENECONTROLLER." triggered ", E_USER_ERROR);
							die();
						}
						$cname = new $cname();
						$func = "index";
						if(isset($path[3])){
							if(empty($path[3])){
								$func = "index";
							}else{
								$func = $path[3];
							}
						}
						$func = str_replace('-','_',$func);
						if(method_exists($cname,$func)){
							$reflection = new ReflectionMethod($cname, $func);
							if (!$reflection->isPublic()){
								$this->notFound();
							}
							$args=array();
							$num = $reflection->getNumberOfParameters();
							if($num>0){
								for($j=0;$j<$num;$j++){
									if(isset($path[(4+$j)])){
										$args[]=$path[(4+$j)];
									}else{
										$args[]=NULL;
									}
								}
							}
							$reflection->invokeArgs($cname,$args);
						}else{
							$this->notFound($newpath);
						}
					}else{
					//die("wdnlknl");
						$this->notFound($newpath);
					}
				}else{
					$filename = realpath(SENECONTROLLER.$path[1].".php");
					if(is_file($filename)){
						include $filename;
						$cname = basename($filename, ".php");
						$cname = str_replace('-','_',$cname);
						if(class_exists($cname)){
							$cname = new $cname();
							$func = "index";
							if(isset($path[2])){
								if(empty($path[2])){
									$func = "index";
								}else{
									$func = $path[2];
								}
							}
							$func = str_replace('-','_',$func);
							if(method_exists($cname,$func)){
								$reflection = new ReflectionMethod($cname, $func);
								if (!$reflection->isPublic()){
									$this->notFound();
								}
								$args=array();
								$num = $reflection->getNumberOfParameters();
								if($num>0){
									for($j=0;$j<$num;$j++){
										if(isset($path[(3+$j)])){
											$args[]=$path[(3+$j)];
										}else{
											$args[]=NULL;
										}
									}
								}
								$reflection->invokeArgs($cname,$args);
							}else{
								
								$this->notFound();
							}
						}else{
							//echo 'controller not found';
							$this->notFound();
						}
					}else{
						$this->notFound();
					}
				}
			}else{
				$this->defaultController();
			}
		}else{
			$this->defaultController();
		}
	}
	private function newRoute(){
		$found=0;
		$sene_method = $GLOBALS['sene_method'];
		if(isset($_SERVER[$sene_method])){
			$path=$_SERVER[$sene_method];
			$path=explode("/",$path);
			$path[1] = str_replace('-','_',$path[1]);
			if((!empty($path[1]))){
				$filename = realpath(SENECONTROLLER.$path[1].".php");
				if(is_file($filename)){
					include $filename;
					$cname = basename($filename, ".php");
					$cname = str_replace('-','_',$cname);
					$cname = new $cname();
					$func = "index";
					if(isset($path[2])){
						if(empty($path[2])){
							$func = "index";
						}else{
							$func = $path[2];
						}
					}
							
					if(method_exists($cname,$func)){
						$reflection = new ReflectionMethod($cname, $func);
						if (!$reflection->isPublic()){
							$this->notFound();
						}
						$args=array();
						$num = $reflection->getNumberOfParameters();
						if($num>0){
							for($j=0;$j<$num;$j++){
								if(isset($path[(3+$j)])){
									$args[]=$path[(3+$j)];
								}else{
									$args[]=NULL;
								}
							}
						}
						$reflection->invokeArgs($cname,$args);
					}else{
						$this->notFound();
					}
				}else{
					$this->notFound();
				}
			}else{
				$this->defaultController();
			}
		}else{
			$this->defaultController();
		}
	}
	private function newRoute2(){
		$found=0;
		$sene_method = $GLOBALS['sene_method'];
		if(isset($_SERVER[$sene_method])){
			$path=$_SERVER[$sene_method];
			$path=explode("/",$path);
			foreach (glob(SENECONTROLLER."*.php") as $filename){
				if(isset($_SERVER['PATH_INFO'])){
					$path[1] = str_replace('-','_',$path[1]);
					if((!empty($path[1])) && (basename($filename, ".php")==$path[1])){
						if(is_file($filename)){
							include $filename;
							$cname = basename($filename, ".php");
							$cname = str_replace('-','_',$cname);
							$cname = new $cname();
							$func = "index";
							if(isset($path[2])){
								if(empty($path[2])){
									$func = "index";
								}else{
									$func = $path[2];
								}
							}
							
							if(method_exists($cname,$func)){
								$reflection = new ReflectionMethod($cname, $func);
								if (!$reflection->isPublic()){
									$found=0;
									break;
								}
								$args=array();
								$num = $reflection->getNumberOfParameters();
								if($num>0){
									for($j=0;$j<$num;$j++){
										if(isset($path[(3+$j)])){
											$args[]=$path[(3+$j)];
										}else{
											$args[]="";
										}
									}
									$reflection->invokeArgs($cname,$args);
									$found=1;
									break;
								}else{
									$reflection->invokeArgs($cname,$args);
									$found=1;
									break;
								}
								
							}else{
								$found=0;
								break;
							}
						}else{
							$found=0;
							break;
						}
					}else{
						$found=0;
						//continue to next file
					}
				}else{
					$found=0;
					break;
				}
			}
			if($found == 0){
				$this->notFound();
			}
		}else{
			$cname = $this->default."";
			include SENECONTROLLER.$this->default.".php";
			$cname = new $cname();
			$cname->index();
		}
	}
	private function aktif($route=1){
		if($route){
			$this->newRoute();
		}else{
			foreach (glob(SENECONTROLLER."*.php") as $filename){
				if(isset($_GET[basename($filename, ".php")])){
					if(is_file($filename)){
						include $filename;
						foreach (glob(SENEMODEL."*.php") as $fmodel){
							include $fmodel;
						}
						$content = new Content();
						$found = 1;
						break;
					}else{
						include SENEVIEW.$this->notfound.".php";
						content();
						///echo 'not found';
						$found = 1;
						break;
					}
				}else{
					//print_r($_GET);
					$found = 0;
					//break;
				}
			}
			if($found == 0){
				include SENECONTROLLER.$this->notfound.".php";
				$content = new Content();
				//print_r($_GET);
			}
		}
	}
	
	private function inaktif(){
		include SENECONTROLLER.$this->default.".php";
		$content = new Content();
	}
}
function redir($url,$time=0,$type=1){
	if($type==0){
		header("Location : ".$url);
	}else{
		if($time){
			echo '<meta http-equiv="refresh" content="'.$time.';URL=\''.$url.'\'" />';
		}else{
			echo '<meta http-equiv="refresh" content="1;URL=\''.$url.'\'" />';
		}
	}
}
function base_url($url=""){
	if(empty($url)) $url = "";
	//var_dump($url);
	//die();
	return BASEURL.$url;
}
function base_url_admin($url=""){
	return $GLOBALS['site'].ADMIN_URL.'/'.$url;
}
function enkrip($str){
	return base64_encode(base64_encode($str));
}
function dekrip($str){
	return base64_decode(base64_decode($str));
}
DEFINE('SALTKEY',$GLOBALS['saltkey']);
function keyAdm(){
	return sha1(date("*W*Y-m").SALTKEY);
}
function get_caller_info() {
	$c = '';
	$file = '';
	$func = '';
	$class = '';
	$trace = debug_backtrace();
	if (isset($trace[2])) {
		$file = $trace[1]['file'];
		$func = $trace[2]['function'];
		if ((substr($func, 0, 7) == 'include') || (substr($func, 0, 7) == 'require')) {
			$func = '';
		}
		} else if (isset($trace[1])) {
		$file = $trace[1]['file'];
		$func = '';
	}
	if (isset($trace[3]['class'])) {
		$class = $trace[3]['class'];
		$func = $trace[3]['function'];
		$file = $trace[2]['file'];
		} else if (isset($trace[2]['class'])) {
		$class = $trace[2]['class'];
		$func = $trace[2]['function'];
		$file = $trace[1]['file'];
	}
	if ($file != '') $file = basename($file);
	$c = $file . ": ";
	$c .= ($class != '') ? ":" . $class . "->" : "";
	$c .= ($func != '') ? $func . "(): " : "";
	return($c);
}
