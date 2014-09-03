// class linklist: construct a linklist that can add nodes, read from a file, search and display
// programmer: Yingying Wu
// dates: 9/2/2014 adapt according to google style guide

#include "stdafx.h"
#include "linklist.h"
#include <iostream>
#include "node.h"

using namespace std;

linklist::linklist(){
	this->head = new node;
	head->next = 0;
	tail = head;
}
//CTOR

void linklist::AddNode(node a){
	tail->next = &a;
	tail = tail->next;
}
//ADD

void linklist::PopulateList(string in_file){

	ifstream fin;
	fin.clear();
	fin.open(in_file.c_str());		// try to open the file	
	if (fin.fail())				// but did the attempt fail?
	{

		cout << "ERROR: file called " << inFile << " did NOT open." << endl;
		exit(-1);
	} // if

	string line;
	
	while (fin){
		node *add = new node;
		getline(fin, add->representative, ',');
		getline(fin, add->year, ',');
		//getline(fin, add->party, ',');
		add->next = 0;
		this->addNode(*add);
	}
	fin.close();
	cout << "I don't know why this is not working.. At least it works until this point(the end of populate function).";
}
// can work line by line, but can't finish the whole function. Don't know why.

node* linklist::Search(string item){
	node* temp = head -> next;
	while (temp->representative != item && temp->year != item && temp->party != item)
		temp = temp->next;
	return temp;
}
// search, untested

void linklist::Display(){
	string outFile = "plainText.txt";
	ofstream fout;                  // stream to connect to output file

	fout.open(outFile.c_str());

	if (fout.fail())				// but did the attempt to open fail?
	{
		cout << "ERROR: file called " << outFile << " did NOT open." << endl;
		exit(-1);
	} // if

	node *temp = head -> next;

	while (temp->next != 0)
		fout << temp->representative << temp->year/*<< temp->party */<< endl;
	fout << temp->representative << temp->year /*<< temp->party */<< endl;

}// display, untested
