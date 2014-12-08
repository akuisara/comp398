$(document).ready(function() {

	// gets connections.json data, creates new div with classes for each connection on success
	$.ajax(
	{      
  		type: 'GET',
		url: 'data/connections.json',
		data: "{}",
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		async: false,
		success: function (data) {
			
			var connections = data["ConnectionDescriptions"];
			var i = 1;

			$.each(connections, function() {

				var Description = this["CourseDescription"];
				var Name = this["CourseName"];
				var Three = String(this["Three"]);
				var Natural = this["Natural"];
				var Social = this["Social"];
				var Humanities = this["Humanities"];
				var QA = this["QA"];

				var end = Description.length - 43;

				currentText = $("#jsonfill").html();

				$("#jsonfill").html(currentText + "<div id='con" + i + "' <br><h3>" + Name + "</h3><p>" + Description.substring(0, end) + "</p></div>");
								
				var newdiv = "#con" + i

				$(newdiv).addClass("connection");

				if (Three == "True") {
					$(newdiv).addClass("three");
				};
				if (Natural == "True") {
					$(newdiv).addClass("natural");
				};
				if (Social == "True") {
					$(newdiv).addClass("social");
				};
				if (Humanities == "True") {
					$(newdiv).addClass("humanities");
				};
				if (QA == "True") {
					$(newdiv).addClass("qa");
				};

				$(newdiv).hide();

				i = i + 1;
			});

		},
		error: function(xhr, status) {
		alert("hatada:" + xhr.responseXML);
  		}
	}); 
	
	// hides or shows each connection based on changes in the form 
	$('.uk-form').change(function(){

		$('.connection').each(function() {
			var two = false;
			var three = false;
			var coursecount = false;
			var division = false;

			if ($('#2course').is(":checked")) {
				two = true;
			}
			if ($('#3course').is(":checked")) {
				three = true;
			}

			if ($(this).hasClass('three') && three) {
				coursecount = true;
				two = false;
			} 

			if ( ($('#natsci').is(":checked") && $(this).hasClass('natural')) 
				|| ($('#socsci').is(":checked") && $(this).hasClass('social')) 
				|| ($('#hum').is(":checked") && $(this).hasClass('humanities')) 
				|| ($('#qa').is(":checked") && $(this).hasClass('qa')) ) {
				division = true;
			}
			
			if ((coursecount || two) && division) {
				$(this).show();
			}
			else {
				$(this).hide();
			}
		});

  	});
  
});

