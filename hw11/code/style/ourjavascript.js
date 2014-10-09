$(document).ready(function() {
  $('.connectiondescriptions').hide();
  
  $('#selectionform').change(function(){
    $('.connectiondescriptions').hide();
  	$('.onesWEWANT').show();
  });
  
});