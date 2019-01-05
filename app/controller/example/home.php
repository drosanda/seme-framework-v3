<?php
//example
class Home extends JI_Controller{
	public function __construct(){
    parent::__construct();
		$this->setTheme('front');
	}
	public function index(){
		//redirect to homepage
    redir(base_url());
    die();
	}

}
