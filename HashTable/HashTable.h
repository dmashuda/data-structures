//
//  HashTable.h
//  CS350_Lab07
//
//  Created by David Babcock on 11/26/12.
//  Copyright (c) 2012 David Babcock. All rights reserved.
//

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <string>
#include <iostream>
#include "Node.h"

class HashTable
{
public:
    // Constructor, destructor
    HashTable(int tableSize = 0);
    ~HashTable();
    
    // Public interface
    void insert(std::string x);
    bool find(std::string x);
    void remove(std::string x);
    void printTable();
    
    // Private fields
    Node ** table;
    int size;
    
    // Private methods
    float loadFactor();
    void maxChainLength(int& maxLength, int& maxSlotIndex);
    int numEmptySlots();
    unsigned int hash(std::string x);
};

#endif
