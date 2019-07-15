<?php
class Home extends JI_Controller{

	public function __construct(){
    parent::__construct();
		$this->setTheme('front');
	}
	public function index(){
		$data = $this->__init(); //method from app/core/ji_controller

		//for menu top bar
		$data['brand'] = "SEME Framework";

		//example data passing
		$data['example'] = 'Lorem lipsum dolor sit amet. This value can be changed in app/controller/home.php';

		//for set pills active
		$data['page_current'] = 'col-1';


		//this config can be found on app/view/front/page/html/head.php
		$this->setTitle('Welcome to SEME Framework');
		$this->setDescription('SEME Framework PHP MVC Framework with small footprint for your business.');
		$this->setKeyword('SEME Framework');

		//sidebar left
		//this view can be found on app/view/front/page/html/sidebar_left.php
		$this->putThemeLeftContent("page/html/sidebar_left",$data); //pass data to view

		//sidebar right
		//this view can be found on app/view/front/page/html/sidebar_left.php
		$this->putThemeRightContent("page/html/sidebar_right",$data); //pass data to view

		//main content
		//this view can be found on app/view/front/home/home.php
		$this->putThemeContent("home/home",$data); //pass data to view
		//this view for INPAGE JS Script can be found on app/view/front/page/home/home_bottom.php
		$this->putJsContent("home/home_bottom",$data); //pass data to view

		$this->loadLayout("col-1",$data);
		$this->render();
	}

}
