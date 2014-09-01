//
//  linkedList.cpp
//  linkedList
//
//  Created by Qi Zhang on 8/27/14.
//  Copyright (c) 2014 QZ. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "linked_list.h"

RepresentativeList::RepresentativeList()
// Constructor
{
    tail = new RepresentativeMA;  // creates an empty node at the end of the list
    tail->name = "NULL";
    tail->next = 0;
    
    head = new RepresentativeMA;  // creates a butter node
    head->name = "BUFFER";
    head->next = tail;
}



RepresentativeList::~RepresentativeList()
// Destructor
{
    delete head;
}



void RepresentativeList::populate_list()
// This function reads the data from flat file database and calls insert() to add the new node to the list
{
    ifstream my_file("representatives.csv");
    
    if (!my_file.is_open())
    {  //exit if cannot open the file
        cout<<"ERROR";
        exit(-1);
    }
    
    string my_line;  // a string contains a line
    
    getline ( my_file, my_line, '\n' );  // takes out the titles
    
    short records = 0;  // counts the records of names and years
    
    while(!my_file.eof()) {
        RepresentativeMA* temp_pointer = new RepresentativeMA;
        
        getline ( my_file, my_line, '\n' );  // reads a record of an representative
        
        const short k_comma_seperated_records = 2;  // only names and years are seperated by comma
        string temp = "";
        
        for(int i = 0; i < my_line.length(); i++)
        {   // within the length of this line, reads the segment
            temp += my_line[i];
            if(my_line[i] == ',')
            {
                if (records % k_comma_seperated_records == 0) {
                    temp_pointer->name = temp;
                    // cout << temp_pointer->name << endl;
                } else if (records % k_comma_seperated_records == 1) {
                    temp_pointer->years_served = temp;
                    // cout << temp_pointer->years_served << endl;
                }
                temp = "";
                records++;
            }
        }
        temp_pointer->party = temp;
        // cout << temp_pointer->party << endl;
        
        temp_pointer->next = tail;
        
        insert(temp_pointer);  // call insert() to insert this newly created node
    }
    
    my_file.close();
}  // end populate_list()



void RepresentativeList::insert(RepresentativeMA* new_node)
// This function insert the new node to the current linked list
{
    RepresentativeMA *temp = head->next;  // creates a temp pointer to hold the first node after the buffer node
    head->next = new_node;
    new_node->next = temp;
}  // end insert()



void RepresentativeList::search_value(const short k_total_representatives)
// This function allows users to search for a record
{
    string search_name;  // the input string entered by user
    cout << endl << "Please enter a name for searching: \n";
    cout << "(For example: George Partridge)\n\n";
    getline (cin,search_name);
    
    search_name = search_name + ',';  // since the input file is .csv, so the value is comma seperated
    
    RepresentativeMA *temp = head;  // creates a temp pointer in order to search the value in the linked list
    
    short search = 0;  // number of nodes has been searched so far
    
    while (temp->name != search_name &&
           search <= k_total_representatives) {
        temp = temp->next;
        search++;
    }
    if (temp->name == search_name)
    {   // if find the name entered by user, then print out the whole record
        cout << "\n\nFind the record:" <<endl;
        cout << search_name << temp->years_served << temp->party << endl << endl;
    }
    else
        cout << "\n\nCannot find " <<search_name << endl << endl;
    
}  // end search_value()



void RepresentativeList::display_content()
// This function prints all the content to the console
{
    ifstream display("representatives.csv");
    string line;  // a string contains a line
    
    while(!display.eof()) {
        getline ( display, line, ',' ); // reads a string until next comma:
        cout << line;
    }
    display.close();
}  // end display_content()

