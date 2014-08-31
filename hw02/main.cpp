//
//  main.cpp
//  linkedList
//
//  Created by Qi Zhang on 8/27/14.
//  Copyright (c) 2014 QZ. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

#include "linkedList.h"

typedef
struct reprMA
{
    string name, yearsServed, party;  // hold the representative's basic information
    
} REPR; // define a node called REPRESENTATIVE


int main(int argc, const char * argv[])
{
    // 1) ~ 3) 
    
    ifstream myFile("Representatives.csv");
    
    if (!myFile.is_open())
    {
        cout<<"ERROR";
    }
    
    string myLine;
    short n = 33; // There are 33 people in the list
    
    REPR rList[33];
    
    getline ( myFile, myLine, ',' ); // takes out the title
    
    short count = 0, people = 0;
    while(!myFile.eof()) {
        getline ( myFile, myLine, ',' ); // reads a string until next comma:
        
        if (count % 3 == 0) {
            rList[people].name = myLine;
            //cout << people << ": " << rList[people].name << endl;
        }
        else if (count % 3 == 1)
        {
            rList[people].yearsServed = myLine;
            //cout << people << ": " << rList[people].yearsServed << endl;
        }
        else
        {
            rList[people].party = myLine;
            //cout << people << ": " << rList[people].party << endl;
            people++;
        }
        count++;
        
    } // stores all the data to rList
    
    
    representativeList reprList;
    
    for (short i=0; i<n; i++) {
        reprList.createNode(rList[i].name, rList[i].yearsServed, rList[i].party);
    }
    
    myFile.close();
    
    
    // 4) calls the function to search for certain values
    reprList.searchValue(n);
    
    
    // 5) displays the plain text
    ifstream display("Representatives.csv");
    string line;
    
    while(!display.eof()) {
        getline ( display, line, ',' ); // reads a string until next comma:
        cout << line;
    }
    display.close();

    
    return 0;
}

