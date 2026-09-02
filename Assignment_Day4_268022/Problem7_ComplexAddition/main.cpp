// =====================================================
// Problem 7: Complex Number Addition
// Demonstrates: operator overloading of '+'
// =====================================================

#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    cout << "========== COMPLEX NUMBER ADDITION ==========" << endl;

    // Create three Complex objects using the constructor
    Complex c1(3.5, 2.0);   // 3.5 + 2i
    Complex c2(1.5, 4.0);   // 1.5 + 4i
    Complex c3(-2.0, -3.0); // -2 - 3i

    // Display the numbers
    cout << "\nc1 = "; c1.display();
    cout << "c2 = "; c2.display();
    cout << "c3 = "; c3.display();

    // Add using the overloaded '+' operator
    Complex sum = c1 + c2;        // Operator overload
    Complex sum2 = c1 + c2 + c3;  // Chained operator overload

    cout << "\n--- Results ---" << endl;
    cout << "c1 + c2 = ";
    sum.display();

    cout << "c1 + c2 + c3 = ";
    sum2.display();

    // Demonstrate addition with a plain double (using implicit conversion)
    Complex sum3 = c1 + 4.5;      // 3.5+4.5 = 8.0, 2+0 = 2
    cout << "c1 + 4.5 = ";
    sum3.display();

    return 0;
}
