<?php
class Home extends JI_Controller{

	public function __construct(){
    parent::__construct();
		$this->setTheme('front');
	}
	public function index(){
		$data = $this->__init(); //method from app/core/ji_controller

		//this config can be found on app/view/front/page/html/head.php
		$this->setTitle($this->site_suffix);
		$this->setDescription($this->site_description);
		$this->setKeyword('dr alfred');

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
