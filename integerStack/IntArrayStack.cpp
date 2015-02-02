//
//  IntArrayStack.cpp
//

#include "IntArrayStack.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
IntArrayStack::IntArrayStack(){
  top = -1;
  stack = new int[1];
  maxSize = 1;
}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
IntArrayStack::~IntArrayStack(){
  delete[] stack;
}
#endif

/* **************************************************************** */

#if PUSH || ALL
void IntArrayStack::push(int x){
  top++;

  if((top+1) == maxSize){
    resize(maxSize*2);
  }

  stack[top] = x;

}
#endif

/* **************************************************************** */

#if POP || ALL
 int IntArrayStack::pop(){
  if(top == -1){
    return -1;
  }

  int val;
  val = stack[top];

  top--;

  if(top < (maxSize/3)){
    if (maxSize >1)
    {
      resize(maxSize/2);
    }
    
  }

  return val;
}
#endif

/* **************************************************************** */

#if PEEK || ALL
int IntArrayStack::peek(){
  if(top == -1){
    return -1;
  }
  return stack[top];
}
#endif

/* **************************************************************** */

#if ISEMPTY || ALL
bool IntArrayStack::isEmpty(){
  if(top == -1){
    return true;
  }
  return false;
}
#endif

/* **************************************************************** */

#if EMPTYSTACK || ALL
void IntArrayStack::emptyStack(){
  resize(1);
  top = -1;
}
#endif

/* **************************************************************** */

#if RESIZE || ALL
void IntArrayStack::resize(int newSize){
  int *temp = new int[newSize];
  for(int i = 0; i <= top; i++){
    temp[i] = stack[i];
  }
  stack = temp;
  maxSize = newSize;
}
#endif

/* **************************************************************** */
// Do NOT modify anything below this line
/* **************************************************************** */

#ifndef BUILD_LIB
void IntArrayStack::printStack()
{
    std::cout << std::endl;
    std::cout << "Current array size: " << maxSize << std::endl;
    std::cout << "Number of ints in stack: " << top+1 << std::endl;
    for (int i=top; i >= 0; i--)
    {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}


int IntArrayStack::getCapacity()
{
  return maxSize;
}


int IntArrayStack::getSize()
{
  return top+1;
}


void IntArrayStack::toArray(int* arr)
{
  for (int i=top; i >= 0; i--)
  {
    arr[i] = stack[i];
  }
}
#endif

/* **************************************************************** */


