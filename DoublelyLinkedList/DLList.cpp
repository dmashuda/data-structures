//
//  DLList.cpp
//

#include "DLList.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
// Constructor
template <class T>
DLList<T>::DLList()
{
    dummy = new Node<T>();
    dummy->next = dummy;
    dummy->prev = dummy;

}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
// Destructor
template <class T>
DLList<T>::~DLList()
{
    makeEmpty();

    delete dummy;

}
#endif

/* **************************************************************** */

#if ALL || GETFIRST
template <class T>
const T & DLList<T>::getFirst() const{
    
    return dummy->next->data;
}
#endif

/* **************************************************************** */

#if ALL || GETLAST
template <class T>
const T & DLList<T>::getLast() const{
    
    return dummy->prev->data;
}
#endif

/* **************************************************************** */

#if ALL || FIND
template <class T>
bool DLList<T>::find(const T & x) const{
    
    Node<T> *currNode = dummy->next;

    while(currNode != dummy){
        if(currNode->data == x){
            return true;
        }
        currNode = currNode->next;
    }

    return false;
}
#endif

/* **************************************************************** */

#if ALL || FINDNODE
template <class T>
Node<T>* DLList<T>::findNode(const T & x) const{
    Node<T> *currNode = dummy->next;

    while(currNode != dummy){
        if(currNode->data == x){
            return currNode;
        }
        currNode = currNode->next;
    }

    return dummy;
}
#endif

/* **************************************************************** */

#if ALL || INSERT
template <class T>
void DLList<T>::insert(const T & x){
    Node<T> *originalHead = dummy->next;
    Node<T> *newNode = new Node<T>(x);


    newNode->next = originalHead;
    originalHead->prev = newNode;
    dummy->next = newNode; 
}
#endif

/* **************************************************************** */

#if ALL || REMOVE
template <class T>
void DLList<T>::remove(const T & x){
    Node<T> *currNode = dummy->next;
    while(currNode != dummy){
        if(currNode->data == x){

            currNode->prev->next = currNode->next;
            currNode->next->prev = currNode->prev;

            delete currNode;
            return;
        }
        currNode = currNode->next;
    }
}
#endif

/* **************************************************************** */

#if ALL || ISEMPTY
template <class T>
bool DLList<T>::isEmpty() const{
    if ((dummy->next == dummy) & (dummy->prev == dummy))
    {
        return true;
    }

    return false;
}
#endif

/* **************************************************************** */

#if ALL || MAKEEMPTY
template <class T>
void DLList<T>::makeEmpty()
{
    while(dummy != dummy->next){

        Node<T> *temp = dummy->next;
        dummy->next = dummy->next->next;
        delete temp;
    }

    dummy->next = dummy;
    dummy->prev = dummy; 
}
#endif

/* **************************************************************** */

#if ALL || COPY_CONSTRUCTOR
template <class T>
DLList<T>::DLList(const DLList & rhs){
    
    dummy = new Node<T>();
    dummy->next = dummy;
    dummy->prev = dummy;
    
    *this = rhs;
}
#endif

/* **************************************************************** */

#if ALL || ASSIGN
template <class T>
const DLList<T>& DLList<T>::operator=(const DLList<T> & rhs){
    return *this;
}
#endif

/* **************************************************************** */
// Do NOT modify anything below this line
/* **************************************************************** */

#ifndef BUILD_LIB
// Print list
template <class T>
void DLList<T>::printList()
{
    if(isEmpty())
    {
        // Empty list
        std::cout << "Empty List" << std::endl;
    } else {
        // Iterate to end
        Node<T> *p = dummy->next;
        
        // Loop to end
        while (p != dummy)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
}
#endif

template class DLList<int>;
