<?php
class Notfound extends SENE_Controller{
	public function __constructx(){
    parent::__construct();
		
	}
	private function __init(){
		
	}
	public function index(){
		header("HTTP/1.0 404 Not Found");
		echo '404 not found';
	}
}
