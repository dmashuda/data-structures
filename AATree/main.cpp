//
//  main.cpp
//

#include <iostream>
#include "AATree.h"

int main(int argc, const char * argv[])
{
    AATree<int> myAATree;

    const int ARR_SIZE = 15;
    int insertArr[ARR_SIZE] = { 10, 85, 15, 70, 20, 60, 30, 50, 65, 80, 90, 40, 5, 55, 35 };

    for (int i=0; i < ARR_SIZE; i++) {
        std::cout << "*****************************************" << std::endl;
        std::cout << "Inserting " << insertArr[i] << std::endl;
        std::cout << "------------" << std::endl;
        myAATree.insert(insertArr[i]);
        myAATree.printTree();
    }

    

    
    std::cout << "*****************************************" << std::endl;
    int min = myAATree.findMin();
    std::cout << "Min: " << min << std::endl;
    
    int max = myAATree.findMax();
    std::cout << "Max: " << max << std::endl;
    
    bool found = myAATree.find(4);
    std::cout << "Find 4: " << found << std::endl;
    
    found = myAATree.find(5);
    std::cout << "Find 5: " << found << std::endl;
    
    found = myAATree.find(40);
    std::cout << "Find 40: " << found << std::endl;
    
    
    
    
    // Node with no children
    std::cout << "*****************************************" << std::endl;
    std::cout << "Remove " << 90 << " (node with no children)" << std::endl;
    std::cout << "------------" << std::endl;
    myAATree.remove(90);
    myAATree.printTree();
    
    // Node with one child
    std::cout << "*****************************************" << std::endl;
    std::cout << "Remove " << 5 << " (node with one child)" << std::endl;
    std::cout << "------------" << std::endl;
    myAATree.remove(5);
    myAATree.printTree();

    // Node with two children
    std::cout << "*****************************************" << std::endl;
    std::cout << "Remove " << 50 << " (node with two children)" << std::endl;
    std::cout << "------------" << std::endl;
    myAATree.remove(50);
    myAATree.printTree();
    
    // Node that doesn't exist
    std::cout << "*****************************************" << std::endl;
    std::cout << "Remove " << 42 << " (node that doesn't exist)" << std::endl;
    std::cout << "------------" << std::endl;
    myAATree.remove(42);
    myAATree.printTree();
    

    
    
    std::cout << "*****************************************" << std::endl;
    std::cout << "Emptying Tree" << std::endl;
    std::cout << "-------------" << std::endl;
    myAATree.makeEmpty();
    myAATree.printTree();
    
    // Node that doesn't exist again
    std::cout << "*****************************************" << std::endl;
    std::cout << "Remove " << 42 << " (from an empty tree)" << std::endl;
    std::cout << "------------" << std::endl;
    myAATree.remove(42);
    myAATree.printTree();


    
    
    std::cout << "*****************************************" << std::endl;
    std::cout << "**                DONE                 **" << std::endl;
    std::cout << "*****************************************" << std::endl;

    return 0;
}

