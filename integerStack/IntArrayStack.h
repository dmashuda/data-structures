//
//  IntArrayStack.h
//

#ifndef _INTARRAYSTACK_H_
#define _INTARRAYSTACK_H_

#include <iostream>

class IntArrayStack
{
private:
    // Class variables
    int *stack;
    int maxSize;
    int top;

    // (Private) utility methods
    void resize(int newSize);
    
public:
    IntArrayStack();
    ~IntArrayStack();
    
    // Public interface
    void push(int x);
    int pop();
    int peek();
    void emptyStack();
    bool isEmpty();

    void printStack();
    int getCapacity();
    int getSize();
    void toArray(int* arr);
};

#endif 
