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

    // Display the initial fine rate
    cout << "\n--- Initial Fine Rate ---" << endl;
    LibraryMember::displayFineRate();

    // Create an array of LibraryMember objects
    LibraryMember members[3] = {
        LibraryMember(201, "Rahul Verma", 5),
        LibraryMember(202, "Kavita Iyer", 12),
        LibraryMember(203, "Sanjay Gupta", 2)
    };

    // Display all members with their fines
    cout << "\n--- Library Members and Fines ---" << endl;
    for (int i = 0; i < 3; i++) {
        members[i].display();
        cout << "---------------------------------" << endl;
    }

    // Modify the fine rate using static member function
    cout << "\n--- Update Fine Rate to Rs. 7 per day ---" << endl;
    LibraryMember::setFineRate(7.0);
    LibraryMember::displayFineRate();

    // Display recalculated fines
    cout << "\n--- Recalculated Fines After Rate Update ---" << endl;
    for (int i = 0; i < 3; i++) {
        members[i].display();
        cout << "---------------------------------" << endl;
    }

    // Attempt an invalid (negative) fine rate
    cout << "\n--- Attempt to set negative fine rate ---" << endl;
    LibraryMember::setFineRate(-3.0);

    return 0;
}
