//
//  Node.h
//  aatree
//
//  Created by David Babcock on 8/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _NODE_H_
#define _NODE_H_

// BST node
template <class T>
class Node
{
public:
    // Constructor (private, only for friends)
    Node(const T & theData = T(), Node * lch = NULL, Node * rch = NULL, int lev = 0)
    : data(theData), left(lch), right(rch), level(lev) {}
    
    T data;
    Node *left;
    Node *right;
    int level;
};

#endif
