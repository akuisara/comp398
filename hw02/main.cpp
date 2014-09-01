//
//  main.cpp
//  linkedList
//
//  Created by Qi Zhang on 8/27/14.
//  Copyright (c) 2014 QZ. All rights reserved.
//  Summary: This program reads the flat file database and uses its data to create a linked list. It allows the users to search for a certain record. In the end, all the records are displayed on screen.

#include <iostream>

#include "linked_list.h"

int main(int argc, const char * argv[])
{
    const short k_total_representatives = 33;  // global variable, total number of representatives
    
    // 1) ~ 2) Creates an empty list and added a node at the end of this list
    RepresentativeList ReprList;
    
    // 3) populates the list from the flat file database
    ReprList.populate_list();
    
    // 4) calls the function to search for certain values
    ReprList.search_value(k_total_representatives);
    
    // 5) displays the plain text
    ReprList.display_content();
    
    return 0;
}

