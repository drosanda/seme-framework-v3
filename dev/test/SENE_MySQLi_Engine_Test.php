<?php declare(strict_types=1);
// Path to run ./vendor/bin/phpunit --bootstrap vendor/autoload.php FileName.php
// Butuh Framework PHPUnit
use PHPUnit\Framework\TestCase;

require_once SENEKEROSINE.'SENE_MySQLi_Engine.php';
require_once SENEKEROSINE.'SENE_Model.php';

class SENE_MySQLi_Engine_Mock extends SENE_MySQLi_Engine {
  public $db;
  public $config;
  public $__mysqli;
  public function __construct(){
    parent::__construct();
  }
}

/**
 * @covers SENE_Model
 */
final class SENE_MySQLi_Engine_Test extends TestCase
{
  public function __construct(){
    parent::__construct();
  }
  /**
  * Call protected/private method of a class.
  *
  * @param object &$object    Instantiated object that we will run method on.
  * @param string $methodName Method name to call
  * @param array  $parameters Array of parameters to pass into method.
  *
  * @return mixed Method return.
  */
  public function invokeMethod(&$object, $methodName, array $parameters = array())
  {
    $reflection = new \ReflectionClass(get_class($object));
    $method = $reflection->getMethod($methodName);
    $method->setAccessible(true);
    return $method->invokeArgs($object, $parameters);
  }

  /**
   * @uses SENE_MySQLi_Engine_Mock
   * @covers SENE_MySQLi_Engine
   */
  public function testFlushQuery()
  {
    $tc = new SENE_MySQLi_Engine_Mock();
    $this->invokeMethod($tc, 'flushQuery', array());
    $this->assertEquals('',$tc->in_select);
    $this->assertEquals('',$tc->in_where);
    $this->assertEquals('',$tc->in_order);
    $this->assertEquals('',$tc->in_group);
    $this->assertEquals(0,$tc->pagesize);
    $this->assertEquals(0,$tc->page);
    $this->assertEquals(0,$tc->is_limit);
    $this->assertEquals(0,$tc->limit_a);
    $this->assertEquals(0,$tc->limit_b);
    $this->assertEquals(array(),$tc->as_from);
  }

  /**
   * @uses SENE_MySQLi_Engine_Mock
   * @covers SENE_MySQLi_Engine
   */
  public function testFlushQueryAfter()
  {
    $tc = new SENE_MySQLi_Engine_Mock();
    $this->invokeMethod($tc, 'select', array('*'));
    $this->invokeMethod($tc, 'from', array('tabel'));
    $this->invokeMethod($tc, 'where', array('name','ashley'));
    $this->invokeMethod($tc, 'flushQuery', array());
    $this->assertEquals('',$tc->in_select);
    $this->assertEquals('',$tc->in_where);
    $this->assertEquals('',$tc->in_order);
    $this->assertEquals('',$tc->in_group);
    $this->assertEquals(0,$tc->pagesize);
    $this->assertEquals(0,$tc->page);
    $this->assertEquals(0,$tc->is_limit);
    $this->assertEquals(0,$tc->limit_a);
    $this->assertEquals(0,$tc->limit_b);
    $this->assertEquals(array(),$tc->as_from);
  }

  /**
   * @uses SENE_MySQLi_Engine_Mock
   * @covers SENE_MySQLi_Engine
   */
  public function testWhereIsNull()
  {
    $tc = new SENE_MySQLi_Engine_Mock();
    $this->invokeMethod($tc, 'flushQuery', array());
    $this->invokeMethod($tc, 'select', array('*'));
    $this->invokeMethod($tc, 'from', array('tabel'));
    $this->invokeMethod($tc, 'where', array('name','IS NULL'));
    $this->assertEquals('`name`  IS NULL  AND ',$tc->in_where);

    $this->invokeMethod($tc, 'flushQuery', array());
    $this->invokeMethod($tc, 'select', array('*'));
    $this->invokeMethod($tc, 'from', array('tabel'));
    $this->invokeMethod($tc, 'where', array('name','Is nUlL'));
    $this->assertEquals('`name`  IS NULL  AND ',$tc->in_where);

    $this->invokeMethod($tc, 'flushQuery', array());
    $this->invokeMethod($tc, 'select', array('*'));
    $this->invokeMethod($tc, 'from', array('tabel'));
    $this->invokeMethod($tc, 'where', array('name','is null'));
    $this->assertEquals('`name`  IS NULL  AND ',$tc->in_where);
  }

