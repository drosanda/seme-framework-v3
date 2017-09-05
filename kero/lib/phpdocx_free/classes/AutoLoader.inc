<?php

/**
 * Autoloader
 *
 * @category   Phpdocx
 * @package    loader
 * @copyright  Copyright (c) 2009-2011 Narcea Producciones Multimedia S.L.
 *             (http://www.2mdc.com)
 * @license    http://www.phpdocx.com/wp-content/themes/lightword/pro_license.php
 * @version    2011.08.17
 * @link       http://www.phpdocx.com
 * @since      Class available since Release 2.0
 */
class AutoLoader
{

    /**
     * Main tags of relationships XML
     *
     * @access public
     * @static
     */
    public static function load()
    {
        spl_autoload_register(array('AutoLoader', 'autoloadGenericClasses'));
        spl_autoload_register(array('AutoLoader', 'autoloadPhpdocx'));
        spl_autoload_register(array('AutoLoader', 'autoloadLog4php'));
        spl_autoload_register(array('AutoLoader', 'autoloadZetaComponents'));
        spl_autoload_register(array('AutoLoader', 'autoloadTcpdf'));
        spl_autoload_register(array('AutoLoader', 'autoloadPdf'));
        spl_autoload_register(array('AutoLoader', 'autoloadDompdf'));
        spl_autoload_register(array('AutoLoader', 'autoloadMht'));
    }

    /**
     * Autoload Tcpdf
     *
     * @access private
     * @param string $className Class to load
     */
    private static function autoloadTcpdf($className)
    {
        $pathTcpdf = dirname(__FILE__) . '/../pdf/class.tcpdf.php';
        if (file_exists($pathTcpdf)) {
            require_once $pathTcpdf;
        }
    }
    
    /**
     * Autoload dompdf
     *
     * @access private
     * @param string $className Class to load
     */
    private static function autoloadDompdf($className)
    {
        $pathDompdf = dirname(__FILE__) . '/../pdf/dompdf_config.inc.php';
        if (file_exists($pathDompdf)) {
            require_once $pathDompdf;
        }
    }

    /**
     * Autoload log4php
     *
     * @access private
     * @param string $className Class to load
     */
    private static function autoloadLog4php($className)
    {
        $pathLogphp = dirname(__FILE__) . '/../lib/log4php/'
            . $className . '.php';
        if (file_exists($pathLogphp)) {
            require_once $pathLogphp;
        }
    }

    /**
     * Autoload mht
     *
     * @access private
     * @param string $className Class to load
     */
    private static function autoloadMht($className)
    {
        $pathMht = dirname(__FILE__) . '/../lib/'
            . $className . '.php';
        if (file_exists($pathMht)) {
            require_once $pathMht;
        }
    }

    /**
     * Autoload phpdocx
     *
     * @access private
     * @param string $className Class to load
     */
    private static function autoloadPhpdocx($className)
    {
        $pathPhpdocx = dirname(__FILE__) . '/docx/' . $className . '.inc';
        if (file_exists($pathPhpdocx)) {
            require_once $pathPhpdocx;
        }
    }

    /**
     * Autoload Apache Zeta Components
     *
     * @access private
     * @param string $className Class to load
     */
    private static function autoloadZetaComponents($className)
    {
    	if (preg_match('/^ezcBase/', $className)) {
	    	$ezcBaseClasses = require dirname(__FILE__) . 
	    			'/../lib/zetacomponents/Base/src/base_autoload.php';
	    	if (array_key_exists($className, $ezcBaseClasses)){
		    	$classPath = $ezcBaseClasses[$className];
		    	$classPathFix = this.zetaComponentsFileName($classPath);
		        $pathZetaComp = dirname(__FILE__) . '/../lib/zetacomponents/'
		            . $classPathFix;
		    	if (file_exists($pathZetaComp)) {
		            require_once $pathZetaComp;
		        }
	    	}
    	}
    	if (preg_match('/^ezcGraph/', $className)) {
	    	$ezcGraphClasses = require dirname(__FILE__) . 
	    			'/../lib/zetacomponents/Graph/src/graph_autoload.php';
	    	if (array_key_exists($className, $ezcGraphClasses)){
		    	$classPath = $ezcGraphClasses[$className];
		    	$classPathFix = this.zetaComponentsFileName($classPath);
		        $pathZetaComp = dirname(__FILE__) . '/../lib/zetacomponents/'
		            . $classPathFix;
		    	if (file_exists($pathZetaComp)) {
		            require_once $pathZetaComp;
		        }
	    	}
    	}
    	
    }

    /**
     * 
     * Transform file path
     * @param string $file
     */
    private function zetaComponentsFileName($file) {
		list( $first, $second, $third ) = explode( '/', $file, 3 );
		// Add the "src/" after the package name.
		if ( !empty($third) )
		{
		    return $file = $first . "/src/" . $second . '/' . $third;
		} else {
		    list( $first, $second ) = explode( '/', $file, 2 );
		    return $file = $first . "/src/" . $second;
		}
    }


    /**
     * Autoload phpdocx
     *
     * @access private
     * @param string $className Class to load
     */
    private static function autoloadPdf($className)
    {
        $pathPhpdocx = dirname(__FILE__) . '/pdf/' . $className . '.inc';
        if (file_exists($pathPhpdocx)) {
            require_once $pathPhpdocx;
        }
    }


    /**
     * Autoload phpdocx
     *
     * @access private
     * @param string $className Class to load
     */
    private static function autoloadGenericClasses($className)
    {
        $pathPhpdocx = dirname(__FILE__) . '/' . $className . '.inc';
        if (file_exists($pathPhpdocx)) {
            require_once $pathPhpdocx;
        }
    }
}