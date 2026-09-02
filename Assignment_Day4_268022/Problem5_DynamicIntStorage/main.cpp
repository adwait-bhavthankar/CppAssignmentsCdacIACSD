// =====================================================
// Problem 5: Dynamic Integer Storage
// Demonstrates: dynamic memory allocation, deep copy
// constructor, destructor
// =====================================================

#include <iostream>
#include "Number.h"

using namespace std;

int main() {
    cout << "========== DYNAMIC INTEGER STORAGE ==========" << endl;

    // Create an object using the parameterized constructor
    cout << "\n--- Creating number1 with value 42 ---" << endl;
    Number number1(42);
    number1.display();

    // Create another object using the copy constructor (deep copy)
    cout << "\n--- Creating number2 as a copy of number1 ---" << endl;
    Number number2(number1);   // Copy constructor called
    number2.display();

    // Modify number2 - should NOT affect number1 (independent deep copy)
    cout << "\n--- Modifying number2 to 100 ---" << endl;
    number2.setValue(100);
    cout << "number1 : "; number1.display();
    cout << "number2 : "; number2.display();
    cout << ">> Demonstrates deep copy: number1 unchanged." << endl;

    // Create a third object using assignment-style copy
    cout << "\n--- Creating number3 as another copy ---" << endl;
    Number number3 = number1;  // Copy constructor called
    number3.display();

    cout << "\n--- End of program (destructors will run) ---" << endl;

    return 0;
}
