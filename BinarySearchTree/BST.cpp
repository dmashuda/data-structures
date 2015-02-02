//
//  BST.cpp
//

#include "BST.h"
#include "Flags.h"

/* **************************************************************** */

#if ALL || CONSTRUCTOR
template <class T>
BST<T>::BST()
{
    root = NULL;
    numNodes = 0;
}
#endif

/* **************************************************************** */

#if ALL || DESTRUCTOR
template <class T>
BST<T>::~BST()
{
    makeEmpty();
}
#endif

/* **************************************************************** */

#if ALL || ISEMPTY
template <class T>
bool BST<T>::isEmpty(){
    if (root == NULL)
    {
        return true;
    }
    return false;
}
#endif

/* **************************************************************** */

#if ALL || FIND

template <class T>
bool BST<T>::find(const T & x){
    Node<T>* node =  findNode(root, x);
    if (node == NULL)
    {
        return false;
    }

    return true;
}

#endif

/* **************************************************************** */

#if ALL || FINDMIN
template <class T>
const T & BST<T>::findMin(){
    return findMinNode(root)->data;
}
#endif

/* **************************************************************** */

#if ALL || FINDMAX
template <class T>
const T & BST<T>::findMax(){
    return findMaxNode(root)->data;
}
#endif

/* **************************************************************** */

#if ALL || INSERT
template <class T>
void BST<T>::insert(const T & x){
    root = insertNode(root, x);
    numNodes++;
}
#endif

/* **************************************************************** */

#if ALL || REMOVE
template <class T>
void BST<T>::remove(const T & x){
    Node<T>* node =  findNode(root, x);
    if (node == NULL)
    {
        return;
    }
    
    Node<T>* parent = findParentOf(x);
    Node<T>* successor = findSuccessor(node);
    if (node->right == NULL && node->left == NULL)
    {
        if (parent->left == node)
        {
            parent->left = NULL;
        }else{
            parent->right = NULL;
        }
    }else if (node->right != NULL && node->left !=NULL)
    {
        if (parent->left == node)
        {
            parent->left = successor;
        }else{
            parent->right = successor;
        }

        successor->left = node->left;
        if (successor->right == node->right)
        {
            successor->right = node->right;
        }
        
    }
    else
    {

        if (parent->right == node)
        {
            if (successor == NULL)
            {
                parent->right = node->left;
            }else{
                parent->right =node->right;
            }
        }else if(parent->left == node){
            if (successor == NULL)
            {
                parent->right = node->left;
            }else{
                parent->right =node->right;
            }
        }
       
    }

    delete node;
    numNodes--;
    
}
#endif

/* **************************************************************** */

#if ALL || MAKEEMPTY
template <class T>
void BST<T>::makeEmpty(){
    removeAllNodes(root);
    root = NULL;
    numNodes = 0;
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/*  Private methods                                                 */
/* **************************************************************** */
#if ALL || FINDNODE
template <class T>
Node<T> * BST<T>::findNode(Node<T> * node,const T & x){
    if (node == NULL || node->data == x)
    {
        return node;
    }

    if (node->data < x)
    {
        return findNode(node->right, x);
    }
    
    return findNode(node->left, x);
    
}
#endif

/* **************************************************************** */

#if ALL || FINDMINNODE
template <class T>
Node<T> * BST<T>::findMinNode(Node<T> * node){
    if(node == NULL){
        return NULL;
    }
    if(node->left == NULL){
        return node;
    }

    return findMinNode(node->left);
}
#endif

/* **************************************************************** */

#if ALL || FINDMAXNODE
template <class T>
Node<T> * BST<T>::findMaxNode(Node<T> * node){
    if(node == NULL){
        return NULL;
    }
    if(node->right == NULL){
        return node;
    }

    return findMaxNode(node->right);
}
#endif

/* **************************************************************** */

#if ALL || INSERTNODE
template <class T>
 Node<T> * BST<T>::insertNode(Node<T> * node,const T & x){
    Node<T>* newNode = new Node<T>(x);
    if (node == NULL)
    {
        node = newNode;
    }
    else if (x  < node->data)
    {
        node->left = insertNode(node->left, x);
    }else{
        node->right = insertNode(node->right, x);
    }

    return node;
 }
#endif

/* **************************************************************** */

#if ALL || FINDSUCCESSOR
 template <class T>
 Node<T> * BST<T>::findSuccessor(Node<T> * node){
    if (node->right == NULL)
    {
        return NULL;
    }

    return findMinNode(node->right);
 }
 
#endif

/* **************************************************************** */

#if ALL || FINDPARENTOF
 
template <class T>
Node<T> * BST<T>::findParentOf(const T & x){
    
    Node<T>* currNode = root;
    Node<T>* nextNode = NULL;

    if (root == NULL)
    {
        return NULL;
    }
    if (currNode->data == x)
    {
        return NULL;
    }

    while(currNode != NULL){ 

        if (currNode->data > x)
        {
            nextNode = currNode->left;
        }else{
            nextNode = currNode->right;
        }


        if (nextNode == NULL)
        {
            currNode = NULL;
        }else if (nextNode->data == x)
        {
            return currNode;
        }else{
            currNode = nextNode;
        }

        
    }

    return NULL;


 }
#endif

/* **************************************************************** */

#if ALL || REMOVEALLNODES
template <class T>
void BST<T>::removeAllNodes(Node<T> * node){
    if (node->left != NULL)
    {
        removeAllNodes(node->left);
    }
    if (node->right != NULL)
    {
        removeAllNodes(node->right);
    }

    delete node;
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* Do NOT modify anything below this line                           */
/* **************************************************************** */

#ifndef BUILD_LIB
// Print tree
template <class T>
void BST<T>::printTree(){
    if (!isEmpty())
    {
        printNodesInOrder(root);
        std::cout << std::endl;
    } else {
        std::cout << "Empty Tree" << std::endl;
    }
}

// Print tree using level order traversal
template <class T>
void BST<T>::printNodesInOrder(Node<T> * node)
{
    Node<T>*q[100];
    int head = 0;
    int tail = 0;
    q[0] = root;
    tail++;
    
    while (head != tail)
    {
        Node<T> *n = q[head];
        head++;
        std::cout << "Node " << n->data << " ";
        if (n->left != NULL)
        {
            std::cout << " left child: " << n->left->data;
            q[tail] = n->left;
            tail++;
        }
        if (n->right != NULL)
        {
            std::cout << " right child: " << n->right->data;
            q[tail] = n->right;
            tail++;
        }
        
        if (n->left == NULL && n->right == NULL)
        {
            std::cout << " no children";
        }
        std::cout << std::endl;
    }
}
#endif

template class BST<int>;
