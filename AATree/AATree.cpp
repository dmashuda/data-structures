//
//  AATree.cpp
//

#include "AATree.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
template <class T>
AATree<T>::AATree()
{
    bottomNode = new Node<T>();
    bottomNode->left = bottomNode;
    bottomNode->right = bottomNode;
    bottomNode->level = 0;
    bottomNode->data = -1;


    root = bottomNode;
    lastNode = bottomNode;
    deletedNode = bottomNode;

}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
template <class T>
AATree<T>::~AATree()
{
    makeEmpty();
    delete bottomNode;
}
#endif

/* **************************************************************** */

#if ISEMPTY || ALL
template <class T>
bool AATree<T>::isEmpty(){
    if (root == bottomNode)
    {
        return true;
    }

    return false;
}
#endif

/* **************************************************************** */

#if FIND || ALL
template <class T>
bool AATree<T>::find(const T & x){
    Node<T>* theNode = findNode(root, x);

    if (theNode == bottomNode)
    {
        return false;
    }

    return true;
}
#endif

/* **************************************************************** */

#if FINDNODE || ALL
template <class T>
Node<T>* AATree<T>::findNode(Node<T>* node, const T & x){
    Node<T>* theNode = node;

    while(theNode != bottomNode && theNode->data != x){
        if (x < theNode->data)
        {
            theNode = theNode->left;
        }else{
            theNode = theNode->right;
        }
    }

    return theNode;
}
#endif

/* **************************************************************** */

#if FINDMIN || ALL
template <class T>
const T & AATree<T>::findMin(){
    return findMinNode(root)->data;
}
#endif

/* **************************************************************** */

#if FINDMINNODE || ALL
template <class T>
Node<T>* AATree<T>::findMinNode(Node<T>* node){
    Node<T>* n = node;
    while(n->left != bottomNode){
        n = n->left;
    }

    return n;
}
#endif

/* **************************************************************** */

#if FINDMAX || ALL
template <class T>
const T & AATree<T>::findMax(){
    return findMaxNode(root)->data;
}
#endif

/* **************************************************************** */

#if FINDMAXNODE || ALL
template <class T>
Node<T> * AATree<T>::findMaxNode(Node<T> * node){
    Node<T>* n = node;
    while(n->right != bottomNode){
        n = n->right;
    }

    return n;
}
#endif

/* **************************************************************** */

#if INSERT || ALL
template <class T>
void AATree<T>::insert(const T & x){
    insertNode(root, x);
}
#endif

/* **************************************************************** */

#if INSERTNODE || ALL
template <class T>
Node<T> * AATree<T>::insertNode(Node<T> * & node, const T & x){
    Node<T>* theNode = bottomNode;
    if (node == bottomNode)
    {
        Node<T>* newNode = new Node<T>(x);
        newNode->level = 1;
        newNode->left = bottomNode;
        newNode->right = bottomNode;
        node = newNode;
        
    }else{
        if (x < node->data)
        {
            theNode = insertNode(node->left, x);
        }else if(x > node->data){
            theNode = insertNode(node->right, x);
        }
    }

    skew(node);
    split(node);

    return theNode;
}
#endif

/* **************************************************************** */

#if REMOVE || ALL
template <class T>
void AATree<T>::remove(const T & x){
    removeNode(root, x);
}
#endif

/* **************************************************************** */

#if REMOVENODE || ALL
template <class T>
void AATree<T>::removeNode(Node<T> * & node, const T & x){
    if (node == bottomNode)
    {
        return;
    }

    lastNode = node;

    if (x < node->data)
    {
        removeNode(node->left, x);
    }else{
        deletedNode = node;
        removeNode(node->right, x);
    }

    if (node == lastNode && deletedNode != bottomNode && x == deletedNode->data)
    {
        deletedNode->data = node->data;
        deletedNode = bottomNode;

        node = node->right;

        delete lastNode;

    }else if(node->left->level < (node->level -1) || node->right->level < (node->level-1) ){
        node->level = node->level-1;
        if (node->right->level > node->level)
        {
            node->right->level = node->level;
        }

        skew(node);
        skew(node->right);
        skew(node->right->right);

        split(node);
        split(node->right);
    }
}
#endif

/* **************************************************************** */

#if SKEW || ALL
template <class T>
void AATree<T>::skew(Node<T> * & node){
    if (node->left->level == node->level)
    {
        Node<T>* temp = node;

        node = node->left;

        temp->left = node->right;

        node->right = temp;
        
    }
}
#endif

/* **************************************************************** */

#if SPLIT || ALL
template <class T>
void AATree<T>::split(Node<T> * & node){
    if (node->right->right->level == node->level)
    {
        Node<T>* temp = node;
        node = node->right;
        temp->right = node->left;
        node->left = temp;
        node->level = node->level+1;
    }
}
#endif

/* **************************************************************** */

#if MAKEEMPTY || ALL
template <class T>
void AATree<T>::makeEmpty(){

    removeAllNodes(root);
    root = bottomNode;
}
#endif

/* **************************************************************** */

#if REMOVEALLNODES || ALL
template <class T>
void AATree<T>::removeAllNodes(Node<T> * node){

    if (node->right != bottomNode)
    {
        removeAllNodes(node->right);
    }
    if (node->left != bottomNode)
    {
        removeAllNodes(node->left);
    }

    if (node == bottomNode)
    {
        return;
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
void AATree<T>::printTree(){
    if (root != bottomNode)
    {
        printNodesInOrder(root);
        std::cout << std::endl;
    } else {
        std::cout << "Empty Tree" << std::endl;
        std::cout << std::endl;
    }
}

// Print tree using level order traversal
template <class T>
void AATree<T>::printNodesInOrder(Node<T> * node)
{
    Node<T>* q[100];
    int head = 0;
    int tail = 0;
    q[0] = root;
    tail++;
    
    while (head != tail)
    {
        Node<T> *n = q[head];
        head++;
        std::cout << "Node " << n->data << " at level " << n->level << std::endl;
        if (n->left != bottomNode)
        {
            std::cout << "  " << n->data << " left child: " << n->left->data << std::endl;
            q[tail] = n->left;
            tail++;
        }
        if (n->right != bottomNode)
        {
            std::cout << "  " << n->data << " right child: " << n->right->data << std::endl;
            q[tail] = n->right;
            tail++;
        }
    }
}
#endif

template class AATree<int>;
