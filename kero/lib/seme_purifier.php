<?php
class Seme_Purifier {
	var $restricted;
	var $replacer;
	public function __construct(){
		$this->replacer = ' ';
		
		$this->restricted = array();
		$this->restricted[] = '<?';
		$this->restricted[] = '<?php';
		$this->restricted[] = '<script';
		$this->restricted[] = '</script>';
		$this->restricted[] = '?>';
		
	}
	private function createPatterns(){
		foreach($this->restricted as &$v){
			$v = '/'.$v.'/i';
		}
		unset($v);
	}
	public function exec($str){
		$this->createPatterns();
		//preg_replace($this->restricted, $this->replacer, $str); 
		preg_replace_callback("/(&#[0-9]+;)/", function($str) { return mb_convert_encoding($str[1], "UTF-8", "HTML-ENTITIES"); }, $str);
		//print_r($this->restricted);
		//die();
		return $str;
	}
	public function quoteEscape($data, $addSlashes = false){
		if ($addSlashes === true) {
			$data = addslashes($data);
		}
		return htmlspecialchars($data, ENT_QUOTES, null, false);
	}
	public function escapeHtml($data, $allowedTags = null){
		if (is_array($data)) {
			$result = array();
			foreach ($data as $item) {
				$result[] = $this->escapeHtml($item);
			}
		} else {
			// process single item
			if (strlen($data)) {
				if (is_array($allowedTags) and !empty($allowedTags)) {
					$allowed = implode('|', $allowedTags);
					$result = preg_replace('/<([\/\s\r\n]*)(' . $allowed . ')([\/\s\r\n]*)>/si', '##$1$2$3##', $data);
					$result = htmlspecialchars($result, ENT_COMPAT, 'UTF-8', false);
					$result = preg_replace('/##([\/\s\r\n]*)(' . $allowed . ')([\/\s\r\n]*)##/si', '<$1$2$3>', $result);
				} else {
					$result = htmlspecialchars($data, ENT_COMPAT, 'UTF-8', false);
				}
			} else {
				$result = $data;
			}
		}
		return $result;
	}
}