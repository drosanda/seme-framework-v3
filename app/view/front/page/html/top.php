<!-- button mobile -->
<div class="title-bar title-bar-transparent show-for-small-only">
  <div class="title-bar-left">
    <a href="#" data-open="offCanvasLeft" class="buttonbar" style="">
      <i class="fa fa-list"></i>&nbsp;
    </a>
  </div>
  <div class="title-bar-right">
    <a href="#" data-open="offCanvasRight" class="buttonbar" style="">
      <i class="fa fa-shopping-cart"></i>&nbsp;
    </a>
  </div>
</div>
<div class="row sticky-bottom show-for-small-only">
  <div class="columns small-6">
    <button href="#" data-open="offCanvasLeft" class="button hollow expanded sticky-button" style="">
      <i class="fa fa-list"></i>&nbsp;
    </button>
  </div>
  <div class="columns small-6">
    <button href="#" data-open="offCanvasRight" class="button hollow  expanded sticky-button" style="">
      <i class="fa fa-shopping-cart"></i>&nbsp;
    </button>
  </div>
</div>
<!-- end button mobile -->

<!--top bar menu links -->
<?php $this->getThemeElement('page/html/top_bar',$__forward); ?>
<!-- end top bar menu links -->

<div class="row">
  <div class="columns large-4 medium-5 hide-for-small-only pt10" >
    <div class="row">
      <div class="columns large-3 medium-4">
        <a href="#" class="button hollow secondary" data-open="offCanvasLeft">
          <i class="fa fa-list"></i>
        </a>
      </div>
      <div class="columns large-9 medium-8">
        <div class="input-group">
          <input class="input-group-field" type="text" />
          <div class="input-group-button">
            <a href="#" class="button">
              <i class="fa fa-search"></i>
            </a>
          </div>
        </div>
      </div>
    </div>
  </div>
  <div class="columns large-2 large-offset-1 medium-2 text-center pt05">
    <a href="<?=base_url()?>" title="">
      <img src="<?=base_url()?>skin/front/images/logo.png" style="width: 7em;" alt="Dr Vice Logo" />
    </a>
  </div>
  <!-- top cart -->
  <div class="columns large-5 medium-5 pt10">
    <div class="row text-right">
      <div class="columns hide-for-small-only">
        <div class="row">
          <div class="columns large-offset-4  large-3 medium-4 small-6 end">
            <a href="#" class="hollow button secondary expanded" data-toggle="user-menu-dropdown">
              <i class="fa fa-user"></i>&nbsp;&nbsp;
              <i class="fa fa-chevron-down"></i>
            </a>
            <div class="dropdown-pane bottom" id="user-menu-dropdown" data-dropdown data-hover="true" data-hover-pane="true">
              <ul class="menu vertical user" style="text-align: left;">
                <li><a href="#">Login</a></li>
                <li><a href="#">Register</a></li>
              </ul>
             </div>
          </div>
          <div class="columns large-4 medium-8 small-6 end">
            <a id="acartbutton" href="#" class="hollow button expanded" style=""  data-open="offCanvasRight">
              <i class="fa fa-shopping-cart"></i> CART
              <i class="fa fa-chevron-right"></i>
            </a>
          </div>
        </div>
      </div>
      <div class="columns show-for-small-only">

        <div class="input-group">
          <input class="input-group-field" type="text" />
          <div class="input-group-button">
            <a href="#" class="button">
              <i class="fa fa-search"></i>
            </a>
          </div>
        </div>

      </div>
    </div>
  </div>
  <!-- end top cart -->
</div>
