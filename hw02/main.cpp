//
//  main.cpp
//  linked_list
//
//  Created by Qi Zhang on 8/27/14.
//  Copyright (c) 2014 QZ. All rights reserved.
//
//  Summary: This program reads the flat file database and uses its data to create a linked list. It allows the users to search for a certain record. In the end, all the records are stored in an output plaintext file.

#include <iostream>

#include "linked_list.h"

int main(int argc, const char * argv[])
{
    const short k_total_states = 51;  // global variable, total number of states contained in the database
    
    // 1) ~ 2) Creates an empty list and adds a node at the end of this list
    StateList L;
    
    // 3) populates the list from the flat file database
    L.populate_list();
    
    // 4) calls the function to search for a certain record
    L.search_value(k_total_states);
    
    // 5) displays the plain text in an output file
    L.display_content();
    
    return 0;
}

