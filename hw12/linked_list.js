console.log("Linked List");

function Node() {
	state = null;
	abbr = null;
	next = null;
}

function LinkedList() {
	head = null;
	tail = null;
	size = 0;
}

function Populate(state, abbr) {
	var newNode = new Node();
	newNode.state = state;
	newNode.abbr = abbr;
	tail = newNode;

	if (head === null) {
		head = newNode;
	}else {
		head.next = newNode;
	}
	size++;
}

function Driver(){
	var list = new LinkedList();

	var fs = require('fs');
	var path = require('path');

	fs.readFile("states.csv", {encoding: 'utf-8'}, function(err,data){
		data=data.split(/\n+/);
		var stateName = [], abbrName = [];

		for (var i = data.length - 1; i >= 0; i--) {
			stateName = data[i].split(/\"\,\"+/);
		}

		if (!err){
			console.log(stateName);
		}else{
			console.log(err);
		}

	});
}

Driver();