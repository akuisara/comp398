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
    head->name = "EMPTY";
    head->yearsServed = "EMPTY";
    head->party = "EMPTY";
    head->next = tail;
    
}

representativeList::~representativeList()
{
    REPRESENTATIVE *A, *B;
    A = head;
    delete A;
    
    B = head->next;
    
    short i = 3;
    while (B!=0) {
        A = B;
        delete B;
        i--;
        cout << i << endl;
        B = A->next;
    }
}


REPRESENTATIVE* representativeList::createNode(string newName, string newYear, string newParty)
{
    REPRESENTATIVE* temp;
    temp = new REPRESENTATIVE;
    temp->name = newName;
    temp->yearsServed = newYear;
    temp->party = newParty;
    temp->next = 0;
    return temp;
}


void representativeList::Insert(REPRESENTATIVE* newNode, representativeList myList)
{
    REPRESENTATIVE *hold;
    hold = head->next;
    head->next = newNode;
    newNode->next = hold;
}

void representativeList::searchValue()
{
    string searchName;
    cout << "Please enter a name for searching: \n";
    cin >> searchName;
    
    REPRESENTATIVE *temp = head->next;
    while (temp->name != searchName && temp->next != tail) {
        temp = temp->next;
    }
    if (temp->name == searchName)
        cout << "Find " << searchName << endl;
    else
        cout << "Cannot find " <<searchName << endl;

}

