<?php

/**
 * Generate a DOCX file
 *
 * @category   Phpdocx
 * @package    create
 * @copyright  Copyright (c) 2009-2011 Narcea Producciones Multimedia S.L.
 *             (http://www.2mdc.com)
 * @license    http://www.phpdocx.com/wp-content/themes/lightword/pro_license.php
 * @version    2011.08.17
 * @link       http://www.phpdocx.com
 * @since      File available since Release 1.0
 */

error_reporting(E_ALL & ~E_NOTICE);

require_once dirname(__FILE__) . '/AutoLoader.inc';
AutoLoader::load();

/**
 * Main class. Methods and vars to generate a DOCX file
 *
 * @category   Phpdocx
 * @package    create
 * @copyright  Copyright (c) 2009-2011 Narcea ProduCiones Multimedia S.L.
 *             (http://www.2mdc.com)
 * @license    http://www.phpdocx.com/wp-content/themes/lightword/pro_license.php
 * @version    2011.08.17
 * @link       http://www.phpdocx.com
 * @since      Class available since Release 1.0
 */
class CreateDocx extends CreateDocument
{
    const NAMESPACEWORD = 'w';
    const SCHEMA_IMAGEDOCUMENT =
    'http://schemas.openxmlformats.org/officeDocument/2006/relationships/image';
    const SCHEMA_OFFICEDOCUMENT =
    'http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument';

    /**
     *
     * @access public
     * @var array
     */
    public $fileGraphicTemplate;
    /**
     *
     * @access public
     * @var string
     */
    public $graphicTemplate;
    /**
     *
     * @access public
     * @static
     * @var int
     */
    public static $intIdWord;
    /**
     *
     * @access public
     * @static
     * @var Logger
     */
    public static $log;
    /**
     *
     * @access private
     * @var string
     */
    private $_contentTypeC;
    /**
     *
     * @access private
     * @var string
     */
    private $_defaultFont;
    /**
     *
     * @access private
     * @var Debug
     */
    private $_debug;
    /**
     *
     * @access private
     * @var string
     */
    private $_docPropsAppC;
    /**
     *
     * @access private
     * @var string
     */
    private $_docPropsAppT;
    /**
     *
     * @access private
     * @var string
     */
    private $_docPropsCoreC;
    /**
     *
     * @access private
     * @var string
     */
    private $_docPropsCoreT;
    /**
     *
     * @access private
     * @var string
     */
    private $_docPropsCustomC;
    /**
     *
     * @access private
     * @var string
     */
    private $_docPropsCustomT;
    /**
     *
     * @access private
     * @var string
     */
    private static $_encodeUTF;
    /**
     *
     * @access private
     * @var string
     */
    private $_extension;
    /**
     *
     * @access private
     * @var int
     */
    private $_idImgHeader;
    /**
     *
     * @access private
     * @var int
     */
    private $_idRels;
    /**
     *
     * @access private
     * @var array
     */
    private $_idWords;
    /**
     *
     * @access private
     * @var string
     */
    private $_language;
    /**
     *
     * @access private
     * @var boolean
     */
    private $_macro;
    /**
     *
     * @access private
     * @var int
     */
    private $_markAsFinal;
    /**
     *
     * @access private
     * @var string
     */
    private $_relsRelsC;
    /**
     *
     * @access private
     * @var string
     */
    private $_relsRelsT;
    /**
     * Directory path used for temporary files
     *
     * @access private
     * @var string
     */
    private $_tempDir;
    /**
     * Path of temp file to use as DOCX file
     *
     * @access private
     * @var string
     */
    private $_tempFile;
    /**
     * Paths of temps files to use as DOCX file
     *
     * @access private
     * @var array
     */
    private $_tempFileXLSX;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordDocumentC;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordDocumentT;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordDocumentStyles;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordEndnotesC;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordEndnotesT;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordFontTableC;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordFontTableT;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordFooterC;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordFooterT;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordFootnotesC;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordFootnotesT;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordHeaderC;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordHeaderT;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordNumberingC;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordNumberingT;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordRelsDocumentRelsC;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordRelsDocumentRelsT;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordRelsFooterRelsC;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordRelsFooterRelsT;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordRelsHeaderRelsC;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordRelsHeaderRelsT;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordSettingsC;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordSettingsT;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordStylesC;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordStylesT;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordThemeThemeT;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordThemeThemeC;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordWebSettingsC;
    /**
     *
     * @access private
     * @var string
     */
    private $_wordWebSettingsT;
    /**
     *
     * @access private
     * @var ZipArchive
     */
    private $_zipDocx;

    /**
     * Construct
     *
     * @access public
     * @param string $extension File extension. Optional, docx as default
     */
    public function __construct($extension = 'docx')
    {
        $this->_idRels = array();
        $this->_idWords = array();
        $this->_debug = Debug::getInstance();
        Logger::configure(dirname(__FILE__) . '/conf/log4php.properties');
        self::$log = Logger::getLogger('phpdocx_error');
        $this->_idImgHeader = 1;
        $this->_idRels = 1;
        self::$intIdWord = 0;
        self::$_encodeUTF = 0;
        $this->_language = 'en-US';
        $this->_markAsFinal = 0;
        $this->graphicTemplate = array();
        $this->fileGraphicTemplate = array();
        $this->_zipDocx = new ZipArchive();
        $this->_tempDir = $this->getTempDir();
        $this->_tempFile = tempnam($this->_tempDir, 'document');
        $this->_zipDocx->open($this->_tempFile, ZipArchive::OVERWRITE);
        $this->_extension = $extension;
        self::$log->info(
            'Create a temp file to use as initial ZIP file. ' .
            'DOCX is a ZIP file.'
        );
        $this->_relsRelsC = '';
        $this->_relsRelsT = '';
        $this->_contentTypeC = '';
        $this->_defaultFont = '';
        $this->_docPropsAppC = '';
        $this->_docPropsAppT = '';
        $this->_docPropsCoreC = '';
        $this->_docPropsCoreT = '';
        $this->_docPropsCustomC = '';
        $this->_docPropsCustomT = '';
        $this->_macro = 0;
        $this->_tempFileXLSX = array();
        $this->_wordDocumentT = '';
        $this->_wordDocumentC = '';
        $this->_wordDocumentStyles = '';
        $this->_wordEndnotesC = '';
        $this->_wordEndnotesT = '';
        $this->_wordFontTableT = '';
        $this->_wordFontTableC = '';
        $this->_wordFooterC = '';
        $this->_wordFooterT = '';
        $this->_wordFootnotesC = '';
        $this->_wordFootnotesT = '';
        $this->_wordHeaderC = '';
        $this->_wordHeaderT = '';
        $this->_wordNumberingC;
        $this->_wordNumberingT;
        $this->_wordRelsDocumentRelsC = '';
        $this->_wordRelsDocumentRelsT = '';
        $this->_wordRelsHeaderRelsC = '';
        $this->_wordRelsHeaderRelsT = '';
        $this->_wordRelsFooterRelsC = '';
        $this->_wordRelsFooterRelsT = '';
        $this->_wordSettingsT = '';
        $this->_wordSettingsC = '';
        $this->_wordStylesT = '';
        $this->_wordStylesC = '';
        $this->_wordThemeThemeT = '';
        $this->_wordThemeThemeC = '';
        $this->generateContentType();
        try {
            GenerateDocx::beginDocx();
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            exit();
        }
    }

    /**
     * Destruct
     *
     * @access public
     */
    public function __destruct()
    {

    }

