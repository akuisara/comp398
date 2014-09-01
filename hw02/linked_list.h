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

struct StateAbbr
{
    string name, abbreviation;  // hold the states' basic information
	struct StateAbbr  *next;	   // pointer to next node in the list
};


class StateList
{
  public:
    StateList();   // Constructor
    ~StateList();  // Destructor
    
    void populate_list();
    void insert(StateAbbr* new_node);
    void search_value(const short k_total_states);
    void display_content();
    
  private:
    StateAbbr *head;  // pointer to the buffer node
    StateAbbr *tail;  // pointer to the last node
};  // class StateList

#endif
