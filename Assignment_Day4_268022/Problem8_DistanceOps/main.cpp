// =====================================================
// Problem 8: Distance Comparison and Addition
// Demonstrates: operator overloading of '+' and '=='
// =====================================================

#include <iostream>
#include "Distance.h"

using namespace std;

int main() {
    cout << "========== DISTANCE COMPARISON AND ADDITION ==========" << endl;

    // Create Distance objects using the constructor
    Distance d1(5, 8);     // 5 feet 8 inches
    Distance d2(3, 10);    // 3 feet 10 inches
    Distance d3(5, 8);     // 5 feet 8 inches (same as d1)
    Distance d4(2, 15);    // 2 feet 15 inches (normalizes to 3 feet 3 inches)

    // Display the distances
    cout << "\nd1 = "; d1.display();
    cout << "d2 = "; d2.display();
    cout << "d3 = "; d3.display();
    cout << "d4 (2ft 15in, normalized) = "; d4.display();

    // Addition using overloaded '+'
    Distance sum = d1 + d2;
    cout << "\nd1 + d2 = ";
    sum.display();

    // Comparison using overloaded '=='
    cout << "\n--- Comparisons ---" << endl;
    if (d1 == d2)
        cout << "d1 equals d2" << endl;
    else
        cout << "d1 does NOT equal d2" << endl;

    if (d1 == d3)
        cout << "d1 equals d3" << endl;
    else
        cout << "d1 does NOT equal d3" << endl;

    if (d1 == d4)
        cout << "d1 equals d4" << endl;
    else
        cout << "d1 does NOT equal d4" << endl;

    return 0;
}
