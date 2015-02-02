//
//  main.cpp
//

#include <iostream>
#include "BST.h"

int main(int argc, const char * argv[])
{
    BST<int> myBST;
    
    std::cout << "> Insert Nodes" << std::endl;
    myBST.insert(15);
    myBST.insert(6);
    myBST.insert(18);
    myBST.insert(3);
    myBST.insert(7);
    myBST.insert(17);
    myBST.insert(20);
    myBST.insert(2);
    myBST.insert(4);
    myBST.insert(13);
    myBST.insert(9);
    myBST.printTree();
    std::cout << std::endl;
    
    std::cout << "> Find" << std::endl;
    int min = myBST.findMin();
    std::cout << "> Min: " << min << std::endl;
    int max = myBST.findMax();
    std::cout << "> Max: " << max << std::endl;
    bool find = myBST.find(4);
    std::cout << "> Find 4: " << find << std::endl;
    find = myBST.find(5);
    std::cout << "> Find 5: " << find << std::endl;
    std::cout << std::endl;
    
    std::cout << "> Remove 4" << std::endl;
    // Node with no children
    myBST.remove(4);
    myBST.printTree();

    std::cout << "> Remove 13" << std::endl;
    // Node with one child
    myBST.remove(13);
    myBST.printTree();

    std::cout << "> Remove 6" << std::endl;
    // Node with two children
    myBST.remove(6);
    myBST.printTree();
    std::cout << std::endl;

    std::cout << "> Remove 10 (not in tree)" << std::endl;
    // Node not in tree
    myBST.remove(10);
    myBST.printTree();

    // Empty tree
    std::cout << "> Emptying Tree" << std::endl;
    myBST.makeEmpty();
    myBST.printTree();

    myBST.insert(4);
    myBST.insert(6);
    myBST.insert(1);
    
    return 0;
}

