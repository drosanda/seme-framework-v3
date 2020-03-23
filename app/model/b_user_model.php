<?php
class B_User_Model extends SENE_Model{
	var $tbl = 'b_user';
	var $tbl_as = 'bu';
	public function __construct(){
		parent::__construct();
		$this->db->from($this->tbl,$this->tbl_as);
	}
	public function set($di){
		if(!is_array($di)) return 0;
		$this->db->insert($this->tbl,$di,0,0);
		return $this->db->last_id;
	}
}