    /**
     * Magic method, returns current word XML
     *
     * @access public
     * @return string Return current word
     */
    public function __toString()
    {
        $this->generateTemplateWordDocument();
        self::$log->debug('Get document template content.');
        return $this->_wordDocumentT;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setTemporaryDirectory($tempDir)
    {
        $this->_tempDir = $tempDir;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getTemporaryDirectory()
    {
        return $this->_tempDir;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlContentTypes($xmlContentTypes)
    {
        $this->_contentTypeC = $xmlContentTypes;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlContentTypes()
    {
        return $this->_contentTypeC;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlRelsRels($xmlRelsRels)
    {
        $this->_relsRelsC = $xmlRelsRels;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlRelsRels()
    {
        return $this->_relsRelsC;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlDocPropsApp($xmlDocPropsApp)
    {
        $this->_docPropsAppC = $xmlDocPropsApp;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlDocPropsApp()
    {
        return $this->_docPropsAppC;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlDocPropsCore($xmlDocPropsCore)
    {
        $this->_docPropsCoreC = $xmlDocPropsCore;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlDocPropsCore()
    {
        return $this->_docPropsCoreC;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlDocPropsCustom($xmlDocPropsCustom)
    {
        $this->_docPropsCustomC = $xmlDocPropsCustom;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlDocPropsCustom()
    {
        return $this->_docPropsCustomC;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlWordDocument($xmlWordDocument)
    {
        $this->_wordDocumentC = $xmlWordDocument;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlWordDocumentContent()
    {
        return $this->_wordDocumentC;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlWordDocumentStyles($xmlWordDocumentStyles)
    {
        $this->_wordDocumentStyles = $xmlWordDocumentStyles;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlWordDocumentStyles()
    {
        return $this->_wordDocumentStyles;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlWordEndnotes($xmlWordEndnotes)
    {
        $this->_wordEndnotesC = $xmlWordEndnotes;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlWordEndnotes()
    {
        return $this->_wordEndnotesC;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlWordFontTable($xmlWordFontTable)
    {
        $this->_wordFontTableC = $xmlWordFontTable;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlWordFontTable()
    {
        return $this->_wordFontTableC;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlWordFooter1($xmlWordFooter)
    {
        $this->_wordFooterC = $xmlWordFooter;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlWordFooter1()
    {
        return $this->_wordFooterC;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlWordHeader1($xmlWordHeader)
    {
        $this->_wordHeaderC = $xmlWordHeader;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlWordHeader1()
    {
        return $this->_wordHeaderC;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlWordRelsDocumentRels($xmlWordRelsDocumentRels)
    {
        $this->_wordRelsDocumentRelsC = $xmlWordRelsDocumentRels;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlWordRelsDocumentRels()
    {
        return $this->_wordRelsDocumentRelsC;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlWordSettings($xmlWordSettings)
    {
        $this->_wordSettingsC = $xmlWordSettings;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlWordSettings()
    {
        return $this->_wordSettingsC;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlWordStyles($xmlWordStyles)
    {
        $this->_wordStylesC = $xmlWordStyles;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlWordStyles()
    {
        return $this->_wordStylesC;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlWordThemeTheme1($xmlWordThemeTheme)
    {
        $this->_wordThemeThemeC = $xmlWordThemeTheme;
    }

    /**
     * Getter
     *
     * @access public
     */
    public function getXmlWordThemeTheme1()
    {
        return $this->_wordThemeThemeC;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function setXmlWordWebSettings($xmlWordWebSettings)
    {
        $this->_wordWebSettingsC = $xmlWordWebSettings;
    }

    /**
     * Setter
     *
     * @access public
     */
    public function getXml_Word_WebSettings()
    {
        return $this->_wordWebSettingsC;
    }

    /**
     * Add a break
     *
     * @access public
     * @example ../examples/easy/PageBreak.php
     * @example ../examples/intermediate/ChartFootnote.php
     * @example ../examples/intermediate/FooterPager.php
     * @example ../examples/intermediate/Multidocument.php
     * @example ../examples/advanced/Report.php
     * @param string $type Break type.
     *  Values: 'line', 'page'
     */
    public function addBreak($type = '')
    {
        $page = CreatePage::getInstance();
        $page->generatePageBreak($type);
        self::$log->info('Add break to word document.');
        $this->_wordDocumentC .= (string) $page;
    }

    /**
     * Add a chart
     *
     * @access public
     * @example ../examples/easy/Chart.php
     * @example ../examples/easy/BarChart.php
     * @example ../examples/intermediate/Chart.php
     * @example ../examples/intermediate/ChartFootnote.php
     * @example ../examples/intermediate/Multidocument.php
     * @example ../examples/advanced/Report.php
     * @param array $dats Parameters of graphic
     *  Values: 'color' (1, 2, 3...), 'cornerP' (20, 30...),
     *  'cornerX' (20, 30...),
     *  'cornerY' (20, 30...),
     *  'data' (array of values),
     *  'font' (Arial, Times New Roman...),
     *  'groupBar' (clustered, stacked),
     *  'jc' (center, left, right),
     *  'showPercent' (0, 1), 'sizeX' (10, 11, 12...),
     *  'sizeY' (10, 11, 12...),
     *  'textWrap' (0 (inline), 1 (square), 2 (front), 3 (back), 4 (up and bottom), 5 (clear)),
     *  'title',
     *  'type' (barChart, bar3DChart, bar3DChartCylinder, bar3DChartCone,  bar3DChartPyramid, colChart, col3DChart,
     *          col3DChartCylinder,  col3DChartCone, bar3DChartPyramid, pieChart, pie3DChart, lineChart, line3DChart,
     *          areaChart, area3DChart, radar)
     *  'legendpos' (r, l, t, b, none),
     *  'legendoverlay' (0, 1),
     *  'border' (0, 1),
     *  'haxlabel',
     *  'vaxlabel',
     *  'showtable' (0, 1),
     *  'vaxlabel_display' (rotated, vertical, horizontal),
     *  'haxlabel_display' (rotated, vertical, horizontal),
     *  'hgrid' (0, 1, 2, 3),
     *  'vgrid' (0, 1, 2, 3)
     */
    public function addChart($dats)
    {
        self::$log->debug('Create chart.');
        try {
            if (isset($dats['data']) && isset($dats['type'])) {
                self::$intIdWord++;
                self::$log->debug('New ID ' . self::$intIdWord . ' . Chart.');
                $graphic = CreateGraphic::getInstance();
                if ($graphic->createGraphic(self::$intIdWord, $dats) != false) {
                    self::$log->info(
                        'Add chart word/charts/chart' . self::$intIdWord .
                        '.xml to DOCX.'
                    );
                    $this->_zipDocx->addFromString(
                        'word/charts/chart' . self::$intIdWord . '.xml',
                        $graphic->getXmlChart()
                    );
                    $this->_wordRelsDocumentRelsC .=
                        $this->generateRELATIONSHIP(
                            'rId' . self::$intIdWord, 'chart',
                            'charts/chart' . self::$intIdWord . '.xml'
                        );
                    $this->_wordDocumentC .= (string) $graphic;
                    $this->generateDEFAULT('xlsx', 'application/octet-stream');
                    $this->generateOVERRIDE(
                        '/word/charts/chart' . self::$intIdWord . '.xml',
                        'application/vnd.openxmlformats-officedocument.' .
                        'drawingml.chart+xml'
                    );
                } else {
                    throw new Exception(
                        'There was an error related to the chart.'
                    );
                }
                $excel = CreateXlsx::getInstance();
                $this->_tempFileXLSX[self::$intIdWord] =
                    tempnam($this->_tempDir, 'documentxlsx');
                if (
                    $excel->createXlsx(
                        $this->_tempFileXLSX[self::$intIdWord],
                        $dats['data'], $dats['type']
                    ) != false
                ) {
                    $this->_zipDocx->addFile(
                        $this->_tempFileXLSX[self::$intIdWord],
                        'word/embeddings/datos' . self::$intIdWord . '.xlsx'
                    );

                    $chartRels = CreateChartRels::getInstance();
                    $chartRels->createRelationship(self::$intIdWord);
                    $this->_zipDocx->addFromString(
                        'word/charts/_rels/chart' . self::$intIdWord .
                        '.xml.rels',
                        (string) $chartRels
                    );
                }
            } else {
                throw new Exception(
                    'Images must have "data" and "type" values.'
                );
            }
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            exit();
        }
    }
    
    /**
     * Merge DOCX. Keep content and styles.
     *
     * @access public
     * @example ../examples/easy/DOCX.php
     * @param string $pathDOCX Path to DOCX
     */
    public function addDOCX($pathDOCX)
    {
        try {
            if (file_exists($pathDOCX)) {
                $wordDOCX = EmbedDOCX::getInstance();
                $wordDOCX->embed();
                self::$log->info('Add DOCX file to word document.');
                $this->_wordDocumentC .= (string)$wordDOCX;
                $this->_zipDocx->addFile($pathDOCX, 'word/docx' . $wordDOCX->getId() .
                                                    '.zip');
                $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
                    'rDOCXId' . $wordDOCX->getId(), 'aFChunk', 'docx' .
                                                               $wordDOCX->getId() . '.zip', 'TargetMode="Internal"');
            } else {
                throw new Exception('File does not exist.');
            }
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            throw new Exception('File does not exist.');
        }
    }
    
    /**
     * Add an element to embedd in other elements
     *
     * @access public
     * @example ../examples/intermediate/List.php
     * @example ../examples/intermediate/TableStyled.php
     * @param string $type Element type.
     *  Values: 'addImage', 'addGraphic', 'addLink', 'addTextBox', 'addText'
     * @param array $parrams Set of parameters.
     *  Values: same as elements
     * @return Element object
     */
    public function addElement($type, $params = '')
    {
        $type = str_replace('add', 'Create', $type);
        $element = CreateFactory::createObject($type);
        $type = str_replace('Create', 'init', $type);
        $element->$type($params);
        if ($type == 'initImage') {
            self::$log->debug('Create embedded image.');
            try {
                if (isset($params['name']) && file_exists($params['name'])) {
                    $attrImages = getimagesize($params['name']);
                    try {
                        if ($attrImages['mime'] == 'image/jpg' ||
                            $attrImages['mime'] == 'image/jpeg' ||
                            $attrImages['mime'] == 'image/png' ||
                            $attrImages['mime'] == 'image/gif'
                        ) {
                            self::$intIdWord++;
                            self::$log->debug(
                                'New ID ' . self::$intIdWord .
                                ' . Embedded image.'
                            );
                            $type = str_replace('add', 'Create', $type);
                            $dir = $this->parsePath($params['name']);
                            $element->setRId(self::$intIdWord);
                            self::$log->info(
                                'Add image ' . $params['name']
                                . ' to DOCX.'
                            );
                            $this->_zipDocx->addFile(
                                $params['name'],
                                'word/media/image' . self::$intIdWord . '.'
                                . $dir['extension']
                            );
                            $this->generateDEFAULT(
                                $dir['extension'], $attrImages['mime']
                            );
                            self::$log->debug(
                                'Add a new relationship related to image '
                                . $params['name'] . ' .'
                            );
                            $this->_wordRelsDocumentRelsC .=
                                $this->generateRELATIONSHIP(
                                    'rId'
                                    . self::$intIdWord, 'image', 'media/image'
                                    . self::$intIdWord . '.'
                                    . $dir['extension']
                                );
                        } else {
                            throw new Exception(
                                'Image format is not supported.'
                            );
                        }
                    }
                    catch (Exception $e) {
                        self::$log->fatal($e->getMessage());
                        exit();
                    }
                } else {
                    throw new Exception('Image does not exist.');
                }
            }
            catch (Exception $e) {
                self::$log->fatal($e->getMessage());
                exit();
            }
        } elseif ($type == 'initGraphic' || $type == 'initChart') {
            self::$log->debug('Create embedded chart.');
            try {
                if (isset($params['data']) && isset($params['type'])) {
                    self::$intIdWord++;
                    self::$log->debug(
                        'New ID ' . self::$intIdWord . ' . Embedded chart.'
                    );
                    $element->setRId(self::$intIdWord);
                    self::$log->info(
                        'Add chart ' . 'word/charts/chart' . self::$intIdWord
                        . '.xml to DOCX.'
                    );
                    $this->_zipDocx->addFromString(
                        'word/charts/chart' . self::$intIdWord . '.xml',
                        $element->createEmbeddedXmlChart()
                    );
                    self::$log->debug(
                        'Add a new relationship related to chart.'
                    );
                    $this->_wordRelsDocumentRelsC .=
                        $this->generateRELATIONSHIP(
                            'rId' . self::$intIdWord, 'chart', 'charts/chart' .
                            self::$intIdWord . '.xml'
                        );
                    $this->generateDEFAULT('xlsx', 'application/octet-stream');
                    $this->generateOVERRIDE(
                        '/word/charts/chart' . self::$intIdWord .
                        '.xml',
                        'application/vnd.openxmlformats-officedocument' . 
                        '.drawingml.chart+xml'
                    );
                    $excel = CreateXlsx::getInstance();
                    $this->_tempFileXLSX[self::$intIdWord] = tempnam($this->_tempDir, 'documentxlsx');
                    if (
                        $excel->createXlsx(
                            $this->_tempFileXLSX[self::$intIdWord], $params['data'],
                            $params['type']
                        ) != false
                    ) {
                        $this->_zipDocx->addFile(
                            $this->_tempFileXLSX[self::$intIdWord],
                            'word/embeddings/datos' . self::$intIdWord . '.xlsx'
                        );

                        $chartRels = CreateChartRels::getInstance();
                        $chartRels->createRelationship(self::$intIdWord);
                        self::$log->info(
                            'Add chart ' . 'word/charts/_rels/chart'
                            . self::$intIdWord . '.xml.rels to DOCX.'
                        );
                        $this->_zipDocx->addFromString(
                            'word/charts/_rels/chart' . self::$intIdWord
                            . '.xml.rels', (string) $chartRels
                        );
                    }
                } else {
                    throw new Exception(
                        'Charts must have "data" and "type" values.'
                    );
                }
            }
            catch (Exception $e) {
                self::$log->fatal($e->getMessage());
                exit();
            }
        }

        return $element;
    }

    /**
     * Add an endnote
     *
     * @access public
     * @example ../examples/easy/Endnote.php
     * @example ../examples/intermediate/EndnoteAndFootnote.php
     * @param string $paramsEndnote Parameters of endnote.
     *  Optional, default empty.
     *  Values: 'font', 'textDocument', 'textEndNote'
     */
    public function addEndnote($paramsEndnote = '')
    {
        $endnote = CreateEndnote::getInstance();
        if (CreateEndnote::$init == 0) {
            self::$log->debug('Endnote does not exist, add default endnote.');
            $this->addDefaultEndnote();
        }
        $endnote->CreateEndnote($paramsEndnote);
        self::$log->info('Add endnote to endnote document.');
        $this->_wordEndnotesC .= (string) $endnote;
        $endnote->CreateDocumentEndnote($paramsEndnote);
        self::$log->info('Add endnote to word document.');
        $this->_wordDocumentC .= (string) $endnote;
    }

    /**
     * Add a new font
     *
     * @access public
     * @param array $fonts Fonts to add
     */
    public function addFont($fonts)
    {
        $font = CreateFontTable::getInstance();
        $font->createFont($fonts);
        self::$log->info('Add font to fontable document.');
        $this->_wordFontTableC .= (string) $font;
    }

    /**
     * Add a footer
     *
     * @access public
     * @example ../examples/easy/Footer.php
     * @example ../examples/intermediate/HeaderAndFooter.php
     * @example ../examples/intermediate/FooterPager.php
     * @example ../examples/advanced/Report.php
     * @param string $dat Text to add
     * @param array $paramsFooter Parameters of footer
     *  Values: 'name', 'pager' (true, false),
     *  'pagerAlignment' (left, right, false)
     */
    public function addFooter($dat = '', $paramsFooter = '')
    {
        $footer = CreateFooter::getInstance();
        $footer->createFooter($dat, $paramsFooter);
        self::$log->info('Add footer to footer document.');
        $this->_wordFooterC .= (string) $footer;
        if (!empty($paramsFooter['name'])) {
            self::$log->info('Add image to footer document.');
            $xmlHeaderImg = $this->addImageFooter($paramsFooter);
            $this->_wordFooterC = str_replace(
                '__GENERATEIMGFTR__', $xmlHeaderImg, $this->_wordFooterC
            );
        }
        $this->generateOVERRIDE(
            '/word/footer.xml',
            'application/vnd.openxmlformats-officedocument.wordprocessingml' .
            '.footer+xml'
        );
    }

    /**
     * Add a footnote
     *
     * @access public
     * @example ../examples/easy/Footnote.php
     * @example ../examples/intermediate/ChartFootnote.php
     * @example ../examples/intermediate/EndnoteAndFootnote.php
     * @param array $paramsFootnote Parameters of footnote
     *  Values: 'font', 'textDocument', 'textEndNote'
     */
    public function addFootnote($paramsFootnote = '')
    {
        $footnote = CreateFootnote::getInstance();
        if (CreateFootnote::$init == 0) {
            self::$log->debug('Footnote does not exist, add default footnote.');
            $this->addDefaultFootnote();
        }
        $footnote->createFootnote($paramsFootnote);
        self::$log->info('Add footnote to footnote document.');
        $this->_wordFootnotesC .= (string) $footnote;
        $footnote->createDocumentFootnote($paramsFootnote);
        self::$log->info('Add footnote to word document.');
        $this->_wordDocumentC .= (string) $footnote;
    }

    /**
     * Add a graphic
     *
     * @access public
     * @example ../examples/easy/Chart.php
     * @example ../examples/easy/BarChart.php
     * @example ../examples/intermediate/Chart.php
     * @example ../examples/intermediate/ChartFootnote.php
     * @example ../examples/intermediate/Multidocument.php
     * @example ../examples/advanced/Report.php
     * @param array $dats Parameters of graphic
     *  Values: 'color' (1, 2, 3...), 'cornerP' (20, 30...),
     *  'cornerX' (20, 30...), 'cornerY' (20, 30...), 'data' (array of values),
     *  'font' (Arial, Times New Roman...), 'groupBar' (clustered, stacked),
     *  'jc' (center, left, right), 'showPercent' (0, 1), 'sizeX' (10, 11,
     *   12...), 'sizeY' (10, 11, 12...), 'textWrap' (0 (inline), 1 (square),
     *  2 (front), 3 (back), 4 (up and bottom), 5 (clear)), 'title', 'type'
     *  (barChart, bar3DChart, colChart, col3DChart, pieChart, pie3DChart)
     *  @deprecated
     */
    public function addGraphic($dats)
    {
        self::$log->debug('Create chart.');
        try {
            if (isset($dats['data']) && isset($dats['type'])) {
                self::$intIdWord++;
                self::$log->debug('New ID ' . self::$intIdWord . ' . Chart.');
                $graphic = CreateGraphic::getInstance();
                if ($graphic->createGraphic(self::$intIdWord, $dats) != false) {
                    self::$log->info(
                        'Add chart word/charts/chart' . self::$intIdWord .
                        '.xml to DOCX.'
                    );
                    $this->_zipDocx->addFromString(
                        'word/charts/chart' . self::$intIdWord . '.xml',
                        $graphic->getXmlChart()
                    );
                    $this->_wordRelsDocumentRelsC .=
                        $this->generateRELATIONSHIP(
                            'rId' . self::$intIdWord, 'chart',
                            'charts/chart' . self::$intIdWord . '.xml'
                        );
                    $this->_wordDocumentC .= (string) $graphic;
                    $this->generateDEFAULT('xlsx', 'application/octet-stream');
                    $this->generateOVERRIDE(
                        '/word/charts/chart' . self::$intIdWord . '.xml',
                        'application/vnd.openxmlformats-officedocument.' .
                        'drawingml.chart+xml'
                    );
                } else {
                    throw new Exception(
                        'There was an error related to the chart.'
                    );
                }
                $excel = CreateXlsx::getInstance();
                $this->_tempFileXLSX[self::$intIdWord] =
                    tempnam($this->_tempDir, 'documentxlsx');
                if (
                    $excel->createXlsx(
                        $this->_tempFileXLSX[self::$intIdWord],
                        $dats['data'], $dats['type']
                    ) != false
                ) {
                    $this->_zipDocx->addFile(
                        $this->_tempFileXLSX[self::$intIdWord],
                        'word/embeddings/datos' . self::$intIdWord . '.xlsx'
                    );

                    $chartRels = CreateChartRels::getInstance();
                    $chartRels->createRelationship(self::$intIdWord);
                    $this->_zipDocx->addFromString(
                        'word/charts/_rels/chart' . self::$intIdWord .
                        '.xml.rels',
                        (string) $chartRels
                    );
                }
            } else {
                throw new Exception(
                    'Images must have "data" and "type" values.'
                );
            }
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            exit();
        }
    }

    /**
     * Add a graphic image
     *
     * @access public
     * @param array $dats Parameters of graphic
     * Values: 'color' (1, 2, 3, 4, 5), 'cornerX' (20, 30...), 
     * 'data' (array of values), sizeX' (10, 11, 12...),
     * 'sizeY' (10, 11, 12...), 'title',  'type' (barChart, bar3DChart, 
     * colChart, col3DChart, pieChart, pie3DChart)
     */
    public function addGraphicImg($dats)
    {
        self::$log->debug('Create image chart.');
        try {
            if (isset($dats['data']) && isset($dats['type'])) {
            	$graphic = CreateGraphicImg::getInstance();
            	if ($graphic->createGraphicImg($dats)) {
                    
                }
                else {
                    throw new Exception(
                        'Unsupported chart type.'
                    );
                }
            } else {
                throw new Exception(
                    'Images must have "data" and "type" values.'
                );
            }
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            exit();
        }
    }

    /**
     * Add a graphic template. Replace placeholder with a graphic
     *
     * @access public
     * @param array $dats Parameters of graphic
     *  Values: same as charts
     */
    public function addGraphicTemplate($dats)
    {
        try {
            if (isset($dats['data']) && isset($dats['type'])) {
                self::$intIdWord++;
                self::$log->debug(
                    'New ID ' . self::$intIdWord . ' . Image template.'
                );
                $graphic = CreateGraphic::getInstance();
                if ($graphic->createGraphic(self::$intIdWord, $dats) != false) {
                    $this->graphicTemplate['arrChartXML'][self::$intIdWord] =
                        $graphic->getXmlChart();
                    $this->graphicTemplate['arrRelationships'][self::$intIdWord] =
                        $this->generateRELATIONSHIP(
                            'rId' . self::$intIdWord, 'chart',
                            'charts/chart' . self::$intIdWord . '.xml'
                        );
                    $this->graphicTemplate['arrGraphics'][self::$intIdWord] =
                        (string) $graphic;
                    $this->graphicTemplate['arrGenerateDEFAULT'][self::$intIdWord] =
                        '<Default Extension="' . 'xlsx' . '" ContentType="' .
                        'application/octet-stream' . '"> </Default>';
                    $this->graphicTemplate['arrGenerateOVERRIDE'][self::$intIdWord] =
                        '<Override PartName="' . '/word/charts/chart' .
                        self::$intIdWord . '.xml' . '" ContentType="' .
                        'application/vnd.openxmlformats-officedocument.' .
                        'drawingml.chart+xml' . '"> </Override>';
                } else {
                    throw new Exception(
                        'There was an error related to the chart.'
                    );
                }
                $excel = CreateXlsx::getInstance();
                $this->_tempFileXLSX[self::$intIdWord] = tempnam($this->_tempDir, 'documentxlsx');
                if (
                    $excel->createXlsx(
                        $this->_tempFileXLSX[self::$intIdWord], $dats['data'],
                        $dats['type']
                    ) != false
                ) {
                    $this->fileGraphicTemplate['datos' . self::$intIdWord . '.xlsx'] =
                        'word/embeddings/datos' . self::$intIdWord . '.xlsx';

                    $objChartRels = CreateChartRels::getInstance();
                    $objChartRels->createRelationship(self::$intIdWord);
                    $this->fileGraphicTemplate['word/charts/_rels/chart' . self::$intIdWord . '.xml.rels'] =
                        (string) $objChartRels;
                }
            } else {
                throw new Exception(
                    'Charts must have "data" and "type" values.
                ');
            }
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            exit();
        }
    }

    /**
     * Add a header.
     *
     * @access public
     * @example ../examples/easy/Header.php
     * @example ../examples/intermediate/HeaderAndFooter.php
     * @example ../examples/advanced/Report.php
     * @param string $text Text to add
     * @param array $paramsHeader Parameters of header
     *  Values: 'border'(1, 2, 3...), 'borderDiscontinuous' (0, 1),
     *  'font' (Arial, Times New Roman...), 'jc' (center, left, right),
     *  'name', 'scaling' (50, 100), 'sizeX' (10, 11, 12...), 'sizeY'
     *  (10, 11, 12...), spacingTop (10, 11...), spacingBottom (10, 11...),
     *  spacingLeft (10, 11...), spacingRight (10, 11...), 'textWrap'
     *  (0 (inline), 1 (square), 2 (front), 3 (back), 4 (up and bottom),
     *  5 (clear))
     */
    public function addHeader($text = 'Header', $paramsHeader = '')
    {
        $header = CreateHeader::getInstance();
        $header->createHeader($text, $paramsHeader);
        self::$log->info('Add header to header document.');
        $this->_wordHeaderC .= (string) $header;
        if (!empty($paramsHeader['name'])) {
            self::$log->info('Add image to header document.');
            $xmlHeaderImg = $this->addImageHeader($paramsHeader);
            $this->_wordHeaderC = str_replace(
                '__GENERATEHDRIMG__', $xmlHeaderImg, $this->_wordHeaderC
            );
        }
        $this->generateOVERRIDE(
            '/word/header.xml',
            'application/vnd.openxmlformats-officedocument.wordprocessingml.' .
            'header+xml'
        );
    }

    /**
     * Add a HTML to the document. First convert HTML to DOCX XML.
     *   It's possible to use CSS for styling
     *
     * @access public
     * @example ../examples/intermediate/HTML.php
     * @param string $html HTML to add. Must be a valid XHTML
     * @param string $css CSS for styling
     */
    public function addBasicHTML($html = '<HTML />', $css = null)
    {
        $htmlDOCX = new HTML2DOCX();
        $htmlDOCX->setHTML($html);
        $htmlDOCX->setCSS($css);
        self::$log->info('Add converted HTML to word document.');
        $this->_wordDocumentC .= (string) $htmlDOCX->returnXML();
    }

    /**
     * Add HTML to the document. Embed HTML.
     *
     * @access public
     * @example ../examples/easy/HTML.php
     * @example ../examples/intermediate/HTML.php
     * @param string $html HTML to add
     */
    public function addHTML($html = '')
    {
        $wordHTML = EmbedHTML::getInstance();
        $wordHTML->embed();
        self::$log->info('Embed HTML to word document.');
        $this->_wordDocumentC .= (string) $wordHTML;
        $this->_zipDocx->addFromString('word/html' . $wordHTML->getId() .
         '.htm', '<html>' . $html . '</html>');
        $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
            'rHTMLId' . $wordHTML->getId() , 'aFChunk', 'html' .
             $wordHTML->getId() . '.htm', 'TargetMode="Internal"');
    }

    /**
     * Add an image
     *
     * @access public
     * @example ../examples/easy/Image.php
     * @example ../examples/intermediate/ChartFootnote.php
     * @param array $dats Image to add and paramaters to use
     *  Values: 'border'(1, 2, 3...), 'borderDiscontinuous' (0, 1),
     *  'font' (Arial, Times New Roman...), 'jc' (center, left, right),
     *  'name', 'scaling' (50, 100), 'sizeX' (10, 11, 12...), 'sizeY'
     *  (10, 11, 12...), spacingTop (10, 11...), spacingBottom (10, 11...),
     *  spacingLeft (10, 11...), spacingRight (10, 11...), 'textWrap'
     *  (0 (inline), 1 (square), 2 (front), 3 (back), 4 (up and bottom),
     *  5 (clear))
     */
    public function addImage($dats = '')
    {
        self::$log->debug('Create image.');
        try {
            if (isset($dats['name']) && file_exists($dats['name']) == 'true') {
                $attrImage = getimagesize($dats['name']);
                try {
                    if ($attrImage['mime'] == 'image/jpg' ||
                        $attrImage['mime'] == 'image/jpeg' ||
                        $attrImage['mime'] == 'image/png' ||
                        $attrImage['mime'] == 'image/gif'
                    ) {
                        self::$intIdWord++;
                        self::$log->debug(
                            'New ID ' . self::$intIdWord . ' . Image.'
                        );
                        $image = CreateImage::getInstance();
                        $dats['rId'] = self::$intIdWord;
                        $image->createImage($dats);
                        $this->_wordDocumentC .= (string) $image;
                        $dir = $this->parsePath($dats['name']);
                        self::$log->info(
                            'Add image word/media/image' .
                            self::$intIdWord . '.' . $dir['extension'] .
                            '.xml to DOCX.'
                        );
                        $this->_zipDocx->addFile(
                            $dats['name'], 'word/media/image' .
                            self::$intIdWord . '.' .
                            $dir['extension']
                        );
                        $this->generateDEFAULT(
                            $dir['extension'], $attrImage['mime']
                        );
                        if ((string) $image != '')
                            $this->_wordRelsDocumentRelsC .=
                                $this->generateRELATIONSHIP(
                                    'rId' . self::$intIdWord, 'image',
                                    'media/image' . self::$intIdWord . '.'
                                    . $dir['extension']
                                );
                    } else {
                        throw new Exception('Image format is not supported.');
                    }
                }
                catch (Exception $e) {
                    self::$log->fatal($e->getMessage());
                    exit();
                }
            } else {
                throw new Exception('Image does not exist.');
            }
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            exit();
        }
    }

    /**
     * Add a link
     * 
     * @access public
     * @example ../examples/easy/Link.php
     * @example ../examples/advanced/Report.php
     * @param string $text Text to use as link
     * @param string $link URL link
     * @param string $font Type of font
     *  Values: 'Arial', 'Times New Roman'...
     *
     */
    public function addLink($text = '', $textLink = '', $font = '')
    {
        $link = CreateLink::getInstance();
        $link->createLink($text, $textLink, $font);
        self::$log->info('Add link to word document.');
        $this->_wordDocumentC .= (string) $link;
    }

    /**
     * Add a list
     *
     * @access public
     * @example ../examples/easy/List.php
     * @example ../examples/easy/ListBullets.php
     * @example ../examples/intermediate/List.php
     * @example ../examples/intermediate/List_nested.php
     * @example ../examples/intermediate/Multidocument.php
     * @param array $dats Values of the list
     * @param array $paramsList Parameters to use
     *  Values: 'font' (Arial, Times New Roman...),
     *  'val' (0 (clear), 1 (inordinate), 2(numerical)),
     *  array 'bullets' (1 (ï‚·), 2 (o), 3 (ï‚§))
     *
     */
    public function addList($dats, $paramsList = '')
    {
        $list = CreateList::getInstance();
        $list->createList($dats, $paramsList);
        self::$log->info('Add list to word document.');
        $this->_wordDocumentC .= (string) $list;
        
        if (!empty($paramsList['bullets']) 
        	&& is_array($paramsList['bullets']) 
        	&& $paramsList['val'] == 1
        ) {
        	for ($i = 0; $i <= CreateList::MAXDEPTH; $i++) {
        		$bullets = $paramsList['bullets'];
        		$styleId = $bullets[$i] ? $bullets[$i] : $i;
		        $list->createListStyles($i, $styleId);
		        self::$log->info('Add list styles to word document.');
		        $this->_wordDocumentStyles .= (string) $list;
        	}
        }
    }

    /**
     * Add a macro from a DOC
     *
     * @access public
     * @param string $path Path to a file with macro
     */
    public function addMacroFromDoc($path)
    {
        $package = new ZipArchive();
        self::$log->info('Open document with a macro.');
        $package->open($path);
        self::$log->info('Add macro files to DOCX file.');
        $this->_zipDocx->addFromString(
            'word/vbaData.xml',
            $package->getFromName('word/vbaData.xml')
        );
        $this->_zipDocx->addFromString(
            'word/vbaProject.bin',
            $package->getFromName('word/vbaProject.bin')
        );
        $this->_zipDocx->addFromString(
            'word/_rels/vbaProject.bin.rels',
            $package->getFromName('word/_rels/vbaProject.bin.rels')
        );
        self::$intIdWord++;
        self::$log->debug('New ID ' . self::$intIdWord . ' . Macro.');
        if (self::$intIdWord != 1) {
            $this->_wordDocumentC = str_replace(
                'rId1', 'rId' . self::$intIdWord, $this->_wordDocumentC
            );
            $this->_relsRelsC = str_replace(
                'rId1',
                'rId' . self::$intIdWord, $this->_relsRelsC
            );
        }
        $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
            'rId1', 'vbaProject', 'vbaProject.bin'
        );
        $this->generateDEFAULT('bin', 'application/vnd.ms-office.vbaProject');
        $this->generateOVERRIDE(
            '/word/vbaData.xml', 'application/vnd.ms-word.vbaData+xml'
        );
        $package->close();
    }

    /**
     * Convert a math eq to DOCX
     *
     * @access public
     * @example ../examples/easy/Math.php
     * @param string $path Path to a file with math eq
     */
    public function addMathDocx($path)
    {
        $package = new ZipArchive();
        self::$log->info('Open document with an existing math eq.');
        $package->open($path);
        $document = $package->getFromName('word/document.xml');
        $eqs = preg_split('/<[\/]*m:oMathPara>/', $document);
        self::$log->info('Add math eq to word document.');
        $this->addMathEq('<m:oMathPara>' . $eqs[1] . '</m:oMathPara>');
        $package->close();
    }

    /**
     * Add an existing math eq to DOCX
     *
     * @access public
     * @example ../examples/easy/Math.php
     * @param string $eq Math eq
     */
    public function addMathEq($eq)
    {
        self::$log->info('Add existing math eq to word document.');
        $this->_wordDocumentC .= '<' . CreateDocx::NAMESPACEWORD . ':p>' .
            (string) $eq . '</' . CreateDocx::NAMESPACEWORD . ':p>';
    }

    /**
     * Convert a math MML eq to DOCX
     *
     * @access public
     * @param string $eq Math eq
     */
    public function addMathMML($eq)
    {
        $math = CreateMath::getInstance();
        self::$log->debug('Convert MathMML eq.');
        $math->createMath($eq);
        self::$log->info('Add converted MathMML eq to word document.');
        $this->addMathEq('<m:oMathPara>' . (string) $math . '</m:oMathPara>');
    }

    /**
     * Add a MHT file.
     *
     * @access public
     * @example ../examples/easy/MHT.php
     * @param string $pathMHT Path to MHT
     */
    public function addMHT($pathMHT)
    {
        try {
            if (file_exists($pathMHT)) {
                $wordMHT = EmbedMHT::getInstance();
                $wordMHT->embed();
                self::$log->info('Add MHT file to word document.');
                $this->_wordDocumentC .= (string) $wordMHT;
                $this->_zipDocx->addFile($pathMHT, 'word/mht' . $wordMHT->getId() .
                '.mht');
                $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
                    'rMHTId' . $wordMHT->getId() , 'aFChunk', 'mht' .
                    $wordMHT->getId() . '.mht', 'TargetMode="Internal"');
            } else {
                throw new Exception('File does not exist.');
            }
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            throw new Exception('File does not exist.');
        }
    }

    /**
     * Add an existing object (XLS or PPTX)
     *
     * @access public
     * @example ../examples/easy/Object.php
     * @param string $path Object path
     * @param string $type Object type
     *   Values: xlsx, pptx
     */
    public function addObject($path, $type)
    {
        try {
            if (file_exists($path) && ($type == 'xls' || $type == 'pptx')) {
                self::$intIdWord++;
                self::$log->debug('New ID ' . self::$intIdWord . ' . Object.');
                if ($type == 'xls') {
                    $this->generateDEFAULT(
                        'xls', 'application/vnd.ms-excel'
                    );
                    $this->_wordRelsDocumentRelsC .=
                        $this->generateRELATIONSHIP('rId' . self::$intIdWord,
                            'oleObject',
                            'embeddings/Microsoft_Office_Excel_97-2003_'
                            + 'Worksheet' + self::$intIdWord + '.xls'
                        );
                } elseif ($type == 'pptx') {
                    $this->generateDEFAULT(
                        'pptx', 'application/vnd.openxmlformats-officedocument'
                        + '.presentationml.presentation'
                    );
                    $this->_wordRelsDocumentRelsC .=
                        $this->generateRELATIONSHIP('rId' . self::$intIdWord,
                            'package',
                            'embeddings/Microsoft_Office_PowerPoint_'
                            + 'PresentationWorksheet' + self::$intIdWord
                            + '.pptx'
                    );
                }
                $this->generateDEFAULT(
                        'emf', 'image/x-emf'
                );
                $object = CreateObject::getInstance();
                $object->createObject($path, $type);
                self::$log->info('Add object to word document.');
                $this->_wordDocumentC .= (string) $object;
            } else {
                throw new Exception('File does not exist or format is not
                    supported.');
            }
        }
        catch (Exception $e) {
            self::$log->warn($e->getMessage());
            throw new Exception('File does not exist or format is not supported.');
        }
    }
    
    /**
     * Add properties to document
     * 
     * @access public
     * @param array $values
     * @example ../examples/easy/Properties.php
     * @param array $values Parameters to use
     *  Values: 'title', 'subject', 'creator', 'keywords', 'description', 
     *  'category', 'manager', 'custom' ('title', 'value')
     */
    
    public function addProperties($values)
    {
        $prop = CreateProperties::getInstance();
        $prop->createProperties($values);
        self::$log->info('Add properties to word document.');
        $this->_docPropsCoreC .= (string) $prop;
        if (!empty($values['manager']) 
        	|| !empty($values['company'])) {
	        $prop->createPropertiesApp($values);
	        $this->_docPropsAppC .= (string) $prop;
        }
        if (!empty($values['custom'])
        	&& is_array($values['custom'])) {
	        $prop->createPropertiesCustom($values['custom']);
	        $this->_docPropsCustomC .= (string) $prop;
        }
    }
    
    /**
     * Add a raw WordML
     *
     * @access public
     * @param string $wml WordML to add
     * @deprecated See addWordML
     */
    public function addRawWordML($wml)
    {
        self::$log->info('Add raw WordML');
        $this->_wordDocumentC .= $wml;
    }
    
    /**
     * Add a RTF file. Keep content and styles.
     *
     * @access public
     * @example ../examples/easy/RTF.php
     * @param string $pathRTF Path to RTF
     */
    public function addRTF($pathRTF)
    {
        try {
            if (file_exists($pathRTF)) {
                $wordRTF = EmbedRTF::getInstance();
                $wordRTF->embed();
                self::$log->info('Add RTF file to word document.');
                $this->_wordDocumentC .= (string) $wordRTF;
                $this->_zipDocx->addFile($pathRTF, 'word/rtf' . $wordRTF->getId() .
                '.rtf');
                $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
                    'rRTFId' . $wordRTF->getId() , 'aFChunk', 'rtf' .
                    $wordRTF->getId() . '.rtf', 'TargetMode="Internal"');
            } else {
                throw new Exception('File does not exist.');
            }
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            throw new Exception('File does not exist.');
        }
    }

    /**
     * Add a section
     *
     * @access public
     * @example ../examples/easy/Section.php
     * @param array $dats Parameters to use
     *  Values: 'bottom' (4000, 4001...), 'columns' (1, 2, 3),
     *  'left' (4000, 4001...), 'orient' (landscape), 'right' (4000, 4001),
     *  'titlePage' (1), 'top' (4000, 4001)
     */
    public function addSection($dats = '')
    {
        $page = CreatePage::getInstance();
        $page->createSection($dats);
        self::$log->info('Add section to word document.');
        $this->_wordDocumentC .= (string) $page;
    }
    
    /**
     * Add a shape
     *
     * @access public
     * @example ../examples/easy/Shape.php
     * @param string $type Type of shape to draw
     *  Values: line
     * @param array $style Style of text
     *  Values: 'width' (300, 400...), 'height' (300, 400...)
     */
    public function addShape($type, $style = '')
    {
        $shape = CreateShape::getInstance();
        $shape->createShape($type, $style);
        self::$log->info('Add a shape to word document.');
        $this->_wordDocumentC .= (string) $shape;
    }
    
    /**
     * Add a table.
     *
     * @access public
     * @example ../examples/easy/Table.php
     * @example ../examples/intermediate/Table.php
     * @example ../examples/intermediate/TableStyled.php
     * @example ../examples/advanced/Report.php
     * @param array $dats Values to add
     * @param array $parameters Parameters to use
     *  Values:
     *  'border' (none, single, double);
     *  'border_color' (ffffff, ff0000);
     *  'border_spacing' (0, 1, 2...);
     *  'border_sz' (10, 11...);
     *  'font' (Arial, Times New Roman...);
     *  'jc' (center, left, right);
     *  'size_col': column width fix (1200, 1300...),
     *              column width variable (array);
     *  'TBLSTYLEval' (Cuadrculamedia3-nfasis1,
     *                Sombreadomedio1 Tablaconcuadrcula, TableGrid);
     */
    public function addTable($dats, $parameters = '')
    {
        $table = CreateTable::getInstance();
        $table->createTable($dats, $parameters);
        self::$log->info('Add table to word document.');
        $this->_wordDocumentC .= (string) $table;
    }

    /**
     * Add a table of contents (TOC)
     *
     * @access public
     * @example ../examples/easy/TableContents.php
     * @param string $font Set font type
     *  Values: 'Arial', 'Times New Roman'...
     */
    public function addTableContents($font = '')
    {
        $tableContents = CreateTableContents::getInstance();
        $tableContents->createTableContents($font);
        self::$log->info('Add table of contents to word document.');
        $this->_wordDocumentC .= (string) $tableContents;
    }

    /**
     * Add a DOCX file as a template
     *
     * @access public
     * @example ../examples/easy/Template.php
     * @param string $path Path to the file
     */
    public function addTemplate($path)
    {
        $template = CreateTemplate::getInstance();
        try {
            if (file_exists($path)) {
                self::$log->info('Open template ' . $path . '.');
                $template->openTemplate($path);
            } else {
                throw new Exception('File ' . $path . ' not exists');
            }
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            exit();
        }
    }

    /**
     * Replace a variable with a chart.
     *
     * @access public
     * @example ../examples/easy/Template_chart.php
     * @param string $var Value of the variable
     * @param string $chart Chart to add
     *  Values: same as charts.
     */
    public function addTemplateChart($var, $chart)
    {
        $template = CreateTemplate::getInstance();
        self::$log->info('Assign as chart variable ' . $var . ' in template.');
        $this->addGraphicTemplate($chart);
        self::$log->info('Replace chart variable ' . $var . ' in template.');
        $template->replaceChart($var);
    }

    /**
     * Replace a variable with a checkbox.
     *
     * @access public
     * @param string $var Value of the variable. String
     * @param string $value
     */
    public function addTemplateCheckBox($var, $value = false)
    {
        $template = CreateTemplate::getInstance();
        self::$log->info(
            'Replace text variable ' . $var . ' with a checkbox.'
        );
        $template->replaceCheckBox($var, $value);
    }

    /**
     * Replace a variable image template with a new image.
     *
     * @access public
     * @example ../examples/easy/Template_image.php
     * @param string $var Value of the variable
     * @param string $pathImage Path of the new image
     */
    public function addTemplateImage($var, $pathImage)
    {
        $template = CreateTemplate::getInstance();
        self::$log->info(
            'Assign and replace image variable ' . $var . ' in template.'
        );
        $template->replaceImage($var, $pathImage);
    }

    /**
     * Replace a variable with a text, HTML, DOCX, RTF, MHT.
     *
     * @access public
     * @example ../examples/easy/Template.php
     * @example ../examples/easy/TemplateDOCX.php
     * @example ../examples/easy/TemplateHTML.php
     * @example ../examples/easy/TemplateImage.php
     * @example ../examples/easy/TemplateMHT.php
     * @example ../examples/easy/TemplateRTF.php
     * @example ../examples/intermediate/Template.php
     * @param mixed $var Value of the variable. String or array of values
     * @param string $value Text value, type of value or text array
     *  Values type of template: list, table
     * @param mixed $settings Template settings or content type
     *  Content types: html, rtf, docx, mht, image
     */
    public function addTemplateVariable($var, $value = '', $settings = '')
    {
        $template = CreateTemplate::getInstance();
        self::$log->info(
            'Assign and replace text variable ' . $var . ' in template.'
        );
        $template->replaceVariable($var, $value, $settings);
    }

    /**
     * Add a text
     *
     * @access public
     * @example ../examples/easy/Text.php
     * @example ../examples/easy/Text_linespacing.php
     * @example ../examples/easy/TextCursive.php
     * @example ../examples/intermediate/ChartFootnote.php
     * @example ../examples/intermediate/FooterPager.php
     * @example ../examples/intermediate/Multidocument.php
     * @example ../examples/intermediate/Text.php
     * @example ../examples/advanced/Report.php
     * @param mixed $value Text string or array of texts to add
     *  Values array: 'b' (single), 'cell_color' (ffffff, ff0000...),
     *  'color' (ffffff, ff0000...),
     *  'font' (Arial, Times New Roman...), 'i' (single),
     *  'jc' (both, center, distribute, left, right),
     *  'pageBreakBefore' (on, off), 'sz' (1, 2, 3...), 'text'
     *  'u' (dash, dotted, double, single, wave, words),
     *  'widowControl' (on, off), 'wordWrap' (on, off)
     * @param array $style Style of text
     *  Values: 'b' (single), 'color' (ffffff, ff0000...),
     *  'font' (Arial, Times New Roman...), 'i' (single),
     *  'jc' (both, center, distribute, left, right),
     *  'pageBreakBefore' (on, off), 'sz' (1, 2, 3...),
     *  'u' (dash, dotted, double, single, wave, words),
     *  'widowControl' (on, off), 'wordWrap' (on, off),
     *  'lineSpacing' 120, 240 (standard), 480...,
     *  'indent_left' 100..., 'indent_right' 100...
     */
    public function addText($value, $style = '')
    {
        $text = CreateText::getInstance();
        $text->createText($value, $style);
        self::$log->info('Add text to word document.');
        $this->_wordDocumentC .= (string) $text;
    }

    /**
     * Add a textbox
     *
     * @access public
     * @example ../examples/easy/TextBox.php
     * @param mixed $text Text string to add using params or not
     * @param array $style Style of text
     *  Values: 'align' (center, left, right), 'fillcolor' (black, red...),
     *  'font' (Arial, Times New Roman...), 'height' (300, 400...),
     *  'jc' (square, through), 'margin_bottom' (100, 110...),
     *  'margin_left' (100, 110...), 'margin_right' (100, 110...),
     *  'margin_top' (100, 110...)
     */
    public function addTextBox($text, $style = '')
    {
        $textBox = CreateTextBox::getInstance();
        $textBox->createTextBox($text, $style);
        self::$log->info('Add textbox to word document.');
        $this->_wordDocumentC .= (string) $textBox;
    }

    /**
     * Add a title
     *
     * @access public
     * @example ../examples/easy/Title.php
     * @example ../examples/intermediate/Multidocument.php
     * @example ../examples/advanced/Report.php
     * @param string $text Text to add
     * @param array $style Style of title
     *  Values: 'b' (single), 'color' (ffffff, ff0000...),
     *  'font' (Arial, Times New Roman...), 'i' (single),
     *  'jc' (both, center, distribute, left, right),
     *  'pageBreakBefore' (on, off), 'sz' (1, 2, 3...),
     *  'u' (dash, dotted, double, single, wave, words),
     *  'widowControl' (on, off), 'wordWrap' (on, off)
     */
    public function addTitle($text, $style = '')
    {
        $title = CreateText::getInstance();
        $title->createTitle($text, $style);
        self::$log->info('Add title to word document.');
        $this->_wordDocumentC .= (string) $title;
    }

    /**
     * Add WordML to the document. Embed WordML.
     *
     * @access public
     * @example ../examples/easy/WordML.php
     * @param string $wordML WordML to add
     */
    public function addWordML($wordML = '')
    {
        $this->_wordDocumentC .= $wordML;
    }

    /**
     * Clear all blocks
     *
     * @access public
     */
    public function clearBlocks()
    {
        self::$log->info('Clear all blocks.');
        CreateTemplate::deleteAllBlocks();
    }

    /**
     * Generate a new DOCX file
     *
     * @access public
     * @example ../examples/easy/Text.php
     * @example ../examples/advanced/Report.php
     * @param string $args[0] File name
     * @param string $args[1] Page style
     *  Values: 'bottom' (4000, 4001...), 'columns' (1, 2, 3), 'left' (4000, 4001...),
     *  'orient' (landscape), 'right' (4000, 4001), 'titlePage' (1),
     *  'top' (4000, 4001)
     */
    public function createDocx()
    {
        $args = func_get_args();
        if (!empty($args[0])) {
            $fileName = $args[0];
        } else {
            $fileName = 'document';
        }
        self::$log->info('Set DOCX name to: ' . $fileName . '.');
        if (!CreateTemplate::getBlnTemplate()) {
            self::$log->debug('DOCX is a new file, not a template.');
            try {
               GenerateDocx::beginDocx();
            }
            catch (Exception $e) {
                self::$log->fatal($e->getMessage());
                exit();
            }
            $this->generateTemplateRelsRels();
            self::$log->info('Add _rels/.rels content to DOCX file.');
            $this->_zipDocx->addFromString('_rels/.rels', $this->_relsRelsT);
            $this->generateTemplateDocPropsApp();
            self::$log->info('Add docProps/app.xml content to DOCX file.');
            $this->_zipDocx->addFromString(
                'docProps/app.xml', $this->_docPropsAppT
            );
            $this->generateTemplateDocPropsCore();
            self::$log->info('Add docProps/core.xml content to DOCX file.');
            $this->_zipDocx->addFromString(
                'docProps/core.xml', $this->_docPropsCoreT
            );
            
            if (!empty($this->_markAsFinal)
            	|| !empty($this->_docPropsCustomC))
            {
	            $this->generateTemplateDocPropsCustom();
	            self::$log->info('Add docProps/custom.xml content to DOCX file.');
	            $this->_zipDocx->addFromString(
	            	'docProps/custom.xml', $this->_docPropsCustomT
	            );
            }
            $this->addStyle($this->_language);
            $this->generateTemplateWordStyles();
            self::$log->info('Add word/styles.xml content to DOCX file.');
            $this->_zipDocx->addFromString(
                'word/styles.xml', $this->_wordStylesT
            );

            $this->addSettings();
            $this->generateTemplateWordSettings();
            self::$log->info('Add word/settings.xml content to DOCX file.');
            $this->_zipDocx->addFromString(
                'word/settings.xml', $this->_wordSettingsT
            );

            $this->addWebSettings();
            $this->generateTemplateWordWebSettings();
            self::$log->info('Add word/webSettings.xml content to DOCX file.');
            $this->_zipDocx->addFromString(
                'word/webSettings.xml', $this->_wordWebSettingsT
            );

            if (!empty($this->_wordFooterC)) {
                self::$log->debug('There is a footer, add it.');
                $this->generateTemplateWordFooter();
                self::$log->info('Add word/footer.xml content to DOCX file.');
                if (self::$_encodeUTF) {
                    $this->_zipDocx->addFromString(
                        'word/footer.xml', utf8_encode($this->_wordFooterT)
                    );
                } else {
                    $this->_zipDocx->addFromString(
                        'word/footer.xml', $this->_wordFooterT
                    );
                }
                if (CreateEndnote::$init == 0) {
                    self::$log->debug('There is no endnote, add default one.');
                    $this->addDefaultEndnote();
                }
                $this->generateTemplateWordEndnotes();
                self::$log->info('Add word/endnotes.xml content to DOCX file.');
                $this->_zipDocx->addFromString(
                    'word/endnotes.xml', $this->_wordEndnotesT
                );
                if (CreateFootnote::$init == 0) {
                    self::$log->debug('There is no footnote, add default one.');
                    $this->addDefaultFootnote();
                }
                $this->generateTemplateWordFootnotes();
                self::$log->info(
                    'Add word/footnotes.xml content to DOCX file.'
                );
                $this->_zipDocx->addFromString(
                    'word/footnotes.xml', $this->_wordFootnotesT
                );
            } elseif (
                  !empty($this->_wordEndnotesC) ||
                  !empty($this->_wordFootnotesC)
                ) {
                  self::$log->debug(
                      'There is an endnote or footnote, add them.'
                  );
                  if (CreateEndnote::$init == 0) {
                      self::$log->debug(
                          'There is no endnote, add default one.'
                      );
                      $this->addDefaultEndnote();
                  }
                  $this->generateTemplateWordEndnotes();
                  self::$log->info(
                      'Add word/endnotes.xml content to DOCX file.'
                  );
                  $this->_zipDocx->addFromString(
                      'word/endnotes.xml', $this->_wordEndnotesT
                  );
                  if (CreateFootnote::$init == 0) {
                      self::$log->debug(
                          'There is no footnote, add default one.'
                      );
                      $this->addDefaultFootnote();
                  }
                  $this->generateTemplateWordFootnotes();
                  self::$log->info(
                      'Add word/footnotes.xml content to DOCX file.'
                  );
                  $this->_zipDocx->addFromString(
                      'word/footnotes.xml', $this->_wordFootnotesT
                  );
            }

            if (!empty($this->_wordHeaderC)) {
                self::$log->debug('There is a header, add it.');
                $this->generateTemplateWordHeader();
                self::$log->info('Add word/header.xml content to DOCX file.');
                if (self::$_encodeUTF) {
                    $this->_zipDocx->addFromString(
                        'word/header.xml', utf8_encode($this->_wordHeaderT)
                    );
                } else {
                    $this->_zipDocx->addFromString(
                        'word/header.xml', $this->_wordHeaderT
                    );
                }
            }
            self::$log->debug('Check for a valid license.');
            GenerateDocx::beginDocx();
            if (!empty($this->_wordRelsHeaderRelsC)) {
                self::$log->debug('There is a header rels, add it.');
                $this->generateTemplateWordRelsHeaderRels();
                self::$log->info(
                    'Add word/_rels/header.xml.rels content to DOCX file.'
                );
                $this->_zipDocx->addFromString(
                    'word/_rels/header.xml.rels', $this->_wordRelsHeaderRelsT
                );
            }
            if (!empty($this->_wordRelsFooterRelsC)) {
                self::$log->debug('There is a footer rels, add it.');
                $this->generateTemplateWordRelsFooterRels();
                self::$log->info(
                    'Add word/_rels/footer.xml.rels content to DOCX file.'
                );
                $this->_zipDocx->addFromString(
                    'word/_rels/footer.xml.rels', $this->_wordRelsFooterRelsT
                );
            }
            if ($this->_extension == 'docm') {
                self::$log->debug('It is a macro, generate a new override');
                $this->generateOVERRIDE(
                    '/word/document.xml',
                    'application/vnd.ms-word.document.macroEnabled.main+xml'
                );
            } else {
                self::$log->debug('It isnt a macro, generate a new override');
                $this->generateOVERRIDE(
                    '/word/document.xml',
                    'application/vnd.openxmlformats-officedocument.' .
                    'wordprocessingml.document.main+xml'
                );
            }

            $this->generateTemplateContentType();
            self::$log->info('Add [Content_Types].xml content to DOCX file.');
            $this->_zipDocx->addFromString(
                '[Content_Types].xml',
                $this->_wordContentTypeT
            );
            
            if (!empty($this->_wordDocumentStyles)) {
            	$this->generateTemplateWordNumberingStyles();
            } else {
            	$this->generateTemplateWordNumbering();
            }
            self::$log->info('Add word/numbering.xml content to DOCX file.');
            $this->_zipDocx->addFromString(
                'word/numbering.xml', $this->_wordNumberingT
            );

            $this->generateDefaultWordRels();
            if (!empty($this->_wordRelsDocumentRelsC)) {
                self::$log->debug('There is a word rels, add it.');
                $this->generateTemplateWordRelsDocumentRels();
                self::$log->info(
                    'Add word/_rels/document.xml.rels content to DOCX file.'
                );
                $this->_zipDocx->addFromString(
                    'word/_rels/document.xml.rels',
                    $this->_wordRelsDocumentRelsT
                );
            }
            $arrArgsPage = array();
            if (isset($args[1])) {
                self::$log->debug('Page arguments.');
                $arrArgsPage = $args[1];
            }
            $this->generateTemplateWordDocument($arrArgsPage);
            if ($this->_debug->getActive() == 1) {
                self::$log->debug('Debug is active, add messages to objDebug.');
                libxml_use_internal_errors(true);
                simplexml_load_string(
                    $this->_wordDocumentT, 'SimpleXMLElement', LIBXML_NOWARNING
                );
                $xmlErrors = libxml_get_errors();
                if (is_array($xmlErrors)) {
                    $this->_debug->addMessage($xmlErrors);
                    libxml_clear_errors();
                }
            }

            self::$log->info('Add word/document.xml content to DOCX file.');
            if (self::$_encodeUTF) {
                $this->_zipDocx->addFromString(
                    'word/document.xml', utf8_encode($this->_wordDocumentT)
                );
            } else {
                $this->_zipDocx->addFromString(
                    'word/document.xml', $this->_wordDocumentT
                );
            }

            $this->generateDefaultFonts();
            $this->generateTemplateWordFontTable();
            self::$log->info('Add word/fontTable.xml content to DOCX file.');
            $this->_zipDocx->addFromString(
                'word/fontTable.xml', $this->_wordFontTableT
            );

            $this->generateTemplateWordThemeTheme1();
            self::$log->info('Add word/theme/theme1.xml content to DOCX file.');
            $this->_zipDocx->addFromString(
                'word/theme/theme1.xml', $this->_wordThemeThemeT
            );

            self::$log->info('End of file, close it.');
            $this->_zipDocx->close();

            $arrpathFile = pathinfo($fileName);
            self::$log->info('Copy DOCX file using a new name.');
            copy(
                $this->_tempFile,
                $fileName . '.' . $this->_extension
            );

            if ($this->_debug->getActive() == 1) {
                self::$log->debug('Debug is active, show messages.');
                echo $this->_debug;
            }
        } else {
            self::$log->debug('DOCX is a template.');
            self::$log->info(
                'Create a temp copy of the file, to generate a new DOCX.'
            );
            $finalFileName = $fileName . '.' . $this->_extension;
            $fileName = tempnam($this->_tempDir, $fileName);
            copy(CreateTemplate::$path, $fileName);
            $zipDocxTemplate = new ZipArchive();
            try {
                if ($zipDocxTemplate->open($fileName)) {
                    if (count(CreateTemplate::getFooter()) > 0) {
                        $footers = CreateTemplate::getFooter();
                        $i = 1;
                        foreach ($footers as $footer) {
                            self::$log->info('Footer exists, replace word/footer' . $i . '.xml with a new footer.');
                            $zipDocxTemplate->addFromString('word/footer' . $i . '.xml', $footer);
                            $i++;
                        }
                    }
                    if (count(CreateTemplate::getHeader()) > 0) {
                        $headers = CreateTemplate::getHeader();
                        $i = 1;
                        foreach ($headers as $header) {
                            self::$log->info('Footer exists, replace word/header' . $i . '.xml with a new header.');
                            $zipDocxTemplate->addFromString('word/header' . $i . '.xml', $header);
                            $i++;
                        }
                    }
                    if (CreateTemplate::getRelsDocumentXMLRels() != '') {
                        self::$log->info(
                            'Document.xml.rels exists, replace word/_rels/' .
                            'document.xml.rels with a new document.'
                        );
                        $zipDocxTemplate->addFromString(
                            'word/_rels/document.xml.rels',
                            CreateTemplate::getRelsDocumentXMLRels()
                        );
                    }
                    if (count(CreateTemplate::$placeholderImages) > 0) {
                        self::$log->info(
                            'There is one or more images as placeholders, . ' .
                            'replace them.'
                        );
                        CreateTemplate::replaceImages($zipDocxTemplate);
                    }
                    if (CreateTemplate::$totalTemplateCharts > 0) {
                        self::$log->info(
                            'There is one or more charts as placeholders, . ' .
                            'replace them.'
                        );
                        for ($i = CreateTemplate::$ridInitTemplateCharts + 1;
                            $i <= self::$intIdWord; $i++
                        ) {
                            $zipDocxTemplate->addFromString(
                                'word/charts/chart' . $i . '.xml',
                                $this->graphicTemplate['arrChartXML'][$i]
                            );
                            CreateTemplate::replaceVariableChart(
                                $this->graphicTemplate['arrGraphics'][$i],
                                $i
                            );
                            $zipDocxTemplate->addFile(
                                $this->_tempFileXLSX[$i],
                                $this->fileGraphicTemplate['datos' . $i . '.xlsx']
                            );
                            $zipDocxTemplate->addFromString(
                                'word/charts/_rels/chart' . $i . '.xml.rels',
                                $this->fileGraphicTemplate['word/charts/_rels/chart' . $i . '.xml.rels']
                            );

                            CreateTemplate::addContentTypes(
                                $this->graphicTemplate['arrGenerateOVERRIDE'][$i]
                            );
                            CreateTemplate::addContentTypes(
                                $this->graphicTemplate['arrGenerateDEFAULT'][$i]
                            );
                            CreateTemplate::addRelationship(
                                $this->graphicTemplate['arrRelationships'][$i]
                            );
                        }

                    }
                    self::$log->info(
                        'Replace [Content_Types].xml with a new document.'
                    );
                    $zipDocxTemplate->addFromString(
                        '[Content_Types].xml',
                        CreateTemplate::getContentTypes()
                    );
                    self::$log->info(
                        'Replace word/_rels/document.xml.rels with a new ' .
                        'document.'
                    );
                    $zipDocxTemplate->addFromString(
                        'word/_rels/document.xml.rels',
                        CreateTemplate::getRelsDocumentXMLRels()
                    );
                    self::$log->info(
                        'Replace word/document.xml with a new document.'
                    );
                    if (self::$_encodeUTF) {
                        $zipDocxTemplate->addFromString(
                            'word/document.xml',
                            utf8_encode(CreateTemplate::getDocument())
                        );
                    } else {
                        $zipDocxTemplate->addFromString(
                            'word/document.xml', CreateTemplate::getDocument()
                        );
                    }
                    self::$log->info(
                        'Add embedded files.'
                    );
                    foreach (CreateTemplate::$embedFiles as $files) {
                        if (isset($files['src_string'])) {
                            $zipDocxTemplate->addFromString(
                                'word/' . $files['dest_file'], $files['src_string']
                            );
                        } elseif (isset($files['src_file'])) {
                            $zipDocxTemplate->addFile($files['src_file'], 'word/' . $files['dest_file']);
                        }
                    }
                    self::$log->info('End of file, close it.');
                    $zipDocxTemplate->close();
                    copy($fileName, $finalFileName);
                } else {
                    throw new Exception('Unable to create DOCX file.');
                }
                CreateTemplate::reset();
            }
            catch (Exception $e) {
                self::$log->fatal($e->getMessage());
                exit();
            }
        }
    }

    /**
     * Generate and download a new DOCX file
     *
     * @access public
     * @param string $args[0] Name of file
     * @param string $args[1] Page style
     *  Values: 'bottom' (4000, 4001...), 'left' (4000, 4001...),
     *  'orient' (landscape), 'right' (4000, 4001), 'titlePage' (1),
     *  'top' (4000, 4001)
     */
    public function createDocxAndDownload()
    {
        $args = func_get_args();

        try {
            $this->createDocx($args[0], $args[1]);
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            exit();
        }

        if (!empty($args[0])) {
            $fileName = $args[0];
        } else {
            $fileName = 'document';
        }

        self::$log->info(
            'Download file ' . $fileName . '.' . $this->_extension . '.'
        );
        header(
            'Content-Type: application/vnd.openxmlformats-officedocument.' .
            'wordprocessingml.document'
        );
        header(
            'Content-Disposition: attachment; filename="' . $fileName .
            '.' . $this->_extension . '"'
        );
        header('Content-Transfer-Encoding: binary');
        readfile($fileName . '.' . $this->_extension);
    }

    /**
     * Delete a block
     *
     * @access public
     * @param string $blockName Block to remove
     */
    public function deleteTemplateBlock($blockName)
    {
        self::$log->info('Delete block ' . $blockName . '.');
        CreateTemplate::deleteBlock($blockName);
    }

    /**
     * Disable debug mode
     *
     * @access public
     * @deprecated
     */
    public function disableDebug()
    {
        self::$log->info('Disable debug.');
        $this->_debug->disableDebug();
    }

    /**
     * Enable debug mode
     *
     * @access public
     * @deprecated
     */
    public function enableDebug()
    {
        self::$log->info('Enable debug.');
        $this->_debug->enableDebug();
    }

    /**
     * Merge WordML into a DOCX. WordML is added at the end of the document
     *
     * @access public
     * @param string $path Path to DOCX file
     * @param string $newXML WordML to add
     */
    public function mergeDOCX($path, $newXML)
    {
        $template = CreateTemplate::getInstance();
        self::$log->info('Merge DOCX file.');
        $template->mergeFiles($path, $newXML);
    }

    /**
     * Read DOCX file and extract WordML content
     *
     * @access public
     * @param string $path Path to DOCX file
     * @return Document.xml w:body content
     */
    public function readDOCX($path)
    {
        $parser = Parser::getInstance();
        try {
            $parser->readFile($path);
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            throw new Exception('File does not exist');
        }
        self::$log->info('Read DOCX file.');
        return (String)$parser;
    }

    /**
     * Change the default font
     *
     * @access public
     * @param string $font The new font
     *  Values: 'Arial', 'Times New Roman'...
     */
    public function setDefaultFont($font)
    {
        self::$log->info('Change default font.');
        $this->_defaultFont = $font;
    }

    /**
     * Transform to UTF-8 charset
     *
     * @access public
     */
    public function setEncodeUTF8()
    {
        self::$_encodeUTF = 1;
    }

    /**
     * Change default language.
     * @param $lang Locale: en-US, es-ES...
     * @access public
     */
    public function setLanguage($lang = 'en-US')
    {
        $this->_language = $lang;
    }

    /**
     * Mark the document as final
     *
     * @access public
     */
    public function setMarkAsFinal()
    {
        $this->_markAsFinal = 1;
        $this->generateOVERRIDE(
            '/docProps/custom.xml',
            'application/vnd.openxmlformats-officedocument.' .
            'custom-properties+xml'
        );
    }

    /**
     * Set the symbol surrounding varibles (placeholders)
     *
     * @access public
     * @param string $symbol The new symbol. Optional, $ as default
     */
    public function setTemplateSymbol($symbol = '$')
    {
        self::$log->info('Change template symbol.');
        CreateTemplate::setTemplateSymbol($symbol);
    }

    /**
     * Return template variables (placeholders)
     *
     * @example ../examples/easy/TemplateVariables.php
     *
     * @access public
     * @return array
     */
    public function getTemplateVariables()
    {
        $template = CreateTemplate::getInstance();
        self::$log->info(
            'Return template variables.'
        );
        return $template->returnAllVariables();
    }

    /**
     * Return the XML of the given Template
     *
     * @access public
     * @return array
     */
    public function getTemplateXML()
    {
        $templateXML = CreateXML::getInstance();
        self::$log->info(
            'Return the XML of the given Template.'
        );
        self::getTemplateVariables();
        
        $templateXML->XML();
        
        return $templateXML->getXML();
    }

    /*** End old API ***/

    /**
     * Add default endnote
     *
     * @access private
     */
    private function addDefaultEndnote()
    {
        $endnote = CreateEndnote::getInstance();
        $endnote->createInitEndnote(array('type' => 'separator'));
        $this->_wordEndnotesC .= (string) $endnote;
        $endnote = CreateEndnote::getInstance();
        $endnote->createInitEndnote(array('type' => 'continuationSeparator'));
        $this->_wordEndnotesC .= (string) $endnote;
    }

    /**
     * Add default footnote
     *
     * @access private
     */
    private function addDefaultFootnote()
    {
        $footnote = CreateFootnote::getInstance();
        $footnote->createInitFootnote(array('type' => 'separator'));
        $this->_wordFootnotesC .= (string) $footnote;
        $footnote = CreateFootnote::getInstance();
        $footnote->createInitFootnote(
            array('type' => 'continuationSeparator')
        );
        $this->_wordFootnotesC .= (string) $footnote;
    }

    /**
     * Add an image in the footer
     *
     * @param array $dats Image to add and paramaters to use
     * @return string
     */
    private function addImageFooter($dats = '')
    {
        try {
            if (isset($dats['name']) && file_exists($dats['name'])) {
                $arrAtributos = getimagesize($dats['name']);
                try {
                    if (
                        $arrAtributos['mime'] == 'image/jpg' ||
                        $arrAtributos['mime'] == 'image/jpeg' ||
                        $arrAtributos['mime'] == 'image/png' ||
                        $arrAtributos['mime'] == 'image/gif'
                    ) {
                        self::$intIdWord++;
                        self::$log->debug(
                            'New ID ' . self::$intIdWord . ' . Image footer.'
                        );
                        $img = CreateImage::getInstance();
                        $dats['rId'] = self::$intIdWord;
                        $img->createImage($dats);
                        $xmlHeaderImg = (string) $img;
                        $dir = $this->parsePath($dats['name']);
                        self::$log->info(
                            'Add image header word/media/image' . 
                            self::$intIdWord . '.' . $dir['extension'] .
                            '.xml to DOCX.'
                        );
                        $this->_zipDocx->addFile(
                            $dats['name'], 'word/media/image' . 
                            self::$intIdWord . '.' . $dir['extension']
                        );
                        $this->generateDEFAULT(
                            $dir['extension'], $arrAtributos['mime']
                        );
                        if ((string) $img != '') {
                            $this->_wordRelsFooterRelsC .=
                                $this->generateRELATIONSHIP(
                                    'rId' . self::$intIdWord, 'image',
                                    'media/image' . self::$intIdWord .
                                    '.' . $dir['extension']
                                );
                            return $xmlHeaderImg;
                        } else {
                            throw new Exception(
                                'Image format is not supported.'
                            );
                        }
                    } else {
                        throw new Exception('Image does not exist.');
                    }
                }
                catch (Exception $e) {
                    self::$log->fatal($e->getMessage());
                    exit();
                }
            }
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            exit();
        }
    }

    /**
     * Add an image in the header
     *
     * @param array $dats Image to add and paramaters to use
     * @return string
     */
    private function addImageHeader($dats = '')
    {
        try {
            if (isset($dats['name']) && file_exists($dats['name'])) {
                $attrImage = getimagesize($dats['name']);
                try {
                    if (
                        $attrImage['mime'] == 'image/jpg' ||
                        $attrImage['mime'] == 'image/jpeg' ||
                        $attrImage['mime'] == 'image/png' ||
                        $attrImage['mime'] == 'image/gif'
                    ) {
                        self::$intIdWord++;
                        self::$log->debug(
                            'New ID ' . self::$intIdWord . ' . Image header.'
                        );
                        $img = CreateImage::getInstance();
                        $dats['rId'] = self::$intIdWord;
                        $img->createImage($dats);
                        $xmlHeaderImg = (string) $img;
                        $dir = $this->parsePath($dats['name']);
                        self::$log->info(
                            'Add image header word/media/image' .
                            self::$intIdWord . '.' . 
                            $dir['extension'] . '.xml to DOCX.'
                        );
                        $this->_zipDocx->addFile(
                            $dats['name'],
                            'word/media/image' . self::$intIdWord . '.' .
                            $dir['extension']
                        );
                        $this->generateDEFAULT(
                            $dir['extension'], $attrImage['mime']
                        );
                        if ((string) $img != '') {
                            $this->_wordRelsHeaderRelsC .=
                                $this->generateRELATIONSHIP(
                                    'rId' . self::$intIdWord, 'image',
                                    'media/image' . self::$intIdWord . '.' .
                                    $dir['extension']
                                );
                            return $xmlHeaderImg;
                        } else {
                            throw new Exception(
                                'Image format is not supported.'
                            );
                        }
                    } else {
                        throw new Exception('Image does not exist.');
                    }
                }
                catch (Exception $e) {
                    self::$log->fatal($e->getMessage());
                    exit();
                }
            }
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            exit();
        }
    }

    /**
     * Add settings
     *
     * @access private
     */
    private function addSettings()
    {
        $settings = CreateSettings::getInstance();
        $settings->generateSettings();
        self::$log->info('Add settings to settings document.');
        $this->_wordSettingsC .= (string) $settings;
    }

    /**
     * Add style
     *
     * @param string lang Language
     * @access private
     */
    private function addStyle($lang = 'en-US')
    {
        $style = CreateStyle::getInstance();
        $style->createStyle($lang);
        self::$log->info('Add styles to styles document.');
        $this->_wordStylesC .= (string) $style;
    }

    /**
     * Add theme
     *
     * @access private
     */
    private function addTheme($strFont)
    {
        $theme = CreateTheme1::getInstance();
        $theme->createTheme($strFont);
        self::$log->info('Add theme to theme document.');
        $this->_wordThemeThemeC .= (string) $theme;
    }

    /**
     * Add websettings
     *
     * @access private
     */
    private function addWebSettings()
    {
        $webSettings = CreateWebSettings::getInstance();
        $webSettings->generateWebSettings();
        self::$log->info('Add web settings to web settings document.');
        $this->_wordWebSettingsC .= (string) $webSettings;
    }

    /**
     * Clean template
     *
     * @access private
     */
    private function cleanTemplate()
    {
        self::$log->debug('Remove existing template tags.');
        $this->_wordDocumentT = preg_replace(
            '/__[A-Z]+__/',
            '',
            $this->_wordDocumentT
        );
    }

    /**
     * Generate content type
     *
     * @access private
     */
    private function generateContentType()
    {
        try {
            GenerateDocx::beginDocx();
        }
        catch (Exception $e) {
            self::$log->fatal($e->getMessage());
            exit();
        }
        $this->generateDEFAULT(
            'rels', 'application/vnd.openxmlformats-package.relationships+xml'
        );
        $this->generateDEFAULT('xml', 'application/xml');
        $this->generateDEFAULT('htm', 'application/xhtml+xml');
        $this->generateDEFAULT('rtf', 'application/rtf');
        $this->generateDEFAULT('zip', 'application/vnd.openxmlformats-officedocument.wordprocessingml.document.main+xml');
        $this->generateDEFAULT('mht', 'message/rfc822');
        $this->generateDEFAULT('wml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.document.main+xml');
        $this->generateOVERRIDE(
            '/word/numbering.xml',
            'application/vnd.openxmlformats-officedocument.wordprocessingml.' .
            'numbering+xml'
        );
        $this->generateOVERRIDE(
            '/word/styles.xml',
            'application/vnd.openxmlformats-officedocument.wordprocessingml' .
            '.styles+xml'
        );
        $this->generateOVERRIDE(
            '/docProps/app.xml',
            'application/vnd.openxmlformats-officedocument.extended-' .
            'properties+xml'
        );
        $this->generateOVERRIDE(
            '/docProps/custom.xml',
            'application/vnd.openxmlformats-officedocument.' .
            'custom-properties+xml'
        );
        $this->generateOVERRIDE(
            '/word/settings.xml', 'application/' .
            'vnd.openxmlformats-officedocument.wordprocessingml.settings+xml'
        );
        $this->generateOVERRIDE(
            '/word/theme/theme1.xml',
            'application/vnd.openxmlformats-officedocument.theme+xml'
        );
        $this->generateOVERRIDE(
            '/word/fontTable.xml',
            'application/vnd.openxmlformats-officedocument.wordprocessingml.' .
            'fontTable+xml'
        );
        $this->generateOVERRIDE(
            '/word/webSettings.xml',
            'application/vnd.openxmlformats-officedocument.wordprocessingml' .
            '.webSettings+xml'
        );
        if ($this->_wordFooterC != '' || $this->_wordHeaderC != '') {
            $this->generateOVERRIDE(
                '/word/header.xml',
                'application/vnd.openxmlformats-officedocument.' .
                'wordprocessingml.header+xml'
            );
            $this->generateOVERRIDE(
                '/word/footer.xml',
                'application/vnd.openxmlformats-officedocument.' .
                'wordprocessingml.footer+xml'
            );
            $this->generateOVERRIDE(
                '/word/footnotes.xml',
                'application/vnd.openxmlformats-officedocument.' .
                'wordprocessingml.footnotes+xml'
            );
            $this->generateOVERRIDE(
                '/word/endnotes.xml',
                'application/vnd.openxmlformats-officedocument.' .
                'wordprocessingml.endnotes+xml'
            );
        }
        $this->generateOVERRIDE(
            '/docProps/core.xml',
            'application/vnd.openxmlformats-package.core-properties+xml'
        );
    }

    /**
     * Generate DEFAULT
     *
     * @access private
     */
    private function generateDEFAULT($extension, $contentType)
    {
        if (
            strpos($this->_contentTypeC, 'Extension="' . $extension)
            === false
        ) {
            $this->_contentTypeC .= '<Default Extension="' .
                $extension . '" ContentType="' . $contentType . '"> </Default>';
        }
    }

    /**
     *
     *
     * @access private
     */
    private function generateDefaultFonts()
    {
        $font = array(
            'name' => 'Calibri', 'pitch' => 'variable', 'usb0' => 'A00002EF',
            'usb1' => '4000207B', 'usb2' => '00000000', 'usb3' => '00000000',
            'csb0' => '0000009F', 'csb1' => '00000000', 'family' => 'swiss',
            'charset' => '00', 'panose1' => '020F0502020204030204'
        );
        $this->addFont($font);
        $font = array(
            'name' => 'Times New Roman', 'pitch' => 'variable',
            'usb0' => 'E0002AEF', 'usb1' => 'C0007841', 'usb2' => '00000009',
            'usb3' => '00000000', 'csb0' => '000001FF', 'csb1' => '00000000',
            'family' => 'roman', 'charset' => '00',
            'panose1' => '02020603050405020304'
        );
        $this->addFont($font);
        $font = array(
            'name' => 'Cambria', 'pitch' => 'variable', 'usb0' => 'A00002EF',
            'usb1' => '4000004B', 'usb2' => '00000000', 'usb3' => '00000000',
            'csb0' => '0000009F', 'csb1' => '00000000', 'family' => 'roman',
            'charset' => '00', 'panose1' => '02040503050406030204'
        );
        $this->addFont($font);
    }

    /**
     * Generate DefaultWordRels
     *
     * @access private
     */
    private function generateDefaultWordRels()
    {
        self::$intIdWord++;
        self::$log->debug('New ID ' . self::$intIdWord . ' . numbering.xml.');
        $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
            'rId' . self::$intIdWord, 'numbering', 'numbering.xml'
        );
        self::$intIdWord++;
        self::$log->debug(
            'New ID ' . self::$intIdWord . ' . theme/theme1.xml.'
        );
        $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
            'rId' . self::$intIdWord, 'theme', 'theme/theme1.xml'
        );
        self::$intIdWord++;
        self::$log->debug('New ID ' . self::$intIdWord . ' . numbering.xml.');
        $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
            'rId' . self::$intIdWord, 'webSettings', 'webSettings.xml'
        );
        self::$intIdWord++;
        self::$log->debug('New ID ' . self::$intIdWord . ' . webSettings.xml.');
        $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
            'rId' . self::$intIdWord, 'fontTable', 'fontTable.xml'
        );
        self::$intIdWord++;
        self::$log->debug('New ID ' . self::$intIdWord . ' . fontTable.xml.');
        $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
            'rId' . self::$intIdWord, 'settings', 'settings.xml'
        );
        self::$intIdWord++;
        self::$log->debug('New ID ' . self::$intIdWord . ' . settings.xml.');
        $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
            'rId' . self::$intIdWord, 'styles', 'styles.xml'
        );
    }

    /**
     * Generate OVERRIDE
     *
     * @access private
     * @param string $partName
     * @param string $contentType
     */
    private function generateOVERRIDE($partName, $contentType)
    {
        if (
            strpos($this->_contentTypeC, 'PartName="' . $partName . '"')
            === false
        ) {
            $this->_contentTypeC .= '<Override PartName="' .
                $partName . '" ContentType="' . $contentType . '"> </Override>';
        }
    }

    /**
     * Gnerate RELATIONSHIP
     *
     * @access private
     */
    private function generateRELATIONSHIP()
    {
        $arrArgs = func_get_args();
        if ($arrArgs[1] == 'vbaProject') {
            $type =
            'http://schemas.microsoft.com/office/2006/relationships/vbaProject';
        } else {
            $type =
            'http://schemas.openxmlformats.org/officeDocument/2006/' .
            'relationships/' . $arrArgs[1];
        }
            
        if (!isset($arrArgs[3])) {
            return '<Relationship Id="' . $arrArgs[0] . '" Type="' . $type .
               '" Target="' . $arrArgs[2] . '"></Relationship>';
        } else {
            return '<Relationship Id="' . $arrArgs[0] . '" Type="' . $type .
               '" Target="' . $arrArgs[2] . '" ' . $arrArgs[3] . '></Relationship>';
        }
    }

    /**
     * Generate SECTPR
     *
     * @access private
     * @param array $args Section style
     */
    private function generateSECTPR($args = '')
    {
        $page = CreatePage::getInstance();
        $page->createSECTPR($args);
        $this->_wordDocumentC .= (string) $page;
    }
    
    /**
     * Generate ContentType XML template
     *
     * @access private
     */
    private function generateTemplateContentType()
    {
        $this->_wordContentTypeT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>' .
            '<Types xmlns="http://schemas.openxmlformats.org/package/2006/' .
            'content-types">' . $this->_contentTypeC . '</Types>';
    }

    /**
     * Generate DocPropsApp XML template
     *
     * @access private
     */
    private function generateTemplateDocPropsApp()
    {
        $this->_docPropsAppT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' .
            '<Properties xmlns="http://schemas.openxmlformats.org/' .
            'officeDocument/2006/extended-properties" xmlns:vt="' .
            'http://schemas.openxmlformats.org/officeDocument/2006/' .
            'docPropsVTypes"><Template>Normal.dotm</Template><TotalTime>' .
            '0</TotalTime><Pages>1</Pages><Words>1</Words><Characters>1'
            . '</Characters><Application>Microsoft Office Word</Application>' .
            '<DocSecurity>4</DocSecurity><Lines>1</Lines><Paragraphs>1' .
            '</Paragraphs><ScaleCrop>false</ScaleCrop>';
    	if ($this->_docPropsAppC) {
    		$this->_docPropsAppT .= $this->_docPropsAppC;
    	} else {
    		$this->_docPropsAppT .= '<Company>Company</Company>';
    	}
        $this->_docPropsAppT .= '<LinksUpToDate>false</LinksUpToDate>' .
            '<CharactersWithSpaces>1</CharactersWithSpaces><SharedDoc>' .
            'false</SharedDoc><HyperlinksChanged>false</HyperlinksChanged>' .
            '<AppVersion>12.0000</AppVersion></Properties>';
    }

    /**
     * Generate DocPropsCore XML template
     *
     * @access private
     */
    private function generateTemplateDocPropsCore()
    {
        date_default_timezone_set('UTC');
        if ($this->_markAsFinal) {
            $this->_docPropsCoreT =
                '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' .
                '<cp:coreProperties xmlns:cp="http://schemas.openxmlformats' .
                '.org/package/2006/metadata/core-properties" ' .
                'xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:dcterms' .
                '="http://purl.org/dc/terms/" xmlns:dcmitype="http://purl' .
                '.org/dc/dcmitype/" xmlns:xsi="http://www.w3.org/2001/XML' .
                'Schema-instance"><dc:title>Title</dc:title><dc:subject>' .
                'Subject</dc:subject><dc:creator>2mdc</dc:creator>' .
                '<dc:description>Description</dc:description>' .
                '<cp:lastModifiedBy>user</cp:lastModifiedBy><cp:revision>1' .
                '</cp:revision><dcterms:created xsi:type="dcterms:W3CDTF">' .
                date('c') . '</dcterms:created><dcterms:modified ' .
                'xsi:type="dcterms:W3CDTF">' . date('c') .
                '</dcterms:modified><cp:contentStatus>Final' .
                '</cp:contentStatus></cp:coreProperties>';
        } else {
            $this->_docPropsCoreT =
                '<?xml version="1.0" encoding="UTF-8" standalone="yes"?> ' .
                '<cp:coreProperties xmlns:cp="http://schemas.openxmlformats' .
                '.org/package/2006/metadata/core-properties" ' .
                'xmlns:dc="http://purl.org/dc/elements/1.1/" ' .
                'xmlns:dcterms="http://purl.org/dc/terms/" ' .
                'xmlns:dcmitype="http://purl.org/dc/dcmitype/" ' .
                'xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">' .
                '<dc:title>Title</dc:title><dc:subject>Subject</dc:subject>' .
                '<dc:creator>2mdc</dc:creator><dc:description>Description' .
                '</dc:description><cp:lastModifiedBy>user' .
                '</cp:lastModifiedBy><cp:revision>1</cp:revision>' .
                '<dcterms:created xsi:type="dcterms:W3CDTF">' . date('c') .
                '</dcterms:created><dcterms:modified xsi:type="dcterms:W3CDTF' .
                '">' . date('c') . '</dcterms:modified></cp:coreProperties>';
        }
    }

    /**
     * Generate DocPropsCustom XML template
     *
     * @access private
     */
    private function generateTemplateDocPropsCustom()
    {
        $this->_docPropsCustomT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' .
            '<Properties xmlns="http://schemas.openxmlformats.org/' .
            'officeDocument/2006/custom-properties" xmlns:vt="http://' .
            'schemas.openxmlformats.org/officeDocument/2006/docPropsVTypes">' .
            '<property fmtid="{D5CDD505-2E9C-101B-9397-08002B2CF9AE}" ' .
            'pid="2" name="_MarkAsFinal"><vt:bool>true</vt:bool></property>' .
            '</Properties>';
    }

    /**
     * Generate RelsRels XML template
     *
     * @access private
     */
    private function generateTemplateRelsRels()
    {
        $this->_relsRelsT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' .
            '<Relationships xmlns="http://schemas.openxmlformats.org/package/' .
            '2006/relationships">' .
            $this->generateRELATIONSHIP(
                'rId3', 'extended-properties', 'docProps/app.xml'
            ) .
            '<Relationship Id="rId2" Type="http://schemas.openxmlformats' .
            '.org/package/2006/relationships/metadata/core-properties"' .
            ' Target="docProps/core.xml"/>' .
            $this->generateRELATIONSHIP(
                'rId1', 'officeDocument', 'word/document.xml'
            );
        if ($this->_markAsFinal) {
            $this->_relsRelsT .=
                '<Relationship Id="rId4" Type="http://schemas' .
                '.openxmlformats.org/officeDocument/2006/relationships/' .
                'custom-properties" Target="docProps/custom.xml"/>';
        }
        $this->_relsRelsT .= '</Relationships>';
    }

    /**
     * Generate WordDocument XML template
     *
     * @access private
     */
    private function generateTemplateWordDocument()
    {
        $arrArgs = func_get_args();
        $this->generateSECTPR($arrArgs[0]);
        if (!empty($this->_wordHeaderC)) {
            $this->_wordDocumentC = str_replace(
                '__GENERATEHEADERREFERENCE__',
                '<' . CreateDocx::NAMESPACEWORD . ':headerReference ' .
                CreateDocx::NAMESPACEWORD . ':type="default" r:id="rId' .
                $this->_idWords['header'] . '"></' .
                CreateDocx::NAMESPACEWORD . ':headerReference>',
                $this->_wordDocumentC
            );
        }
        if (!empty($this->_wordFooterC)) {
            $this->_wordDocumentC = str_replace(
                '__GENERATEFOOTERREFERENCE__',
                '<' . CreateDocx::NAMESPACEWORD . ':footerReference ' .
                CreateDocx::NAMESPACEWORD . ':type="default" r:id="rId' .
                $this->_idWords['footer'] . '"></' .
                CreateDocx::NAMESPACEWORD . ':footerReference>',
                $this->_wordDocumentC
            );
        }
        $this->_wordDocumentT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' .
            '<' . CreateDocx::NAMESPACEWORD . ':document xmlns:ve=' .
            '"http://schemas.openxmlformats.org/markup-compatibility/2006" ' .
            'xmlns:o="urn:schemas-microsoft-com:office:office"' .
            ' xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006' .
            '/relationships" xmlns:m="http://schemas.openxmlformats.org/' .
            'officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:vml"'.
            ' xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/' .
            'wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:' .
            'office:word" xmlns:w="http://schemas.openxmlformats.org/' .
            'wordprocessingml/2006/main" xmlns:wne="http://schemas' .
            '.microsoft.com/office/word/2006/wordml">' .
            '<' . CreateDocx::NAMESPACEWORD . ':body>' .
            $this->_wordDocumentC .
            '</' . CreateDocx::NAMESPACEWORD . ':body>' .
            '</' . CreateDocx::NAMESPACEWORD . ':document>';
        $this->cleanTemplate();
    }

    /**
     * Generate WordEndnotes XML template
     *
     * @access private
     */
    private function generateTemplateWordEndnotes()
    {
        $this->_wordEndnotesT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' .
            '<' . CreateDocx::NAMESPACEWORD . ':endnotes xmlns:ve' .
            '="http://schemas.openxmlformats.org/markup-compatibility/2006" ' .
            'xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:r="' .
            'http://schemas.openxmlformats.org/officeDocument/2006/' .
            'relationships" xmlns:m="http://schemas.openxmlformats.org/' .
            'officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:' .
            'vml" xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006' .
            '/wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:' .
            'office:word" xmlns:w="http://schemas.openxmlformats.org/' .
            'wordprocessingml/2006/main" xmlns:wne="http://schemas' .
            '.microsoft.com/office/word/2006/wordml">' .
            $this->_wordEndnotesC .
            '</' . CreateDocx::NAMESPACEWORD . ':endnotes>';
        self::$intIdWord++;
        self::$log->debug('New ID ' . self::$intIdWord . ' . Endnotes.');
        $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
            'rId' . self::$intIdWord, 'endnotes', 'endnotes.xml'
        );
        $this->generateOVERRIDE(
            '/word/endnotes.xml',
            'application/vnd.openxmlformats-officedocument.wordprocessingml' .
            '.endnotes+xml'
        );
    }

    /**
     * Generate WordFontTable XML template
     *
     * @access private
     */
    private function generateTemplateWordFontTable()
    {
        $this->_wordFontTableT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>' .
            '<' . CreateDocx::NAMESPACEWORD . ':fonts xmlns:r="http://' .
            'schemas.openxmlformats.org/officeDocument/2006/' .
            'relationships" xmlns:w="http://schemas.openxmlformats.org/' .
            'wordprocessingml/2006/main">' . $this->_wordFontTableC .
            '</' . CreateDocx::NAMESPACEWORD . ':fonts>';
    }

    /**
     * Generate WordFooter XML template
     *
     * @access private
     */
    private function generateTemplateWordFooter()
    {
        self::$intIdWord++;
        self::$log->debug('New ID ' . self::$intIdWord . ' . Footer.');
        $this->_idWords['footer'] = self::$intIdWord;
        $this->_wordFooterT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
            <' . CreateDocx::NAMESPACEWORD . ':ftr xmlns:ve' .
            '="http://schemas.openxmlformats.org/markup-compatibility/' .
            '2006" xmlns:o="urn:schemas-microsoft-com:office:office" xmlns' .
            ':r="http://schemas.openxmlformats.org/officeDocument/2006/' .
            'relationships" xmlns:m="http://schemas.openxmlformats.org/' .
            'officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:vml' .
            '" xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/' .
            'wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:' .
            'office:word" xmlns:w="http://schemas.openxmlformats.org/' .
            'wordprocessingml/2006/main" xmlns:wne="http://schemas' .
            '.microsoft.com/office/word/2006/wordml">' . $this->_wordFooterC .
            '</' . CreateDocx::NAMESPACEWORD . ':ftr>';
        $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
            'rId' . self::$intIdWord, 'footer', 'footer.xml'
        );
    }

    /**
     * Generate WordFootnotes XML template
     *
     * @access private
     */
    private function generateTemplateWordFootnotes()
    {
        $this->_wordFootnotesT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' .
            '<' . CreateDocx::NAMESPACEWORD . ':footnotes xmlns:ve="' .
            'http://schemas.openxmlformats.org/markup-compatibility/2006" ' .
            'xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:r="' .
            'http://schemas.openxmlformats.org/officeDocument/2006/' .
            'relationships" xmlns:m="http://schemas.openxmlformats.org/' .
            'officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:' .
            'vml" xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006' .
            '/wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:' .
            'office:word" xmlns:w="http://schemas.openxmlformats.org/' .
            'wordprocessingml/2006/main" xmlns:wne="http://schemas.microsoft' .
            '.com/office/word/2006/wordml">' . $this->_wordFootnotesC .
            '</' . CreateDocx::NAMESPACEWORD . ':footnotes>';
        self::$intIdWord++;
        self::$log->debug('New ID ' . self::$intIdWord . ' . Footnotes.');
        $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
            'rId' . self::$intIdWord, 'footnotes', 'footnotes.xml'
        );
        $this->generateOVERRIDE(
            '/word/footnotes.xml',
            'application/vnd.openxmlformats-officedocument.wordprocessingml' .
            '.footnotes+xml'
        );
    }

    /**
     * Generate WordHeader XML template
     *
     * @access private
     */
    private function generateTemplateWordHeader()
    {
        self::$intIdWord++;
        self::$log->debug('New ID ' . self::$intIdWord . ' . Header.');
        $this->_idWords['header'] = self::$intIdWord;
        $this->_wordHeaderT = '<?xml version="1.0" encoding="UTF-8" ' .
            'standalone="yes"?>' .
            '<' . CreateDocx::NAMESPACEWORD .
            ':hdr xmlns:ve="http://schemas.openxmlformats.org/markup' .
            '-compatibility/2006" xmlns:o="urn:schemas-microsoft-com:' .
            'office:office" xmlns:r="http://schemas.openxmlformats.org/' .
            'officeDocument/2006/relationships" xmlns:m="http://schemas' .
            '.openxmlformats.org/officeDocument/2006/math" xmlns:v="urn:' .
            'schemas-microsoft-com:vml" xmlns:wp="http://schemas' .
            '.openxmlformats.org/drawingml/2006/wordprocessingDrawing" ' .
            'xmlns:w10="urn:schemas-microsoft-com:office:word" xmlns:w="' .
            'http://schemas.openxmlformats.org/wordprocessingml/2006/' .
            'main" xmlns:wne="http://schemas.microsoft.com/office/word/' .
            '2006/wordml"> ' . $this->_wordHeaderC .
            '</' . CreateDocx::NAMESPACEWORD . ':hdr>';
        $this->_wordRelsDocumentRelsC .= $this->generateRELATIONSHIP(
            'rId' . self::$intIdWord, 'header', 'header.xml'
        );
    }

    /**
     * Generate WordNumbering XML template
     *
     * @access private
     */
    private function generateTemplateWordNumbering()
    {
        $this->_wordNumberingT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' .
            '<w:numbering xmlns:ve="http://schemas.openxmlformats' .
            '.org/markup-compatibility/2006" xmlns:o="urn:schemas-' .
            'microsoft-com:office:office" xmlns:r="http://schemas' .
            '.openxmlformats.org/officeDocument/2006/relationships" ' .
            'xmlns:m="http://schemas.openxmlformats.org/officeDocument/' .
            '2006/math" xmlns:v="urn:schemas-microsoft-com:vml" xmlns:' .
            'wp="http://schemas.openxmlformats.org/drawingml/2006/' .
            'wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com' .
            ':office:word" xmlns:w="http://schemas.openxmlformats.org/' .
            'wordprocessingml/2006/main" xmlns:wne="http://schemas.' .
            'microsoft.com/office/word/2006/wordml"><w:abstractNum w:'
            . 'abstractNumId="0"><w:nsid w:val="713727AE"/><w:multiLevelType' .
            ' w:val="hybridMultilevel"/><w:tmpl w:val="F0B4B6B8"/>' .
            '<w:lvl w:ilvl="0" w:tplc="0C0A0001"><w:start w:val="1"/>' .
            '<w:numFmt w:val="bullet"/><w:lvlText w:val="ï‚·"/><w:lvlJc ' .
            'w:val="left"/><w:pPr><w:ind w:left="720" w:hanging="360"/>' .
            '</w:pPr><w:rPr><w:rFonts w:ascii="Symbol" w:hAnsi="Symbol" ' .
            'w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="1" ' .
            'w:tplc="0C0A0003" w:tentative="1"><w:start w:val="1"/>' .
            '<w:numFmt w:val="bullet"/><w:lvlText w:val="o"/><w:lvlJc ' .
            'w:val="left"/><w:pPr><w:ind w:left="1440" w:hanging="360"/>' . '
                </w:pPr><w:rPr><w:rFonts w:ascii="Courier New" w:hAnsi=' .
            '"Courier New" w:cs="Courier New" w:hint="default"/></w:rPr>' .
            '</w:lvl><w:lvl w:ilvl="2" w:tplc="0C0A0005" w:tentative="1">' .
            '<w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText ' .
            'w:val="ï‚§"/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="2160" ' .
            'w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Wingdings" ' .
            'w:hAnsi="Wingdings" w:hint="default"/></w:rPr></w:lvl><w:lvl ' .
            'w:ilvl="3" w:tplc="0C0A0001" w:tentative="1"><w:start ' .
            'w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val="ï‚·"/>' .
            '<w:lvlJc w:val="left"/><w:pPr><w:ind w:left="2880" w:hanging=' .
            '"360"/></w:pPr><w:rPr><w:rFonts w:ascii="Symbol" w:hAnsi=' .
            '"Symbol" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="4" ' .
            'w:tplc="0C0A0003" w:tentative="1"><w:start w:val="1"/>' .
            '<w:numFmt w:val="bullet"/><w:lvlText w:val="o"/><w:lvlJc ' .
            'w:val="left"/><w:pPr><w:ind w:left="3600" w:hanging="360"/>' .
            '</w:pPr><w:rPr><w:rFonts w:ascii="Courier New" w:hAnsi=' .
            '"Courier New" w:cs="Courier New" w:hint="default"/></w:rPr>' .
            '</w:lvl><w:lvl w:ilvl="5" w:tplc="0C0A0005" w:tentative="1">' .
            '<w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText ' .
            'w:val="ï‚§"/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="4320" ' .
            'w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Wingdings" ' .
            'w:hAnsi="Wingdings" w:hint="default"/></w:rPr></w:lvl><w:lvl ' .
            'w:ilvl="6" w:tplc="0C0A0001" w:tentative="1"><w:start ' .
            'w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val="ï‚·"/>' .
            '<w:lvlJc w:val="left"/><w:pPr><w:ind w:left="5040" ' .
            'w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Symbol" ' .
            'w:hAnsi="Symbol" w:hint="default"/></w:rPr></w:lvl><w:lvl ' .
            'w:ilvl="7" w:tplc="0C0A0003" w:tentative="1"><w:start ' .
            'w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val="o"/>' .
            '<w:lvlJc w:val="left"/><w:pPr><w:ind w:left="5760" ' .
            'w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Courier New" ' .
            'w:hAnsi="Courier New" w:cs="Courier New" w:hint="default"/>' .
            '</w:rPr></w:lvl><w:lvl w:ilvl="8" w:tplc="0C0A0005" ' .
            'w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"' .
            '/><w:lvlText w:val="ï‚§"/><w:lvlJc w:val="left"/><w:pPr><w:ind ' .
            'w:left="6480" w:hanging="360"/></w:pPr><w:rPr><w:rFonts ' .
            'w:ascii="Wingdings" w:hAnsi="Wingdings" w:hint="default"/>' .
            '</w:rPr></w:lvl></w:abstractNum><w:num w:numId="1">' .
            '<w:abstractNumId w:val="0"/></w:num></w:numbering>';
    }

    /**
     * Generate WordNumbering XML template
     *
     * @access private
     */
    private function generateTemplateWordNumberingStyles()
    {
        $this->_wordNumberingT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' .
            '<w:numbering xmlns:ve="http://schemas.openxmlformats' .
            '.org/markup-compatibility/2006" xmlns:o="urn:schemas-' .
            'microsoft-com:office:office" xmlns:r="http://schemas' .
            '.openxmlformats.org/officeDocument/2006/relationships" ' .
            'xmlns:m="http://schemas.openxmlformats.org/officeDocument/' .
            '2006/math" xmlns:v="urn:schemas-microsoft-com:vml" xmlns:' .
            'wp="http://schemas.openxmlformats.org/drawingml/2006/' .
            'wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com' .
            ':office:word" xmlns:w="http://schemas.openxmlformats.org/' .
            'wordprocessingml/2006/main" xmlns:wne="http://schemas.' .
            'microsoft.com/office/word/2006/wordml"><w:abstractNum w:'
            . 'abstractNumId="0"><w:nsid w:val="713727AE"/><w:multiLevelType' .
            ' w:val="hybridMultilevel"/><w:tmpl w:val="F0B4B6B8"/>' .
            $this->_wordDocumentStyles . '</w:abstractNum><w:num w:numId="1">' .
            '<w:abstractNumId w:val="0"/></w:num></w:numbering>';
    }

    /**
     * Generate WordRelsDocumentRels XML template
     *
     * @access private
     */
    private function generateTemplateWordRelsDocumentRels()
    {
        $this->_wordRelsDocumentRelsT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' .
            '<Relationships xmlns="http://schemas.openxmlformats.org/' .
            'package/2006/relationships">' . $this->_wordRelsDocumentRelsC .
            '</Relationships>';
    }

    /**
     * Generate WordRelsFooterRels XML template
     *
     * @access private
     */
    private function generateTemplateWordRelsFooterRels()
    {
        $this->_wordRelsFooterRelsT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' .
            '<Relationships xmlns="http://schemas.openxmlformats.org/' .
            'package/2006/relationships">' . $this->_wordRelsFooterRelsC .
            '</Relationships>';
    }

    /**
     * Generate WordRelsHeaderRels XML template
     *
     * @access private
     */
    private function generateTemplateWordRelsHeaderRels()
    {
        $this->_wordRelsHeaderRelsT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' .
            '<Relationships xmlns="http://schemas.openxmlformats.org/' .
            'package/2006/relationships">' . $this->_wordRelsHeaderRelsC .
            '</Relationships>';
    }

    /**
     * Generate WordSettings XML template
     *
     * @access private
     */
    private function generateTemplateWordSettings()
    {
        $this->_wordSettingsT = $this->_wordSettingsC;
    }

    /**
     * Generate WordStyles XML template
     *
     * @access private
     */
    private function generateTemplateWordStyles()
    {
        $this->_wordStylesT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?><' .
            CreateDocx::NAMESPACEWORD . ':styles xmlns:r="http://' .
            'schemas.openxmlformats.org/officeDocument/2006/relationships' .
            '" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/' .
            '2006/main">' . $this->_wordStylesC .
            '</' . CreateDocx::NAMESPACEWORD . ':styles>';
    }

    /**
     * Generate WordThemeTheme1 XML template
     *
     * @access private
     */
    private function generateTemplateWordThemeTheme1()
    {
        $this->addTheme($this->_defaultFont);
        $this->_wordThemeThemeT =
            '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?><' .
            CreateTheme1::NAMESPACEWORD . ':theme xmlns:a="http://' .
            'schemas.openxmlformats.org/drawingml/2006/main" name="' .
            'Tema de Office">' . $this->_wordThemeThemeC .
            '</' . CreateTheme1::NAMESPACEWORD . ':theme>';
    }

    /**
     * Generate WordWebSettings XML template
     *
     * @access private
     */
    private function generateTemplateWordWebSettings()
    {
        $this->_wordWebSettingsT = $this->_wordWebSettingsC;
    }
    
    /**
     * To add support of sys_get_temp_dir for PHP versions under 5.2.1
     * 
     * @access private
     * @return string
     */
	private function getTempDir() {
		if ( !function_exists('sys_get_temp_dir')) {
			function sys_get_temp_dir() {
				if ($temp = getenv('TMP')) {
					return $temp;
				}
				if ($temp = getenv('TEMP')) {
					return $temp;
				}
				if ($temp = getenv('TMPDIR')) {
					return $temp;
				}
				$temp = tempnam(__FILE__,'');
				if (file_exists($temp)) {
					unlink($temp);
					return dirname($temp);
				}
				return null;
			}
		} else {
			return sys_get_temp_dir();
		}
	}

    /**
     * Parse path dir
     *
     * @access private
     * @param string $dir Directory path
     */
    private function parsePath($dir)
    {
        $slash = 0;
        $path = '';
        if (($slash = strrpos($dir, '/')) !== false) {
            $slash += 1;
            $path = substr($dir, 0, $slash);
        }
        $punto = strpos(substr($dir, $slash), '.');

        $nombre = substr($dir, $slash, $punto);
        $extension = substr($dir, $punto + $slash + 1);
        return array(
            'path' => $path, 'nombre' => $nombre, 'extension' => $extension
        );
    }

}