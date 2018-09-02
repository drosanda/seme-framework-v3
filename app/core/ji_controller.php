<?php
	Class JI_Controller extends SENE_Controller {
		var $site_name = 'Dr. Vice';
		var $site_title = 'Dr. Vice | Your Vice Clothes';
		var $site_description = 'Dr. Vice | Your Vice Clothes';
		var $site_email = 'hi@drvice-clothing.com';
		var $site_replyto = 'nyingspot@gmail.com';
		var $site_phone = '085861624300';
		var $site_suffix = ' | Dr. Vice';
		var $site_keyword = 'dr. vice Clothing';
		var $page_current = 'beranda';
		var $menu_current = 'beranda';
		var $site_author = 'Dr. Vice';
		var $site_company = 'CV. Cipta Esensi Merenah';
		var $site_address = 'Jl Soreang-Padasuka No 3 Citiru, Kabupaten Bandung, Jawa Barat, Indonesia 40911';
		var $user_login = 0;
		var $admin_login = 0;
		var $status = 404;
		var $message = 'Error, not found!';
		var $breadcrumbs;
		var $skins;

		var $fcm_server_token = '';
		var $cdn_url = '';
		var $is_strict_module = 0;
		var $current_parent = '';
		var $current_page = '';

		public function cdn_url($url=""){
			if(strlen($this->cdn_url)>6){
				return $this->cdn_url.$url;
			}else{
				return base_url($url);
			}
		}
    protected function __init(){
      $data = array();
			$this->setTitle($this->site_title);
			$this->setDescription($this->description);
			$this->setRobots('INDEX,FOLLOW');
			$this->setAuthor($this->site_author);
			$this->setKeyword($this->site_keyword);
			$this->setIcon(base_url('favicon.png'));
			$this->setShortcutIcon(base_url('favicon.png'));

			return $data;
    }

		//karena ini wajib jadi method ini harus ada... :P
		public function index(){}
}
