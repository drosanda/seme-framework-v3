<?php declare(strict_types=1);
use PHPUnit\Framework\TestCase;

require_once SENECORE.'ji_controller.php';
require_once SENECONTROLLER.'home.php';

final class HomeTest extends Home
{
  public function __construct(){
    parent::__construct();
  }
  /**
  * @covers Home
  * @uses SENE_Controller
  */
  public function testIndex(): void
  {
    $expected = 'Thank you for using Seme Framework';
    $this->expectOutputString($expected);
    $calc = new Home();
    $calc->index();
  }
}
