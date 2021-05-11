<?php declare(strict_types=1);
// Path to run ./vendor/bin/phpunit --bootstrap vendor/autoload.php FileName.php
// Butuh Framework PHPUnit
use PHPUnit\Framework\TestCase;

require_once SENEKEROSINE.'SENE_MySQLi_Engine.php';
require_once SENEKEROSINE.'SENE_Model.php';

class SENE_Model_Mock extends SENE_Model {
  public $db;
  public $config;
  public $__mysqli;
  public function __construct(){
    parent::__construct();
  }
  public function index(){

  }
}

/**
 * @covers SENE_Model
 */
final class SENE_Model_Test extends TestCase
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
   * @uses SENE_Model_Test
   * @uses SENE_Model_Mock
   * @covers SENE_Model
   * @covers SENE_MySQLi_Engine
   */
  public function testDBConnection()
  {
    $tc = new SENE_Model_Mock();
    $this->assertEquals(0,$tc->db->__mysqli->connect_errno);
  }

  /**
   * @uses SENE_Model_Test
   * @uses SENE_Model_Mock
   * @covers SENE_Model
   * @covers SENE_MySQLi_Engine
   */
  public function testDBError()
  {
    $tc = new SENE_Model_Mock();
    $this->assertEquals(0,$tc->db->__mysqli->errno);
  }
}
