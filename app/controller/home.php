<?php
class Home extends JI_Controller{

	public function __construct(){
    parent::__construct();
		$this->setTheme('front');
	}
	public function index(){
		echo 'Welcome to Seme Framework';
	}
}
