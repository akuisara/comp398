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

// -----------------------------------------------------------------------
StateList::StateList()
// Constructor
// POST: an empty list is created with a buffer node and an ending node
{
    tail = new StateAbbr;  // creates an empty node at the end of the list
    tail->name = "NULL";
    tail->next = 0;
    
    head = new StateAbbr;  // creates a butter node
    head->name = "BUFFER";
    head->next = tail;
} //CTOR


// -----------------------------------------------------------------------
StateList::~StateList()
// Destructor
{
    delete head;
} //DTOR


// -----------------------------------------------------------------------
void StateList::populate_list()
// This function reads the data from flat file database and calls insert() to add the new node to the list
{
    ifstream my_file("states.csv");  // opens the input file
    
    if (!my_file.is_open())
    {  //exit if cannot open the file
        cout<<"ERROR";
        exit(-1);
    }
    
    string my_line;  // a string contains a line
    
    getline (my_file, my_line, '\n');  // takes out the titles
    
    while(!my_file.eof()) {
        StateAbbr* temp_pointer = new StateAbbr;  // creates a temp pointer and builds a new node
        
        getline ( my_file, my_line, '\n' );  // reads the records of a state
        
        string temp = "";  // a string stores the segment reading from a line
        
        for(int i = 0; i < my_line.length(); i++)
        {   // within the length of this line, reads the segment
            temp += my_line[i];
            if(my_line[i] == ',')
            {
                temp_pointer->name = temp;  // stores this state's name in this new node
                temp = "";
            }
        }
        temp_pointer->abbreviation = temp;  // stores this state's abbreviation in this new node
        
        insert(temp_pointer);  // call insert() to insert this newly created node
    }
    
    my_file.close();
}  // populate_list()


// -----------------------------------------------------------------------
void StateList::insert(StateAbbr* new_node)
// This function insert the new node to the current linked list
// PRE-condition: a newly created node is assigned
{
    StateAbbr *temp = head->next;  // creates a temp pointer to hold the first node after the buffer node
    head->next = new_node;         // buffer node points to the newly inserted node
    new_node->next = temp;         // new node points to the next node
}  // insert()


// -----------------------------------------------------------------------
void StateList::search_value(const short k_total_states)
// This function allows user to search for a record
// PRE-condition: a constant integer k_total_states is assigned
{
    string search_name;  // the input string entered by user
    cout << endl << "Please enter a state name or an abbreviation: \n";
    cout << "(For example: Massachusetts or MA)\n\n";
    getline (cin,search_name);
    
    string search_name_state, search_name_abbr;
    search_name_state = "\"" + search_name + "\",";  // state name is quoted and is ended with a comma in input file
    search_name_abbr = "\"" + search_name + "\"";    // state abbreviation is quoted in input file
    
    StateAbbr *temp = head;  // creates a temp pointer in order to search the value in the linked list
    
    short search = 0;  // number of nodes has been searched so far
    
    while (temp->name != search_name_state &&
           temp->abbreviation != search_name_abbr &&
           search <= k_total_states) {
        temp = temp->next;
        search++;
    }
    if (temp->name == search_name_state || temp->abbreviation == search_name_abbr)
    {   // if find the name entered by user, then print out the whole record
        cout << "\n\nFind the record:" <<endl;
        cout << temp->name << temp->abbreviation << endl << endl;
    }
    else
        cout << "\n\nCannot find " <<search_name << endl << endl;
    
}  // search_value()


// -----------------------------------------------------------------------
void StateList::display_content()
// This function prints all the content to the output file as plain-text
{
    ifstream display("states.csv");      // opens the input file
    string line;                         // a string contains a line
    
    ofstream output_plaintext;           // opens the output file
    output_plaintext.open("plaintext.txt");
    
    while(!display.eof()) {
        getline ( display, line, ',' );  // reads a line from the input file
        output_plaintext << line;        // writes this line to the output file
    }
    
    display.close();
    output_plaintext.close();
    
}  // display_content()

