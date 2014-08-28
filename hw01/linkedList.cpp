//
//  linkedList.cpp
//  linkedList
//
//  Created by Qi Zhang on 8/27/14.
//  Copyright (c) 2014 QZ. All rights reserved.
//

#include "linkedList.h"
#include <iostream>
using namespace std;

// CONTRUCTOR
representativeList::representativeList()
{
    tail = new REPRESENTATIVE;
    tail->name = "EMPTY";
    tail->yearsServed = "EMPTY";
    tail->party = "EMPTY";
    tail->next = 0;
    head = tail;
    head->next = tail;
}


void representativeList::createNode(string newName, string newYear, string newParty)
{
    REPRESENTATIVE* temp;
    temp = new REPRESENTATIVE;
    temp->name = newName;
    temp->yearsServed = newYear;
    temp->party = newParty;
    temp->next = 0;
    
    Insert(temp);
}


void representativeList::Insert(REPRESENTATIVE* newNode)
{
    REPRESENTATIVE *hold;
    hold = head->next;
    head->next = newNode;
    newNode->next = hold;
}

void representativeList::searchValue()
{
    string searchName;
    cout << endl << "Please enter a name for searching: \n";
    cin >> searchName;
    
    REPRESENTATIVE *temp = head;
    
    while (temp->name != searchName && temp->next != tail) {
        temp = temp->next;
    }
    if (temp->name == searchName)
    {
        cout << "Find the record" <<endl;
        cout << searchName << ": " << temp->yearsServed << "," << temp->party << endl << endl;
    }
    else
        cout << "Cannot find " <<searchName << endl << endl;

}

