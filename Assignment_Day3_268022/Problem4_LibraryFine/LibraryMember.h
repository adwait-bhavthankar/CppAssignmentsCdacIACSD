#ifndef LIBRARYMEMBER_H
#define LIBRARYMEMBER_H

#include <iostream>
#include <string>
using namespace std;

// ============================
// Class: LibraryMember
// Stores member details and calculates overdue fine
// Uses static member for fine rate per day
// ============================
class LibraryMember {
private:
    int memberId;
    string name;
    int overdueDays;

public:
    // Static data member: fine rate per day (in Rs.)
    static double fineRate;

    // Parameterized constructor
    LibraryMember(int id = 0, string n = "Unknown", int days = 0)
        : memberId(id), name(n), overdueDays(days) {}

    // Calculate fine based on overdue days
    double calculateFine() const {
        return overdueDays * fineRate;
    }

    // Display member details and fine
    void display() const {
        cout << "  Member ID     : " << memberId << endl;
        cout << "  Name          : " << name << endl;
        cout << "  Overdue Days  : " << overdueDays << endl;
        cout << "  Fine          : Rs. " << calculateFine() << endl;
    }

    // Static member function to modify fine rate
    static void setFineRate(double rate) {
        if (rate >= 0) {
            fineRate = rate;
        } else {
            cout << ">> Fine rate cannot be negative!" << endl;
        }
    }

    // Static member function to display fine rate
    static void displayFineRate() {
        cout << "Current fine rate : Rs. " << fineRate << " per day" << endl;
    }
};

// Initialize static data member
double LibraryMember::fineRate = 5.0;

#endif
