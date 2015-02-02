//
//  HashTable.cpp
//

#include "HashTable.h"
#include "Flags.h"
#include "stdio.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
HashTable::HashTable(int tableSize)
{
    table = new Node*[tableSize];
    for (int i = 0; i < tableSize; ++i)
    {
        table[i] = NULL;
    }
    size = tableSize;
}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
HashTable::~HashTable()
{
    for (int i = 0; i < size; ++i)
    {
        Node* next = table[i];
        while(next != NULL){
            Node* todelete = next;
            next = next->next;
            delete todelete;
        }
    }
    
    delete[] table;
}
#endif

/* **************************************************************** */

#if INSERT || ALL
void HashTable::insert(std::string x){
    int theHash = hash(x);

    if (table[theHash] == NULL)
    {
        table[theHash] = new Node(x);
    }else{
        Node* currNode = table[theHash];

        while(currNode->next != NULL){
            if (currNode->data==x)
            {
                return;
            }
            currNode = currNode->next;
        }
        Node* newNode = new Node(x);
        newNode->next = table[theHash];
        table[theHash] = newNode;
    }
    
    
}

#endif

/* **************************************************************** */

#if FIND || ALL
bool HashTable::find(std::string x){
    int theHash = hash(x);

    Node* leadNode = table[theHash];

    if (leadNode==NULL)
    {
        return false;
    }

    while(leadNode!=NULL){
        if (leadNode->data == x)
        {
            return true;
        }
        leadNode = leadNode->next;
    }

    return false;


}
#endif

/* **************************************************************** */

#if REMOVE || ALL
void HashTable::remove(std::string x){
    int theHash = hash(x);

    Node* leadNode = table[theHash];

    if (leadNode ==NULL)
    {
        return;
    }

    if (leadNode->data == x)
    {
        delete leadNode;
        table[theHash] = NULL;
    }

    Node* currNode = leadNode;

    while(currNode->next != NULL){
        if (currNode->next->data == x)
        {
            Node* temp = currNode->next;
            currNode->next = currNode->next->next;
            delete temp;
        }

        currNode = currNode->next;
    }

}
#endif

/* **************************************************************** */

#if LOADFACTOR || ALL
float HashTable::loadFactor(){
    int count = 0;

    for (int i = 0; i < size; ++i)
    {
        Node* currNode = table[i];

        while(currNode!=NULL){
            count++;
            currNode=currNode->next;
        }
    }

    return (float)count/(float)size;
}
#endif

/* **************************************************************** */

#if MAXCHAINLENGTH || ALL
void HashTable::maxChainLength(int& maxLength, int& maxSlotIndex){
    int currentMaxSize = 0;
    int currentMaxLocation = 0;

    for (int i = 0; i < size; ++i)
    {
        int currCount = 0;
        Node* currNode = table[i];

        while(currNode!=NULL){
            currCount++;
            currNode = currNode->next;
        }

        if (currCount > currentMaxSize)
        {
            currentMaxSize = currCount;
            currentMaxLocation =i;
        }
    }

    maxLength = currentMaxSize;
    maxSlotIndex = currentMaxLocation;
}
#endif

/* **************************************************************** */

#if NUMEMPTYSLOTS || ALL
int HashTable::numEmptySlots(){
    int count = 0;

    for (int i = 0; i < size; ++i)
    {
        if (table[i] == NULL)
        {
            count++;
        }
    }

    return count;
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* Do NOT modify anything below this line                           */
/* **************************************************************** */

#ifndef BUILD_LIB
unsigned int HashTable::hash(std::string x) {
    unsigned int hashCode = 0;
    std::string::iterator it;
    for (it=x.begin(); it < x.end(); it ++) {
        hashCode = *it + (hashCode << 5) - hashCode;
    }
    return hashCode % size;
}


void HashTable::printTable() {
    Node* node;
    // Iterate over table
    for (int i = 0; i < size; i++) {
        std::cout << "[" << i << "]: ";
        // Iterate over list
        node = table[i];
        while (node != NULL) {
            std::cout << node->data << " -> ";
            node = node->next;
        }
        std::cout << "NULL" << std::endl;
    }
}
#endif
