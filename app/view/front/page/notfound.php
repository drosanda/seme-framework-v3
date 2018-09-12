<!DOCTYPE html>
<html lang="en">
<?php $this->getThemeElement("page/html/head",$__forward); ?>
<?php $this->getBodyBefore(); ?>
<body class="">
  <div class="off-canvas-wrapper" style="background-color: #000;">
    <div class="off-canvas-wrapper-inner" data-off-canvas-wrapper>

      <!-- offcanvas-left -->
      <?php $this->getThemeElement("page/html/offcanvas-left",$__forward); ?>
      <!-- end offcanvas-left -->

      <!-- offcanvas-right -->
      <?php $this->getThemeElement("page/html/offcanvas-right",$__forward); ?>
      <!-- end offcanvas-right -->

      <div class="off-canvas-content" data-off-canvas-content>
        <!-- main content -->

        <!-- top -->
        <?php $this->getThemeElement("page/html/top",$__forward); ?>
        <!-- end top -->

        <!-- menu topbar -->
        <?php $this->getThemeElement("page/html/menu",$__forward); ?>
        <!-- end menu topbar -->
        <div class="text-center" style="padding-top: 1vh;padding-bottom: 10vh;">
          <h1 style="font-size: 14em; font-weight: 100; padding-bottom:0; margin-bottom: 0;">404</h1>
          <p>The page you request currently unavailable or underconstruction.</p>
        </div>

        <!-- end of main content -->

        <!--footer-->
        <?php $this->getThemeElement('page/html/foot',$__forward); ?>
        <!--end footer-->

        <!--of canvas close tag  inner -->
      </div>
    </div>
  </div>
  <?php $this->getJsFooter(); ?>

  <script>
  $(document).ready(function(e){
    <?php $this->getJsReady(); ?>
    <?php $this->getJsContent(); ?>
  });
  </script>
</body>
</html>
