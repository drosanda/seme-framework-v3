<?php

/**
 * Check for a valid license
 *
 * @category   Phpdocx
 * @package    license
 * @copyright  Copyright (c) 2009-2011 Narcea Producciones Multimedia S.L.
 *             (http://www.2mdc.com)
 * @license    http://www.phpdocx.com/wp-content/themes/lightword/pro_license.php
 * @version    1.0
 * @link       http://www.phpdocx.com
 * @since      File available since Release 1.0
 */

/**
 * Check for a valid license
 *
 * @category   Phpdocx
 * @package    license
 * @copyright  Copyright (c) 2009-2011 Narcea Producciones Multimedia S.L.
 *             (http://www.2mdc.com)
 * @license    http://www.phpdocx.com/wp-content/themes/lightword/pro_license.php
 * @version    1.0
 * @link       http://www.phpdocx.com
 * @since      Class available since Release 1.0
 */
class GenerateDocx
{

    /**
     * Check for a valid license
     *
     * @access public
     * @return boolean
     */
    public static function beginDocx()
    {
        $xzerod = '';
        $xzerob = '';
        $xzeroc = '';

        if (!isset($_SERVER['SERVER_NAME'])) {
            return;
        } else {
            $xzerod = trim(file_get_contents(dirname(__FILE__) . '/code'));
            $xzerob = trim(gethostbyname($_SERVER['SERVER_NAME']));
            $xzeroc = trim($_SERVER['SERVER_NAME']);
        }
        if (
            preg_match('/^192.168./', $xzeroc) ||
            preg_match('/^172.16./', $xzeroc) ||
            preg_match('/^192.168./', $xzerob) ||
            preg_match('/^172.16./', $xzerob) ||
            preg_match('/^10./', $xzerob) ||
            preg_match('/localhost/', $xzeroc)
        ) {
            return;
        } elseif ($xzerod == md5($xzeroc . '_docx')) {
            return;
        } elseif (!preg_match('/^www./', $xzeroc)) {
            $xzeroc = 'www.' . $xzeroc;
        } elseif ($xzerod == md5($xzeroc . '_docx')) {
            return;
        } else {
            throw new Exception('There is not a valid license');
        }
    }

}
