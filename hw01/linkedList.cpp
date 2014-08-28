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

void representativeList::searchValue(short n)
{
    string searchName;
    cout << endl << "Please enter a name for searching: \n";
    getline (cin,searchName);
    
    REPRESENTATIVE *temp = head;
    
    short search;
    while (temp->name != searchName && search <= n) {
        cout << temp->name;
        //Bug needs to fix: temp->name is always not euqal to searchName, even though they are the same
        temp = temp->next;
        search++;
    }
    if (temp->name == searchName)
    {
        cout << "\n\nFind the record" <<endl;
        cout << searchName << ": " << temp->yearsServed << "," << temp->party << endl << endl;
    }
    else
        cout << "\n\nCannot find " <<searchName << endl << endl;

}

