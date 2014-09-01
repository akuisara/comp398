//
//  linkedList.cpp
//  linkedList
//
//  Created by Qi Zhang on 8/27/14.
//  Copyright (c) 2014 QZ. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

#include "linked_list.h"

StateList::StateList()
// Constructor
{
    tail = new StateAbbr;  // creates an empty node at the end of the list
    tail->name = "NULL";
    tail->next = 0;
    
    head = new StateAbbr;  // creates a butter node
    head->name = "BUFFER";
    head->next = tail;
}



StateList::~StateList()
// Destructor
{
    delete head;
}



void StateList::populate_list()
// This function reads the data from flat file database and calls insert() to add the new node to the list
{
    ifstream my_file("states.csv");
    
    if (!my_file.is_open())
    {  //exit if cannot open the file
        cout<<"ERROR";
        exit(-1);
    }
    
    string my_line;  // a string contains a line
    
    getline ( my_file, my_line, '\n' );  // takes out the titles
    
    while(!my_file.eof()) {
        StateAbbr* temp_pointer = new StateAbbr;
        
        getline ( my_file, my_line, '\n' );  // reads a record of an representative
        
        string temp = "";
        
        for(int i = 0; i < my_line.length(); i++)
        {   // within the length of this line, reads the segment
            temp += my_line[i];
            if(my_line[i] == ',')
            {
                temp_pointer->name = temp;
                //cout << temp_pointer->name << endl;
                temp = "";
            }
        }
        temp_pointer->abbreviation = temp;
        // cout << temp_pointer->abbreviation << endl;
        
        temp_pointer->next = tail;
        
        insert(temp_pointer);  // call insert() to insert this newly created node
    }
    
    my_file.close();
}  // end populate_list()



void StateList::insert(StateAbbr* new_node)
// This function insert the new node to the current linked list
{
    StateAbbr *temp = head->next;  // creates a temp pointer to hold the first node after the buffer node
    head->next = new_node;
    new_node->next = temp;
}  // end insert()



void StateList::search_value(const short k_total_states)
// This function allows users to search for a record
{
    string search_name;  // the input string entered by user
    cout << endl << "Please enter a state name to search its abbreviation: \n";
    cout << "(For example: Massachusetts)\n\n";
    getline (cin,search_name);
    
    search_name = "\"" + search_name + "\",";  // since the input file is .csv, so the value is comma seperated
    
    StateAbbr *temp = head;  // creates a temp pointer in order to search the value in the linked list
    
    short search = 0;  // number of nodes has been searched so far
    
    while (temp->name != search_name &&
           search <= k_total_states) {
        temp = temp->next;
        search++;
    }
    if (temp->name == search_name)
    {   // if find the name entered by user, then print out the whole record
        cout << "\n\nFind the record:" <<endl;
        cout << search_name << temp->abbreviation << endl << endl;
    }
    else
        cout << "\n\nCannot find " <<search_name << endl << endl;
    
}  // end search_value()



void StateList::display_content()
// This function prints all the content to the console
{
    ifstream display("states.csv");
    string line;  // a string contains a line
    
    ofstream output_plaintext;
    output_plaintext.open("plaintext.txt");
    
    while(!display.eof()) {
        getline ( display, line, ',' ); // reads a string until next comma:
        output_plaintext << line;
    }
    display.close();
}  // end display_content()

