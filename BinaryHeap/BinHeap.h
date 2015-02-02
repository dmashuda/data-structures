#ifndef _BINHEAP_H_
#define _BINHEAP_H_

//
//  BinHeap.h
//
//  Created by David Babcock on 11/17/12.
//  Copyright (c) 2012 David Babcock. All rights reserved.
//

#include <iostream>

template <class T>
class BinHeap
{
public:
    // Constructor, destructor
    BinHeap();
    ~BinHeap();
    
    // Public interface
    bool isEmpty();
    void makeEmpty();
    void insert(const T & x);
    T removeMin();
    void buildHeap(const T* arr, int size);
    void printHeap();

    // Private fields
    T* heapArray;
    int maxSize;
    int heapSize;
    void resizeArray(int newSize);
    int leftIndex(int idx);
    int rightIndex(int idx);
    int parentIndex(int idx);
    int minChild(int idx);
    void percolateUp(int idx);
    void percolateDown(int idx);
};

#endif
