//
//  DLList.h
//  Created by David Babcock on 8/3/12.
//
#ifndef _DLLIST_H_
#define _DLLIST_H_

#include <iostream>
#include "Node.h"

// Linked List Class (double)
template <class T>
class DLList
{
public:
    // Constructor, copy constructor, destructor
    DLList();
    DLList(const DLList & rhs);
    ~DLList();
    
    // Public interface
    void insert(const T & x);
    void remove(const T & x);
    const T & getFirst() const;
    const T & getLast() const;
    bool find(const T & x) const;
    bool isEmpty() const;
    void makeEmpty();
    void printList();
    
    // Operators
    const DLList<T> & operator=(const DLList<T> & rhs);
    
    // (Private) Dummy node
    Node<T> *dummy;
    
    // (Private) utility method
    Node<T> * findNode(const T & x) const;
};


#endif
