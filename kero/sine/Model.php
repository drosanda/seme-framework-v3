<?php
namespace Kero\Sine;

abstract class Model
{
    protected $db;
    protected $enckey;
    public $field = array();

    public function __construct()
    {
        $db=$GLOBALS['db'];
        $this->loadEngine($db);
    }
    private function loadEngine($e)
    {
        if ($e=="mysql") {
            require_once(SENEKEROSINE."/MySQLi.php");
            $this->db = new \Kero\Sine\MySQLi();
            $this->enckey = $this->db->enckey;
        } elseif ($e=="pdo") {
            require_once(SENEKEROSINE."/MySQLi.php");
            $this->db = new \Kero\Sine\MySQLi();
            $this->enckey = $this->db->enckey;
        } else {
            require_once(SENEKEROSINE."/MySQLi.php");
            $this->db = new \Kero\Sine\MySQLi();
        }
    }
    public function exec($sql)
    {
        // $this->field = $this->engine->getField();
        return $this->db->exec($sql);
    }

    public function multiExec($sql)
    {
        // $this->field = $this->engine->getField();
        $res = $this->db->multiExec($sql);
    }

    public function select($sql, $cache_engine=0, $flushcache=0, $tipe="object")
    {
        //die($tipe);
        return $this->db->select($sql, $cache_engine, $flushcache, $tipe);
    }
    public function lastId()
    {
        return $this->db->lastId();
    }
    public function esc($str)
    {
        return $this->db->esc($str);
    }
    public function prettyName($name)
    {
        $name=strtolower(trim($name));
        $names=explode("_", $name);
        $name='';
        foreach ($names as $n) {
            $name=$name.''.ucfirst($n).' ';
        }
        return $name;
    }

    public function filter(&$str)
    {
        $str=filter_var($str, FILTER_SANITIZE_SPECIAL_CHARS);
    }
    public function getLastQuery()
    {
        return $this->db->getLastQuery();
    }
    public function setDebug($is_debug)
    {
        return $this->db->setDebug($is_debug);
    }
}
