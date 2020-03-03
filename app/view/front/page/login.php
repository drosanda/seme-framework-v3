<?php
//Example 1 column layout
?>
<!DOCTYPE html>
<html lang="en">
<?php $this->getThemeElement("page/html/head",$__forward); ?>
<?php $this->getBodyBefore(); ?>
<body class="">
  <?php $this->getThemeElement("page/html/topbar",$__forward); ?>
  <div class="container" style="background-image: url('<?=base_url('media/sliders/weding.jpg')?>');">
    <?php $this->getThemeContent(); ?>
  </div>
  <!-- load JS in footer-->
  <?php $this->getJsFooter(); ?>
  <!-- End load JS in footer-->

  <!-- default JS Script-->
  <?php $this->getThemeElement("page/html/footer",$__forward); ?>
  <?php $this->getThemeElement("page/html/autorefresh",$__forward); ?>
  <script>
  $(document).ready(function(e){
    <?php $this->getJsReady(); ?>
    <?php $this->getJsContent(); ?>
  });
  </script>
  <!-- default JS Script-->
</body>
</html>
