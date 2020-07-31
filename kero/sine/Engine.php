<?php
namespace Kero\Sine;

DEFINE('SENE_VERSION','3.2.1');


class Engine {
  protected static $__instance;

	var $admin_url="";
	var $notfound=NOTFOUND_CONTROLLER;
	var $default=DEFAULT_CONTROLLER;
	var $core_prefix = 'SM_';
	var $core_controller = '';
	var $core_model = '';
	var $routes;
	public function __construct(){
		require_once SENEKEROSINE."/SENE_Controller.php";
		require_once SENEKEROSINE."/Model.php";
		if(isset($GLOBALS['core_prefix'])) if(!empty($GLOBALS['core_prefix'])) $this->core_prefix = $GLOBALS['core_prefix'];
		if($GLOBALS['core_controller']) if(!empty($GLOBALS['core_controller'])) $this->core_controller = $GLOBALS['core_controller'];
		if($GLOBALS['core_model']) if(!empty($GLOBALS['core_model'])) $this->core_model = $GLOBALS['core_model'];

		$this->admin_url=ADMIN_URL;
		self::$__instance = $this;

		if(!isset($GLOBALS['routes'])) $GLOBALS['routes'] = array();
		$routes = $GLOBALS['routes'];
		$rs = array();
		foreach($routes as $key=>$val){
			$key = trim($key,"/");
			$val = trim($val,"/");
			$rs[$key] = $val;
		}
		$this->routes = $rs;

		$sene_method = $GLOBALS['sene_method'];
		if(isset($_SERVER['argv'])){
			if(count($_SERVER['argv'])>1){
				$i=0;
				$_SERVER[$sene_method] = '';
				foreach($_SERVER['argv'] as $argv){
					$i++;
					if($i==1) continue;
					$_SERVER[$sene_method] .= '/'.$argv;
				}
				unset($i);
				unset($argv);
			}
		}
		unset($sene_method);

	}
  public static function getInstance(){
    return self::$_instance;
  }
	public function Engine(){
		$core_controller_file = SENECORE.$this->core_prefix.$this->core_controller.'.php';
		$core_model_file = SENECORE.$this->core_prefix.$this->core_model.'.php';

		if(!empty($this->core_controller) && !empty($this->core_prefix)){
			if(file_exists($core_controller_file)){
				require_once($core_controller_file);
			}else{
				$error_msg = 'unable to load core controller on '.$core_controller_file;
				$core_controller_file = SENECORE.$this->core_prefix.$this->core_controller.'.php';
				error_log($error_msg);
				trigger_error($error_msg);
			}
		}
		if(!empty($this->core_model) && !empty($this->core_prefix)){
			if(file_exists($core_model_file)){
				require_once($core_model_file);
			}else{
				$error_msg = 'unable to load core model on '.$core_controller_file;
				$core_controller_file = SENECORE.$this->core_prefix.$this->core_controller.'.php';
				error_log($error_msg);
				trigger_error($error_msg);
			}
		}

		$this->newRouteFolder();
    unset($this->core_prefix);
    unset($this->core_model);
    unset($core_controller_file);
    unset($core_model_file);
	}
	private function defaultController(){
		$cname = $this->default."";
		require_once SENECONTROLLER.$this->default.".php";
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
				$cname = strtr($cname,'-','_');;
				if(class_exists($cname)){
					$cname = new $cname();
					$func = "slugParent";
					$reflection = new \ReflectionMethod($cname, $func);
					$args = array();
					$args[0] = $slug_parent;
					$args[1] = $slug_child;
					$reflection->invokeArgs($cname,$args);
				}
			}
		}
	}
	private function ovrRoutes($paths=array()){
		$path = strtolower(implode('/', $paths));
		$path = trim($path,'/');
		$target = '';
		$routes = $this->routes;
		foreach($routes as $key=>$val){
			$key = strtolower(trim($key,"/"));
			$val = strtolower(trim($val,"/"));
			$key = str_replace(array(':any', ':num'), array('[^/]+', '[0-9]+'), $key);
			if(preg_match('#^'.$key.'$#', $path, $matches)){
				$target = '/'.preg_replace('#^'.$key.'$#', $val, $path);
			}
		}
		if(!empty($target)) return explode("/",$target);
		return $paths;
	}
	private function newRouteFolder(){
		$found=0;
		$sene_method = $GLOBALS['sene_method'];
		if(isset($_SERVER[$sene_method])){
			$path = $_SERVER[$sene_method];
      $path = strtr($path,'//','/');
			$path = explode("/",str_replace("//","/",$path));
			$i=0;
			foreach($path as $p){
				if(strlen($p)>0){
					$pos = strpos($p, '?');
					if ($pos !== false) {
						unset($path[$i]);
					}
				}
				$i++;
			}
			unset($p);
			$path = $this->ovrRoutes($path);
      if(!isset($path[1])) $path[1] = '';
			$path[1] = strtr($path[1],'-','_');
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
					$dirn = $newpath.'/'.$path[2];
					$filename = realpath($newpath.''.$path[2].".php");
					//var_dump($filename);
					if(is_dir($dirn)){
						$dirn = rtrim($dirn,'/');
						$dirn = $dirn.'/';
						if(!isset($path[3])) $path[3] = '';
						if(empty($path[3])) $path[3] = 'home';
						$filename = realpath($dirn.''.$path[3].".php");
						if(is_file($filename)){
							require_once $filename;
							$cname = basename($filename, ".php");
							$cname = strtr($cname,'-','_');;
							if (!class_exists($cname, false)) {
								trigger_error("Unable to load class: $cname. Please check classname on controller is exists in ".SENECONTROLLER.$path[2].'/'.$path[3].".php", E_USER_ERROR);
								die();
							}
							$cname = new $cname();
							$func = "index";
							if(isset($path[4])){
								if(empty($path[4])){
									$func = "index";
								}else{
									$func = $path[4];
								}
							}
							$func = strtr($func,'-','_');
							if(method_exists($cname,$func)){
								$reflection = new \ReflectionMethod($cname, $func);
								if (!$reflection->isPublic()){
									$this->notFound();
								}

								$args=array();
                $num = $reflection->getNumberOfParameters();
								if($num>0){
									for($j=0;$j<$num;$j++){
										if(isset($path[(5+$j)])){
											$args[]=$path[(5+$j)];
										}else{
											$args[]=NULL;
										}
									}
								}
                unset($j,$num);
								$reflection->invokeArgs($cname,$args);
                unset($cname,$args);
							}else{
								$this->notFound($newpath);
							}
						}else{
							$this->notFound($newpath);
						}
					}else	if(is_file($filename)){
						require_once $filename;
						$cname = basename($filename, ".php");
						$cname = strtr($cname,'-','_');;
						if (!class_exists($cname, false)) {
							trigger_error("Unable to load class: $cname. Please check classname on controller is exists in ".SENECONTROLLER." triggered ", E_USER_ERROR);
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
							$reflection = new \ReflectionMethod($cname, $func);
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
						$cname = strtr($cname,'-','_');;
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
								$reflection = new \ReflectionMethod($cname, $func);
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
	private function newRouteFolder2(){
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
					$dirn = $newpath.'/'.$path[2];
					$filename = realpath($newpath.''.$path[2].".php");
					//var_dump($filename);
					if(is_dir($dirn)){
						$dirn = rtrim($dirn,'/');
						$dirn = $dirn.'/';
						if(!isset($path[3])) $path[3] = '';
						if(empty($path[3])) $path[3] = 'home';
						$filename = realpath($dirn.''.$path[3].".php");
						if(is_file($filename)){
							require_once $filename;
							$cname = basename($filename, ".php");
							$cname = strtr($cname,'-','_');;
							if (!class_exists($cname, false)) {
								trigger_error("Unable to load class: $cname. Please check classname on controller is exists in ".SENECONTROLLER." triggered ", E_USER_ERROR);
								die();
							}
							$cname = new $cname();
							$func = "index";
							if(isset($path[4])){
								if(empty($path[4])){
									$func = "index";
								}else{
									$func = $path[4];
								}
							}
							$func = str_replace('-','_',$func);
							if(method_exists($cname,$func)){
								$reflection = new \ReflectionMethod($cname, $func);
								if (!$reflection->isPublic()){
									$this->notFound();
								}
								$args=array();
								$num = $reflection->getNumberOfParameters();
								if($num>0){
									for($j=0;$j<$num;$j++){
										if(isset($path[(5+$j)])){
											$args[]=$path[(5+$j)];
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
							$this->notFound($newpath);
						}
					}else	if(is_file($filename)){
						require_once $filename;
						$cname = basename($filename, ".php");
						$cname = strtr($cname,'-','_');;
						if (!class_exists($cname, false)) {
							trigger_error("Unable to load class: $cname. Please check classname on controller is exists in ".SENECONTROLLER." triggered ", E_USER_ERROR);
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
							$reflection = new \ReflectionMethod($cname, $func);
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
						$cname = strtr($cname,'-','_');;
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
								$reflection = new \ReflectionMethod($cname, $func);
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
					$cname = strtr($cname,'-','_');;
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
						$reflection = new \ReflectionMethod($cname, $func);
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
							$cname = strtr($cname,'-','_');;
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
								$reflection = new \ReflectionMethod($cname, $func);
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
function redir($url,$time=0,$type=0){
	if($type=="1" || $type==1){
		if($time){
			echo '<meta http-equiv="refresh" content="'.$time.';URL=\''.$url.'\'" />';
		}else{
			echo '<meta http-equiv="refresh" content="1;URL=\''.$url.'\'" />';
		}
	}else{
		if($time>1){
      header('HTTP/1.1 301 Moved Permanently');
			header("Refresh:".$time."; url=".$url);
		}else{
      header('HTTP/1.1 301 Moved Permanently');
			header('Location: ' . $url);
		}
	}
}
