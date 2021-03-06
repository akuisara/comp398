//
//  linkedList.h
//  linkedList
//
//  Created by Qi Zhang on 8/27/14.
//  Copyright (c) 2014 QZ. All rights reserved.
//

#ifndef linkedList_linkedList_h
#define linkedList_linkedList_h

#include <iostream>
using namespace std;

typedef
struct representativeMA
{
    string name, yearsServed, party;  // hold the representative's basic information
    
	struct representativeMA  *next;	  // pointer to next node in the list
	
} REPRESENTATIVE; // define a node called REPRESENTATIVE

class representativeList
{
  public:
    representativeList();
    
    
    void createNode(string newName, string newYear, string newParty);

    void Insert(REPRESENTATIVE* newNode);
    
    void searchValue(short totalNum);
    
    REPRESENTATIVE *head;   
    REPRESENTATIVE *tail;   // pointer to the last node on the list
    
};

#endif
