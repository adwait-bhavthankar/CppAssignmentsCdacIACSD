// =====================================================
// Problem 6: Library Member Records
// Demonstrates: constructor, copy constructor, destructor
// =====================================================

#include <iostream>
#include "LibraryMember.h"

using namespace std;

int main() {
    cout << "========== LIBRARY MEMBER RECORDS ==========" << endl;

    // Create a member using the parameterized constructor
    cout << "\n--- Creating member1 ---" << endl;
    LibraryMember member1(301, "Alice Johnson", 4);
    member1.display();

    // Create another member using the copy constructor
    cout << "\n--- Creating member2 as a copy of member1 ---" << endl;
    LibraryMember member2(member1);   // Copy constructor
    member2.display();

    // Create a third member independently
    cout << "\n--- Creating member3 ---" << endl;
    LibraryMember member3(302, "Bob Smith", 7);
    member3.display();

    cout << "\n--- Members created. Destructors will run at end of scope. ---" << endl;

    return 0;
}
