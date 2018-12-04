<?php
session_start();
ini_set("error_reporting",E_ALL);
$website_view_id = 1; // default
$admin_secret_url = 'admin';

$apps_dir='app';
$assets_dir='assets';
$cache_dir='app/cache';
$ssys_dir='kero';
$kerosine_dir='kero/sine';
$library_dir='kero/lib';
$config_dir='app/config';
$model_dir='app/model';
$view_dir='app/view';
$controller_dir='app/controller';
$core_dir='app/core';


if (defined('STDIN')){
	chdir(dirname(__FILE__));
}
if (realpath($apps_dir) !== FALSE){
	$apps_dir = realpath($apps_dir).'/';
}
if (realpath($assets_dir) !== FALSE){
	$assets_dir = realpath($assets_dir).'/';
}
if (realpath($ssys_dir) !== FALSE){
	$ssys_dir = realpath($ssys_dir).'/';
}
if (realpath($kerosine_dir) !== FALSE){
	$kerosine_dir = realpath($kerosine_dir).'/';
}
if (realpath($config_dir) !== FALSE){
	$config_dir = realpath($config_dir).'/';
}
if (realpath($cache_dir) !== FALSE){
	$cache_dir = realpath($cache_dir).'/';
}
if (realpath($library_dir) !== FALSE){
	$library_dir = realpath($library_dir).'/';
}
if (realpath($model_dir) !== FALSE){
	$model_dir = realpath($model_dir).'/';
}
if (realpath($view_dir) !== FALSE){
	$view_dir = realpath($view_dir).'/';
}
if (realpath($controller_dir) !== FALSE){
	$controller_dir = realpath($controller_dir).'/';
}
if (realpath($core_dir) !== FALSE){
	$core_dir = realpath($core_dir).'/';
}
if(!is_dir($apps_dir)){
	die("missing apps dir: ".pathinfo(__FILE__, PATHINFO_BASENAME));
}
if(!is_dir($assets_dir)){
	die("missing assets dir: ".pathinfo(__FILE__, PATHINFO_BASENAME));
}
if(!is_dir($ssys_dir)){
	die("missing ssys dir: ".pathinfo(__FILE__, PATHINFO_BASENAME));
}
if(!is_dir($kerosine_dir)){
	die("missing apps dir: ".pathinfo(__FILE__, PATHINFO_BASENAME));
}
if(!is_dir($library_dir)){
	die("missing library dir: ".pathinfo(__FILE__, PATHINFO_BASENAME));
}
if(!is_dir($config_dir)){
	die("missing config dir: ".pathinfo(__FILE__, PATHINFO_BASENAME));
}
if(!is_dir($cache_dir)){
	die("missing cache dir: ".pathinfo(__FILE__, PATHINFO_BASENAME));
}
if(!is_dir($model_dir)){
	die("missing nodel dir: ".pathinfo(__FILE__, PATHINFO_BASENAME));
}if(!is_dir($view_dir)){
	die("missing view dir: ".pathinfo(__FILE__, PATHINFO_BASENAME));
	}
if(!is_dir($controller_dir)){
	die("missing controller dir: ".pathinfo(__FILE__, PATHINFO_BASENAME));
}
if(!is_dir($core_dir)){
	die("missing core dir: ".pathinfo(__FILE__, PATHINFO_BASENAME));
}

$apps_dir = rtrim($apps_dir, '/').'/';
$ssys_dir = rtrim($ssys_dir, '/').'/';
$kerosine_dir = rtrim($kerosine_dir, '/').'/';
$library_dir = rtrim($library_dir, '/').'/';
$cache_dir = rtrim($cache_dir, '/').'/';
$config_dir = rtrim($config_dir, '/').'/';
$model_dir = rtrim($model_dir, '/').'/';
$view_dir = rtrim($view_dir, '/').'/';
$controller_dir = rtrim($controller_dir, '/').'/';
$core_dir = rtrim($core_dir, '/').'/';

if(!is_dir($apps_dir)) die("Seme framework directory missing : ".pathinfo(__FILE__, PATHINFO_BASENAME));
if(!is_dir($ssys_dir)) die("Seme framework directory missing : ".pathinfo(__FILE__, PATHINFO_BASENAME));
if(!is_dir($kerosine_dir)) die("Seme framework directory missing : ".pathinfo(__FILE__, PATHINFO_BASENAME));
if(!is_dir($library_dir)) die("Seme framework directory missing : ".pathinfo(__FILE__, PATHINFO_BASENAME));
if(!is_dir($cache_dir)) die("Seme framework directory missing : ".pathinfo(__FILE__, PATHINFO_BASENAME));
if(!is_dir($config_dir)) die("Seme framework directory missing : ".pathinfo(__FILE__, PATHINFO_BASENAME));
if(!is_dir($model_dir)) die("Seme framework directory missing : ".pathinfo(__FILE__, PATHINFO_BASENAME));
if(!is_dir($view_dir)) die("Seme framework directory missing : ".pathinfo(__FILE__, PATHINFO_BASENAME));
if(!is_dir($controller_dir)) die("Seme framework directory missing : ".pathinfo(__FILE__, PATHINFO_BASENAME));
if(!is_dir($core_dir)) die("Seme framework directory missing : ".pathinfo(__FILE__, PATHINFO_BASENAME));

define('SENEROOT',str_replace("\\", "/", realpath("").'/'));
define('SENEAPP',str_replace("\\", "/",$apps_dir));
define('SENEASSETS',$assets_dir);
define('SENESYS',$ssys_dir);
define('SENEKEROSINE',$kerosine_dir);
define('SENELIB',$library_dir);
define('SENECACHE',$cache_dir);
define('SENECFG',$config_dir);
define('SENEMODEL',$model_dir);
define('SENEVIEW',$view_dir);
define('SENECONTROLLER',$controller_dir);
define('SENECORE',$core_dir);

require_once SENEKEROSINE."/SENE_Engine.php";
$se = new SENE_Engine($db);
$se->SENE_Engine();
