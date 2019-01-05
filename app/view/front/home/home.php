<?php
if(!isset($page_current)) $page_current = '';
?>

<h1>Thank you for using SEME Framework</h1>
<p>Seme Framework PHP MVC Framework for creating small and medium app that needed for fast delivery. At first version of Seme Framework used for building API (Middle Ware) for another Application such as android, iOS, etc. And now as increasing of requirement, Seme Framework has expand the limit for creating Small and Medium App.</p>
<pre><?=$example?></pre>
<hr />
<ul class="nav nav-pills">
  <li role="presentation" class="<?php if($page_current == 'col-1') echo 'active';?>">
    <a href="<?=base_url()?>">Example 1 Column</a>
  </li>
  <li role="presentation" class="<?php if($page_current == 'col-2-left') echo 'active';?>">
    <a href="<?=base_url("example/col_2_left")?>">Example 2 Column Left Sidebar</a>
  </li>
  <li role="presentation" class="<?php if($page_current == 'col-2-right') echo 'active';?>">
    <a href="<?=base_url("example/col_2_right")?>">Example 2 Column Right Sidebar</a>
  </li>
  <li role="presentation" class="<?php if($page_current == 'col-3') echo 'active';?>">
    <a href="<?=base_url("example/col_3")?>">Example 3 Column</a>
  </li>
</ul>
