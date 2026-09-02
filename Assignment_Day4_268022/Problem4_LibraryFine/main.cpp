// =====================================================
// Problem 4: Library Fine Calculator
// Demonstrates: class, constructor, static data member,
// static member function
// =====================================================

#include <iostream>
#include "LibraryMember.h"

using namespace std;

int main() {
    cout << "========== LIBRARY FINE CALCULATOR ==========" << endl;

    // Display the default fine rate
    cout << "\n--- Initial State ---" << endl;
    LibraryMember::displayFineRate();

    // Create LibraryMember objects (id, name, overdue days)
    LibraryMember member1(201, "Alice Johnson", 3);
    LibraryMember member2(202, "Bob Smith", 7);
    LibraryMember member3(203, "Carol Davis", 12);

    // Display details and fines with default rate
    cout << "\n--- Fines with Default Rate (Rs. 5/day) ---" << endl;
    member1.displayDetails(); cout << "-----------------------------" << endl;
    member2.displayDetails(); cout << "-----------------------------" << endl;
    member3.displayDetails();

    // Modify the fine rate using the static member function
    cout << "\n--- Updating Fine Rate ---" << endl;
    LibraryMember::setFineRate(10.0);

    // Display updated rate and recalculated fines
    cout << "\n--- Fines with Updated Rate (Rs. 10/day) ---" << endl;
    member1.displayDetails(); cout << "-----------------------------" << endl;
    member2.displayDetails(); cout << "-----------------------------" << endl;
    member3.displayDetails();

    return 0;
}
