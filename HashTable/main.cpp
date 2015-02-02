//
//  main.cpp
//  CS350_Lab07
//
//  Created by David Babcock on 11/26/12.
//  Copyright (c) 2012 David Babcock. All rights reserved.
//

#include <iostream>
#include "HashTable.h"

int main(int argc, const char * argv[])
{
    HashTable myTable(10);

    std::cout << "***************************************************************" << std::endl;
    std::cout << "Inserting..." << std::endl;
    std::cout << "------------" << std::endl;
    myTable.insert("Elephant");
    myTable.insert("Monkey");
    myTable.insert("Zebra");
    myTable.insert("Screeching Giraffe");
    myTable.insert("Donkey");
    myTable.insert("Badger");
    myTable.insert("Snake");
    myTable.insert("Tortoise");
    myTable.insert("Squid");
    myTable.insert("Whale");
    myTable.insert("Octopus");
    myTable.insert("Electric Eel");
    myTable.insert("Mountain Goat");
    myTable.insert("Lion");
    myTable.insert("Mountain Llama");
    myTable.insert("Sea Monkey");
    myTable.insert("Narwhal");
    myTable.insert("Flying Platypus");
    myTable.insert("Stealth Rhinoceros");
    myTable.insert("Magical Liger");
    myTable.insert("Bear");
    myTable.printTable();
    std::cout << "------------" << std::endl;
    
    std::cout << "Load Factor: " << myTable.loadFactor() << std::endl;
    int maxLength, maxSlotNum;
    myTable.maxChainLength(maxLength, maxSlotNum);
    std::cout << "Max Chain Length: " << maxLength << " at slot " << maxSlotNum << std::endl;
    int numEmpty = myTable.numEmptySlots();
    std::cout << "Number of Empty Slots: " << numEmpty << std::endl;
    std::cout << std::endl;
    
    
    
    std::cout << "***************************************************************" << std::endl;
    std::cout << "Find" << std::endl;
    std::cout << "------" << std::endl;
    bool found;
    found = myTable.find("Octopus");
    std::cout << "Searching for Octopus: " << found << std::endl;
    found = myTable.find("Dog");
    std::cout << "Searching for Dog: " << found << std::endl;
    std::cout << std::endl;
    
    
    
    std::cout << "***************************************************************" << std::endl;
    std::cout << "Removing Whale" << std::endl;
    std::cout << "Removing Zebra" << std::endl;
    std::cout << "Removing Cat (not in hash table)" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    myTable.remove("Whale");
    myTable.remove("Zebra");
    myTable.remove("Cat");
    myTable.printTable();
    std::cout << "------------" << std::endl;
    
    std::cout << "Load Factor: " << myTable.loadFactor() << std::endl;
    myTable.maxChainLength(maxLength, maxSlotNum);
    std::cout << "Max Chain Length: " << maxLength << " at slot " << maxSlotNum << std::endl;
    numEmpty = myTable.numEmptySlots();
    std::cout << "Number of Empty Slots: " << numEmpty << std::endl;
    std::cout << std::endl;
}

