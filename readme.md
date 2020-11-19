# Seme Framework v3.1.4
[![Build Status](https://travis-ci.org/drosanda/seme-framework-v3.svg?branch=3.1.0)](https://travis-ci.org/drosanda/seme-framework-v3)  [![Coverage Status](https://coveralls.io/repos/github/drosanda/seme-framework/badge.svg?branch=3.1.0)](https://coveralls.io/github/drosanda/seme-framework?branch=3.1.0) [![Website seme.framwork.web.id](https://img.shields.io/website-up-down-green-red/http/seme.framework.web.id)](https://seme.framework.web.id/)

Seme Framework PHP MVC Framework for creating small and medium app that needed for fast delivery. At first version of Seme Framework used for building API (Middle Ware) for another Application such as android, iOS, etc. And now as increasing of requirement, Seme Framework has expand the limit for creating Small and Medium App.

## Documentation

Read the official [https://seme.framework.web.id](https://seme.framework.web.id/). Now only available in English.

## Key Feature
This framework suitable for Programmer that only know about Manual way of code. Not like this time, everything build up automatically through console. Seme Framework has taken different way of code, If you want build small app, why we need lots of library. Here is the key feature of Seme Framework:

 - Small but not Tiny. Seme Framework growth on SME Industries with many requirement but can suppress the hosting price.
 - Not Too serious. You can played with Seme Framework at your own logic. Its free and almost has no restriction to developing your solution.
 - Admin Friendly. Seme Framework has re-routing feature for admin page, without refactoring the MVC.
 - Theme Engine. Seme Framework has feature who can PUSH the content inside the layout view. Also support theming engine, if you want change the Style, you just clone the original one and modified safely.

## Version 3.1.4
This is latest version of 3.1 branch. Here is the new feature:
- add SENE_MySQLi_Engine::update_as method
- Fix SENEROOT base directory defining method for docker support

## Version 3.1.3
This is latest version of 3.1 branch. Here is the new feature:
- add join_as method

## Version 3.0
On version 3.0 we have plan to do more with aliases in models and then we have more homework to rebalancing query builder (query helper) method.
Adding library for using mailgun

## Basic Concept
Seme Framework comes with basic routing and database that supported MySQL or MariaDB.
The database class can executed through the model.

### Routing
Default routing configuration location
app/config/controller.php.
As like many other MVC Framework, Seme Framework using automatic routes that depends on class name or directory name.

http://example.com/classname/method/param1/param2/param..n

*OR*

http://example.com/directory_name/classname/method/param1/param2/param..n

#### Example
Using class name
http://example.com/dashboard -> app/controller/dashboard.php with classname login.

Using directory
http://example.com/admin/login -> app/controller/admin/login.php with class name Login

If there same class name with directory name, the directory name will be the first executed.

## Installation
Clone or download and then edit config file located at *app/config/*

### config.php
config.php contain about base url
database.php contain about connection to MySQL or MariaDB.
session.php conatin about key, you should change this.

## Code Example
By default Seme Framework automatically get *home* controller or *notfound* controller for 404 error page.

### The Controller
The location of controllers script is on *app/controller*. The default controller is home.php.
Creating the controller, make sure your class name is match with *classname*.php case insensitive.
```php
class Home extends SENE_Controller{

	public function __construct(){
    parent::__construct();
	}
	private function __init(){

	}
	public function index(){
		echo 'Thankyou for using seme framework';
	}
}
```

### The Models
The location of models in app/models. Models currently doenst support sub directory. Make sure your model name same name with class name (case insensitive).
Here is the example
```php
class Table_Name_Model extends SENE_Model{
	public function __construct(){
    parent::__construct();
  }
	public function executeSQL(){
		$sql = 'SELECT * FROM table_name WHERE 1';
		return $this->db->query($sql); //will return array of object
	}
	public function queryBuilder(){
		$this->db->select('*')->from('table_name')->where('name_of_col','value_desired')->get("object",0); //array of (object) or (array) of array, second debug true or false
	}
	public funciton insertToTbl($dataArray=array()){
		//make sure your data array key match with column name in table
		$this->db->insert("table_name",$dataArray); //return true if sucess or false if fail
		return $this->db->last_id; // get last id or false
	}
	public function updateTbl($dataUpdate=array()){
		//make sure your data array key match with column name in table
		return $this->db->update("table_name",$dataUpdate); //return true if sucess or false if fail
	}
	public function ddlQuery($id){
		$sql = 'DELETE FROM table_name WHERE id = '.$this->db->esc($id); //insert update delete with escaped value
		return $this->db->exec($sql); //return true or false
	}
	public function delete($id){
		$this->db->where("id",$id);
		return $this->db->delete($this->tbl);//return true or false
	}
}
```

### The Views
The view contain about your view in HTML. Put your view file in php extension (lowercase).

```php
<html>
	<head>
		<title>Title</title>
	</head>
	<body>
		<h1>Halloo</h1>
		<p>Thankyou for using seme framework</p>
	</body>
</html>
```
save that file on app/view/front/home.php. For loading this view on controller just add $this->view('NAME_HOME');
```php
class Home extends SENE_Controller{
	public function __construct(){
    parent::__construct();
	}
	private function __init(){
	}
	public function index(){
		$this->view('front/home');
		$this->render(); // version 3
	}
}
```

#### Creating Template or Layout
Seme Framework allowing you to create template or layout that consist of separated file.
```php

```

## More Guides
Look for more guides https://seme.framework.web.id/ (English) and https://www.nyingspot.com/author/seme_framework/ (Bahasa)

## License
Seme Framework licensed under MIT License 2.0
