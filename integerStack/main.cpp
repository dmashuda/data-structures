//
//  main.cpp
//

#include <iostream>
#include "IntArrayStack.h"
#include "minunit.h"

#pragma GCC diagnostic ignored "-Wwrite-strings"

IntArrayStack s;
int tests_run = 0;


static char * test_push() 
{
    std::cout << "-- Testing push --" << std::endl;
    std::cout << "Pushing 1 ... " << std::endl;
    s.push(1);
    std::cout << "Pushing 2 ... " << std::endl;
    s.push(2);
    std::cout << "Pushing 3 ... " << std::endl;
    s.push(3);
    std::cout << "Pushing 4 ... " << std::endl;
    s.push(4);
    std::cout << "Pushing 5 ... " << std::endl;
    s.push(5);

    int cap = s.getCapacity();
    int size = s.getSize();
    int *arr = new int[size];
    s.toArray(arr);

    std::cout << "  capacity = " << cap << std::endl;
    std::cout << "  size = " << size << std::endl;
    std::cout << "  contents: ";
    for (int i=size-1; i >= 0; i--) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    mu_assert("  ERROR: capacity is incorrect", cap == 8);
    mu_assert("  ERROR: size is incorrect", size == 5);
    mu_assert("  ERROR: contents are incorrect", 
              arr[4]==5 &&
              arr[3]==4 &&
              arr[2]==3 &&
              arr[1]==2 &&
              arr[0]==1
             );

    std::cout << "-- Testing push complete --" << std::endl << std::endl;

    delete[] arr;
    return 0;
}


static char * test_pop() 
{
    std::cout << "-- Testing pop --" << std::endl;
    std::cout << "Popping stack ..." << std::endl;
    int v = s.pop();
    std::cout << "  popped value = " << v << std::endl;
    mu_assert("  ERROR: popped value is incorrect", v == 5);

    std::cout << "Popping stack ..." << std::endl;
    v = s.pop();
    std::cout << "  popped value = " << v << std::endl;
    mu_assert("  ERROR: popped value is incorrect", v == 4);

    std::cout << "Popping stack ..." << std::endl;
    v = s.pop();
    std::cout << "  popped value = " << v << std::endl;
    mu_assert("  ERROR: popped value is incorrect", v == 3);

    std::cout << "Popping stack ..." << std::endl;
    v = s.pop();
    std::cout << "  popped value = " << v << std::endl;
    mu_assert("  ERROR: popped value is incorrect", v == 2);


    int cap = s.getCapacity();
    int size = s.getSize();
    int *arr = new int[size];
    s.toArray(arr);

    std::cout << "  capacity = " << cap << std::endl;
    std::cout << "  size = " << size << std::endl;
    std::cout << "  contents: ";
    for (int i=size-1; i >= 0; i--) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    mu_assert("  ERROR: capacity is incorrect", cap == 2);
    mu_assert("  ERROR: size is incorrect", size == 1);
    mu_assert("  ERROR: contents are incorrect", arr[0]==1);

    std::cout << "-- Testing pop complete --" << std::endl << std::endl;

    delete[] arr;
    return 0;
}


static char * test_emptyStack()
{
    std::cout << "-- Testing emptyStack --" << std::endl;
    std::cout << "Emptying stack" << std::endl;
    s.emptyStack();
    int cap = s.getCapacity();
    int size = s.getSize();
    std::cout << "  capacity = " << cap << std::endl;
    std::cout << "  size = " << size << std::endl;
    mu_assert("  ERROR: capacity is incorrect", cap == 1);
    mu_assert("  ERROR: size is incorrect", size == 0);
    std::cout << "-- Testing emptyStack complete --" << std::endl << std::endl;

    return 0;
}


static char * test_isEmpty()
{
    std::cout << "-- Testing isEmpty --" << std::endl;
    std::cout << "Emptying stack (just in case)" << std::endl;
    s.emptyStack();
    bool v = s.isEmpty();
    mu_assert("  ERROR: stack is not empty!", v == true);
    std::cout << "-- Testing isEmpty complete --" << std::endl << std::endl;

    return 0;
}


static char * all_tests() 
{
    mu_run_test(test_push);
    mu_run_test(test_pop);
    mu_run_test(test_emptyStack);
    mu_run_test(test_isEmpty);
    return 0;
}


int main(int argc, const char * argv[])
{
    std::cout << std::endl;

    char *result = all_tests();

    if (result != 0) {
        std::cout << result << std::endl;
        std::cout << "== ONE OR MORE TESTS FAILED ==" << std::endl;
        std::cout << "See output above for more info on failed tests" << std::endl;
    }
    else {
        std::cout << "== ALL TESTS PASSED ==" << std::endl;
    }

    std::cout << std::endl << "Total tests run: " << tests_run << std::endl;
    std::cout << std::endl;
    return result != 0;
}


