<?php
abstract class SENE_Model {
	public $db;
	public $field = array();

	public function __construct(){
		$this->loadEngine();
	}

	private function loadEngine(){
		require_once(SENEKEROSINE."/SENE_MySQLi_Engine.php");
		$this->db = new SENE_MySQLi_Engine();
	}

	public function exec($sql){
		return $this->db->exec($sql);
	}

	public function multiExec($sql){
		$res = $this->db->multiExec($sql);
	}

	public function select($sql,$cache_engine=0,$flushcache=0,$tipe="object"){
		return $this->db->select($sql,$cache_engine,$flushcache,$tipe);
	}
	public function lastId(){
		return $this->db->lastId();
	}
	public function esc($str){
		return $this->db->esc($str);
	}
	public function prettyName($name){
		$name=strtolower(trim($name));
		$names=explode("_", $name);
		$name='';
		foreach($names as $n){
			$name=$name.''.ucfirst($n).' ';
		}
		return $name;
	}
	public function filter(&$str){
		$str=filter_var($str,FILTER_SANITIZE_SPECIAL_CHARS);
	}
	public function setDebug($is_debug){
		return $this->db->setDebug($is_debug);
	}
}
