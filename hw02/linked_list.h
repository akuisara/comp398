//
//  linkedList.h
//  linkedList
//
//  Created by Qi Zhang on 8/27/14.
//  Copyright (c) 2014 QZ. All rights reserved.
//

#ifndef linked_list_linked_list_h
#define linked_list_linked_list_h

#include <iostream>
using namespace std;

struct RepresentativeMA
{
    string name, years_served, party;  // hold the representative's basic information
	struct RepresentativeMA  *next;	   // pointer to next node in the list
};


class RepresentativeList
{
  public:
    RepresentativeList();   // Constructor
    ~RepresentativeList();  // Destructor 
    
    void populate_list();
    void insert(RepresentativeMA* new_node);
    void search_value(const short k_total_representatives);
    void display_content();
    
  private:
    RepresentativeMA *head;  // pointer to the buffer node
    RepresentativeMA *tail;  // pointer to the last node
};  // class RepresentativeList

#endif
