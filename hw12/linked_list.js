console.log("Linked List");

function Node(string1,string2) {
	this.state = string1;
	this.abbreviation = string2;
	this.next = null;
}

var LinkedList = function() {
	this.head = null;
	this.tail = null;
	this.num = 0;
};

LinkedList.prototype.Populate = function() {
	var fs = require('fs');

	fs.readFile("states.csv", {encoding: 'utf-8'}, function(err,data){
		data=data.split(/\n+/);
		var stateName = [], abbreviationName = [];

		for (var i = 0; i < data.length - 1; i++) {
			var string1 = "";
			for (var j = 0; j < data[i].length - 5; j++) {
				string1+= data[i][j];
			}
			stateName[i] = string1;
			var string2 = "";
			for (var k = (data[i].length - 4); k < data[i].length; k++) {
				string2+= data[i][k];
			}
			abbreviationName[i] = string2;

			var newNode = new Node(string1,string2);

			if (this.head === null){
				this.head = newNode;
				this.tail = newNode;
			}
			else {
				this.head.next = newNode;
				this.tail = newNode;
			}

			this.num++;

			if (err){
				console.log(err);
			}
		}
	});
};

LinkedList.prototype.Search = function() {
	var value = prompt("Please enter a state name or an abbreviation: (For example: Massachusetts or MA)");
	temp = this.head;
	while(temp !== null) {
		if(temp.state == value || temp.abbreviation == value){
			console.log("Find the record: "+temp.state+" "+temp.abbreviation);
			break;
		}
		temp = temp.next;
	}
};

LinkedList.prototype.DisplayContent = function() {
	var fs = require('fs');
	var outputFile = fs.open("Output.txt", 3);
	
};

function Driver(){
	var list = new LinkedList();

	list.Populate();

	// list.Search();

	list.DisplayContent();

}

Driver();