console.log("Linked List");

function Node(string1, string2) {
	this.state = string1;
	this.abbreviation = string2;
	this.next = null;
}

var LinkedList = function() {
	this.head = null;
	this.tail = null;
	this.num = 0;
};

LinkedList.prototype.Append = function(string1, string2) {
	if (this.head === null){
		this.head = new Node(string1, string2);
		this.tail = this.head;
	}
	else {
		this.tail.next = new Node(string1, string2);
		this.tail = this.tail.next;
	}
	this.num++;
};

LinkedList.prototype.Populate = function() {
	var fs = require('fs');

	var data = fs.readFileSync("states.csv").toString().split("\n");

	var stateName = [];
	var abbreviationName = [];


	for (var i = 1; i < data.length; i++) {
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

		this.Append(string1, string2);
	}
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

LinkedList.prototype.DisplayContent = function(list) {

	var fs = require('fs');

	var p = this.head;

	var string;

	while(p !== null) {
		console.log(p);
		string += JSON.stringify(p);
		p = p.next;
	}

	fs.writeFile("output.txt", string.split("\\"), function(err) {
		if(err) {
			console.log(err);
		} else {
			console.log("The file was saved!");
		}
	});
	
};

function Driver(){

	var list = new LinkedList();

	list.Populate();

	// list.Search();

	list.DisplayContent(list);
}

Driver();