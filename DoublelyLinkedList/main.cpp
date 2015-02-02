//
//  main.cpp
//

#include <iostream>
#include "DLList.h"
#include "minunit.h"

#pragma GCC diagnostic ignored "-Wwrite-strings"

DLList<int> myList;
int tests_run = 0;


static char * test_list_insert()
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "-- Testing list insert --" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Printing list before inserts ..." << std::endl;
    myList.printList();
    std::cout << std::endl;
    
    std::cout << "Inserting 1 ..." << std::endl;
    myList.insert(1);
    std::cout << "Inserting 2 ..." << std::endl;
    myList.insert(2);
    std::cout << "Inserting 4 ..." << std::endl;
    myList.insert(4);
    std::cout << std::endl;
    
    std::cout << "Printing list after inserts ..." << std::endl;
    myList.printList();
    std::cout << "-- Testing list insert complete --" << std::endl << std::endl;

    return 0;
}



static char * test_list_getFirst()
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "-- Testing list getFirst --" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    int val;
    val = myList.getFirst();
    std::cout << "First node: " << val << std::endl;
    
    mu_assert("  ERROR: first node is incorrect", val == 4);
    
    std::cout << "-- Testing list getFirst complete --" << std::endl << std::endl;
    return 0;
}


static char * test_list_getLast()
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "-- Testing list getLast --" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    int val;
    val = myList.getLast();
    std::cout << "Last node: " << val << std::endl;
    
    mu_assert("  ERROR: last node is incorrect", val == 1);
    
    std::cout << "-- Testing list getLast complete --" << std::endl << std::endl;
    return 0;
}


static char * test_list_find()
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "-- Testing list find --" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    bool found;
    
    std::cout << "Attempting to find 4 ..." << std::endl;
    found = myList.find(4);
    mu_assert("  ERROR: node 4 not found", found == true);

    std::cout << "Attempting to find 1 ..." << std::endl;
    found = myList.find(1);
    mu_assert("  ERROR: node 1 not found", found == true);
    
    std::cout << "Attempting to find 5 ..." << std::endl;
    found = myList.find(5);
    mu_assert("  ERROR: node 5 found, should not exist", found == false);
    
    std::cout << "-- Testing list find complete --" << std::endl << std::endl;
    return 0;
}


static char * test_list_remove()
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "-- Testing list remove --" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Printing list before removal ..." << std::endl;
    myList.printList();
    std::cout << std::endl;
    
    std::cout << "Removing 2 ..." << std::endl;
    myList.remove(2);
    std::cout << "Removing 5 ..." << std::endl;
    myList.remove(5);

    std::cout << "Printing list after removals ..." << std::endl;
    myList.printList();
    
    std::cout << "-- Testing list remove complete --" << std::endl << std::endl;
    return 0;
}


static char * test_list_makeEmpty()
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "-- Testing list makeEmpty --" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Printing list before emptying ..." << std::endl;
    myList.printList();
    std::cout << std::endl;
    
    std::cout << "Making list empty ..." << std::endl;
    myList.makeEmpty();
    
    std::cout << "Printing list after making empty ..." << std::endl;
    myList.printList();
    
    std::cout << "-- Testing list makeEmpty complete --" << std::endl << std::endl;
    return 0;
    
}


static char * test_list_copy()
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "-- Testing list copy constructor --" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Insert some nodes" << std::endl;
    
    std::cout << "Inserting 3 ..." << std::endl;
    myList.insert(3);
    std::cout << "Inserting 9 ..." << std::endl;
    myList.insert(9);
    std::cout << "Inserting 2 ..." << std::endl;
    myList.insert(2);
    std::cout << std::endl;
    
    std::cout << "Original list before copying ..." << std::endl;
    myList.printList();
    std::cout << std::endl;
    
    std::cout << "Calling copy constructor ..." << std::endl;
    DLList<int> *newList = new DLList<int>(myList);
    std::cout << std::endl;
    
    std::cout << "New list after copying ..." << std::endl;
    myList.printList();
    
    std::cout << "-- Testing list copy constructor complete --" << std::endl << std::endl;
    delete newList;
    return 0;
}


static char * test_list_assignment()
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "-- Testing list assignment --" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Original list before copying ..." << std::endl;
    myList.printList();
    std::cout << std::endl;
    
    std::cout << "Assigning original list to a new list ..." << std::endl;
    DLList<int> newList = myList;
    std::cout << std::endl;
    
    std::cout << "New list after copying ..." << std::endl;
    myList.printList();
    std::cout << std::endl;
    
    std::cout << "Removing node 9 from the new list ..." << std::endl;
    newList.remove(9);
    
    std::cout << "Original list after removing a node from new list (should not have changed) ..." << std::endl;
    myList.printList();
    std::cout << "New list after removing a node ..." << std::endl;
    newList.printList();
    std::cout << std::endl;
    
    
    std::cout << "Making original list empty ..." << std::endl;
    myList.makeEmpty();
    std::cout << "Original list after making empty ..." << std::endl;
    myList.printList();
    std::cout << "New list after making original list empty (should not have changed) ..." << std::endl;
    newList.printList();
    std::cout << std::endl;
    
    
    std::cout << "Making new list empty ..." << std::endl;
    newList.makeEmpty();
    std::cout << "Original list after making new list empty ..." << std::endl;
    myList.printList();
    std::cout << "New list after making empty ..." << std::endl;
    newList.printList();
    
    std::cout << "-- Testing list assignment complete --" << std::endl << std::endl;
    return 0;
}


static char * all_tests()
{
    mu_run_test(test_list_insert);
    mu_run_test(test_list_getFirst);
    mu_run_test(test_list_getLast);
    mu_run_test(test_list_find);
    mu_run_test(test_list_remove);
    mu_run_test(test_list_makeEmpty);
    mu_run_test(test_list_copy);
    mu_run_test(test_list_assignment);
    return 0;
}


int main(int argc, const char * argv[])
{
    std::cout << std::endl;
    
    char *result = all_tests();
    
    std::cout << std::endl << "Total tests run: " << tests_run << std::endl;
    std::cout << std::endl;
    
    return result != 0;
}