  /**
   * @uses SENE_MySQLi_Engine_Mock
   * @covers SENE_MySQLi_Engine
   */
  public function testWhereIsNotNull()
  {
    $tc = new SENE_MySQLi_Engine_Mock();
    $this->invokeMethod($tc, 'flushQuery', array());
    $this->invokeMethod($tc, 'select', array('*'));
    $this->invokeMethod($tc, 'from', array('tabel'));
    $this->invokeMethod($tc, 'where', array('name','IS NOT NULL'));
    $this->assertEquals('`name`  IS NOT NULL  AND ',$tc->in_where);

    $this->invokeMethod($tc, 'flushQuery', array());
    $this->invokeMethod($tc, 'select', array('*'));
    $this->invokeMethod($tc, 'from', array('tabel'));
    $this->invokeMethod($tc, 'where', array('name','Is not nUlL'));
    $this->assertEquals('`name`  IS NOT NULL  AND ',$tc->in_where);

    $this->invokeMethod($tc, 'flushQuery', array());
    $this->invokeMethod($tc, 'select', array('*'));
    $this->invokeMethod($tc, 'from', array('tabel'));
    $this->invokeMethod($tc, 'where', array('name','is not null'));
    $this->assertEquals('`name`  IS NOT NULL  AND ',$tc->in_where);
  }

  /**
   * @uses SENE_MySQLi_Engine_Mock
   * @covers SENE_MySQLi_Engine
   */
  public function testWhereAsIsNull()
  {
    $tc = new SENE_MySQLi_Engine_Mock();
    $this->invokeMethod($tc, 'flushQuery', array());
    $this->invokeMethod($tc, 'select', array('*'));
    $this->invokeMethod($tc, 'from', array('tabel'));
    $this->invokeMethod($tc, 'where_as', array('name','IS NULL'));
    $this->assertEquals('name  IS NULL  AND ',$tc->in_where);

    $this->invokeMethod($tc, 'flushQuery', array());
    $this->invokeMethod($tc, 'select', array('*'));
    $this->invokeMethod($tc, 'from', array('tabel'));
    $this->invokeMethod($tc, 'where_as', array('name','Is nUlL'));
    $this->assertEquals('name  IS NULL  AND ',$tc->in_where);

    $this->invokeMethod($tc, 'flushQuery', array());
    $this->invokeMethod($tc, 'select', array('*'));
    $this->invokeMethod($tc, 'from', array('tabel'));
    $this->invokeMethod($tc, 'where_as', array('name','is null'));
    $this->assertEquals('name  IS NULL  AND ',$tc->in_where);
  }

  /**
   * @uses SENE_MySQLi_Engine_Mock
   * @covers SENE_MySQLi_Engine
   */
  public function testWhereAsIsNotNull()
  {
    $tc = new SENE_MySQLi_Engine_Mock();
    $this->invokeMethod($tc, 'flushQuery', array());
    $this->invokeMethod($tc, 'select', array('*'));
    $this->invokeMethod($tc, 'from', array('tabel'));
    $this->invokeMethod($tc, 'where_as', array('name','IS NOT NULL'));
    $this->assertEquals('name  IS NOT NULL  AND ',$tc->in_where);

    $this->invokeMethod($tc, 'flushQuery', array());
    $this->invokeMethod($tc, 'select', array('*'));
    $this->invokeMethod($tc, 'from', array('tabel'));
    $this->invokeMethod($tc, 'where_as', array('name','Is not nUlL'));
    $this->assertEquals('name  IS NOT NULL  AND ',$tc->in_where);

    $this->invokeMethod($tc, 'flushQuery', array());
    $this->invokeMethod($tc, 'select', array('*'));
    $this->invokeMethod($tc, 'from', array('tabel'));
    $this->invokeMethod($tc, 'where_as', array('name','is not null'));
    $this->assertEquals('name  IS NOT NULL  AND ',$tc->in_where);
  }
}
