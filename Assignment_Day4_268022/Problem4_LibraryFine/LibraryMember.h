#ifndef LIBRARYMEMBER_H
#define LIBRARYMEMBER_H

#include <iostream>
#include <string>
using namespace std;

// ============================
// Class: LibraryMember
// Calculates library fines for overdue books
// Uses a static data member for fine rate and
// a static member function to modify/display it
// ============================
class LibraryMember {
private:
    int memberId;
    string name;
    int overdueDays;

    // Static data member: fine rate per day (shared by all objects)
    static double fineRatePerDay;

public:
    // Parameterized constructor
    LibraryMember(int id = 0, string n = "Unknown", int days = 0)
        : memberId(id), name(n), overdueDays(days) {}

    // Member function to calculate the fine
    double calculateFine() const {
        return overdueDays * fineRatePerDay;
    }

    // Member function to display member details and fine
    void displayDetails() const {
        cout << "  Member ID      : " << memberId << endl;
        cout << "  Member Name    : " << name << endl;
        cout << "  Overdue Days   : " << overdueDays << endl;
        cout << "  Fine Rate/Day  : Rs. " << fineRatePerDay << endl;
        cout << "  Total Fine     : Rs. " << calculateFine() << endl;
    }

    // Static member function to modify the fine rate
    static void setFineRate(double newRate) {
        if (newRate >= 0) {
            fineRatePerDay = newRate;
            cout << ">> Fine rate updated to Rs. " << fineRatePerDay << " per day." << endl;
        } else {
            cout << ">> Invalid fine rate!" << endl;
        }
    }

    // Static member function to display the fine rate
    static void displayFineRate() {
        cout << ">> Current fine rate: Rs. " << fineRatePerDay << " per day." << endl;
    }
};

// Initialize the static data member
double LibraryMember::fineRatePerDay = 5.0;  // Default Rs. 5 per day

#endif
