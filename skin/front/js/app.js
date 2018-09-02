
$(document).ready(function(){
  $(document).foundation();
  $("#acartbuttonx").on("click tap",function(e){
    e.preventDefault();
    console.log("Open Cart Canvas");
    $("#offCanvasRight").foundation("open");

  });
  setTimeout(function(){
    $("#modalPromotion").foundation("open");
  }, 4000);
});
