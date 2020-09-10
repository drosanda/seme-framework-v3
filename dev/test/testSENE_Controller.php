<?php
// Path to run ./vendor/bin/phpunit --bootstrap vendor/autoload.php FileName.php
// Butuh Framework PHPUnit
use PHPUnit\Framework\TestCase;

// Class yang mau di TEST.
//require_once "../../kero/sine/SENE_Controller.php";

// Class untuk run Testing.
class mockSENE_Controller extends SENE_Controller {
  public function __construct(){
    parent::__construct();
  }
  public function index(){

  }
}

class testSENE_Controller extends TestCase
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
  public function testTitle()
  {
    $tc = new mockSENE_Controller();
    $ts = "Welcome to Seme Framework"; // 4 Kata ..
    $this->invokeMethod($tc, 'setTitle', array($ts));
    $this->assertEquals($ts, $this->invokeMethod($tc, 'getTitle', array()));
    $this->assertNotEquals(strtolower($ts), $this->invokeMethod($tc, 'getTitle', array()));
  }
  public function testDescription()
  {
    $tc = new mockSENE_Controller();
    $ts = "Seme Framework is lightweight PHP MVC Framework for creating small and medium web application with fast delivery"; // 4 Kata ..
    $this->invokeMethod($tc, 'setDescription', array($ts));
    $this->assertEquals($ts, $this->invokeMethod($tc, 'getDescription', array()));
    $this->assertNotEquals(strtolower($ts), $this->invokeMethod($tc, 'getDescription', array()));
  }
  public function testLang()
  {
    $tc = new mockSENE_Controller();
    $ts = 'id-ID';
    $this->invokeMethod($tc, 'setLang', array($ts));
    $this->assertEquals($ts, $this->invokeMethod($tc, 'getLang', array()));
    $this->assertNotEquals(strtolower($ts), $this->invokeMethod($tc, 'getLang', array()));
  }
  public function testRobots()
  {
    $tc = new mockSENE_Controller();
    $ts = 'INDEX,FOLLOW';
    $this->invokeMethod($tc, 'setRobots', array($ts));
    $this->assertEquals($ts, $this->invokeMethod($tc, 'getRobots', array()));
    $this->assertNotEquals(strtolower($ts), $this->invokeMethod($tc, 'getRobots', array()));
    $ts = 'NOINDEX,NOFOLLOW';
    $this->invokeMethod($tc, 'setRobots', array($ts));
    $this->assertEquals($ts, $this->invokeMethod($tc, 'getRobots', array()));
    $this->assertNotEquals(strtolower($ts), $this->invokeMethod($tc, 'getRobots', array()));
    $ts = 'anything';
    $this->invokeMethod($tc, 'setRobots', array($ts));
    $this->assertEquals('NOINDEX,NOFOLLOW', $this->invokeMethod($tc, 'getRobots', array()));
    $this->assertNotEquals(strtolower('NOINDEX,NOFOLLOW'), $this->invokeMethod($tc, 'getRobots', array()));
  }
  public function testAuthor()
  {
    $tc = new mockSENE_Controller();
    $ts = 'Seme Framework';
    $this->invokeMethod($tc, 'setAuthor', array($ts));
    $this->assertEquals($ts, $this->invokeMethod($tc, 'getAuthor', array()));
  }
  public function testIcon()
  {
    $tc = new mockSENE_Controller();
    $ts = 'favicon.ico';
    $this->invokeMethod($tc, 'setIcon', array($ts));
    $this->assertEquals($ts, $this->invokeMethod($tc, 'getIcon', array()));
  }
  public function testShortcutIcon()
  {
    $tc = new mockSENE_Controller();
    $ts = 'favicon.ico';
    $this->invokeMethod($tc, 'setShortcutIcon', array($ts));
    $this->assertEquals($ts, $this->invokeMethod($tc, 'getShortcutIcon', array()));
  }
}
