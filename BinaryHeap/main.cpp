//
//  main.cpp
//

#include <iostream>
#include "BinHeap.h"

int main(int argc, const char * argv[])
{
    BinHeap<int> myBinHeap;
    
    const int ARR_SIZE = 8;
    int insertArr[] = {6, 9, 2, 10, 8, 14, 5, 1};
    
    
    for (int i=0; i < ARR_SIZE; i++) {
        std::cout << "***************************************************************" << std::endl;
        std::cout << "Inserting " << insertArr[i] << std::endl;
        std::cout << "------------" << std::endl;
        myBinHeap.insert(insertArr[i]);
        myBinHeap.printHeap();
    }
    
    
    std::cout << "***************************************************************" << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << std::endl;
    
    
    
    
    for (int i=0; i < ARR_SIZE+1; i++) {
        std::cout << "***************************************************************" << std::endl;
        std::cout << "About to remove min element from heap with following properties" << std::endl;
        myBinHeap.printHeap();
        int min = myBinHeap.removeMin();
        std::cout << "Removed min value: " << min << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "Heap after removing minimum element" << std::endl;
        myBinHeap.printHeap();
    }
    

    std::cout << "***************************************************************" << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << std::endl;
    
    
    
    
    std::cout << "***************************************************************" << std::endl;
    std::cout << "Reconstructing heap with buildHeap()" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    myBinHeap.buildHeap(insertArr, ARR_SIZE);
    myBinHeap.printHeap();
    
    std::cout << "***************************************************************" << std::endl;
    std::cout << "About to remove min element from heap with following properties" << std::endl;
    myBinHeap.printHeap();
    int min = myBinHeap.removeMin();
    std::cout << "Removed min value: " << min << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "Heap after removing minimum element" << std::endl;
    myBinHeap.printHeap();
    
    std::cout << "***************************************************************" << std::endl;
    std::cout << "Making heap empty" << std::endl;
    std::cout << "-----------------" << std::endl;
    myBinHeap.makeEmpty();
    myBinHeap.printHeap();

}
