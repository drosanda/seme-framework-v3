<?php
class Home extends JI_Controller{

	public function __construct(){
    parent::__construct();
		$this->setTheme('front');
	}
	public function index(){
		$data = $this->__init();

		$this->loadLayout("col-1",$data);
		$this->render();
	}

}
