
#include <iostream>
#include "gtest/gtest.h"
#include <string>
#include <sstream>
#include <vector>
#include "StringCalculator.h"
using namespace std;


int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    /* try {
        cout << "Test Case 1: " << StringCalculator::addNumbers("") << endl; 
        cout << "Test Case 2: " << StringCalculator::addNumbers("0") << endl;
        cout << "Test Case 3: " << StringCalculator::addNumbers("1") << endl;
        cout << "Test Case 4: " << StringCalculator::addNumbers("1,2") << endl;
        cout << "Test Case 5: " << StringCalculator::addNumbers("1,2,3,-1,4,5") << endl;
        cout << "Test Case 6: " << StringCalculator::addNumbers("1,1001,3,4,5") << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
    */
}

