// former declaration of node
// programmer: Yingying Wu
// dates: 9/2/2014 adapt according to google style guide

//#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// node.h -- these are the NODES on the list
#ifndef HW01_NODE_H
#define HW01_NODE_H //define guard

// NODE for ONE elephant

struct node{
	string representative;
	string year;
	string party;
	node *next;
}; // clear names

#endif //398HW01_NODE_H
