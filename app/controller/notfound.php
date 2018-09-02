<?php
class Notfound extends JI_Controller{
	public function __constructx(){
    parent::__construct();

	}
	public function index(){
		$data = $this->__init();
		header("HTTP/1.0 404 Not Found");
		$this->setTitle('Not Found'.$this->site_suffix);
		$this->loadLayout('notfound');
		$this->render();
	}
}
