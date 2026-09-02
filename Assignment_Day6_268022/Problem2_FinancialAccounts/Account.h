#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

// ============================
// Base class: Account
// Stores common account details
// ============================
class Account {
protected:
    int accountNumber;
    string customerName;
    double balance;

public:
    // Constructor
    Account(int accNo, string name, double bal)
        : accountNumber(accNo), customerName(name), balance(bal) {}

    // Virtual destructor for proper cleanup of derived objects
    virtual ~Account() {
        cout << "Account destructor called for: " << customerName << endl;
    }

    // Pure virtual function - must be overridden by derived classes
    virtual double calculateReturns() = 0;

    // Virtual function to display account info
    virtual void displayAccountInfo() {
        cout << "-----------------------------------" << endl;
        cout << "  Account Number  : " << accountNumber << endl;
        cout << "  Customer Name   : " << customerName << endl;
        cout << "  Balance         : Rs. " << balance << endl;
    }

    // Get customer name (used for RTTI display)
    string getCustomerName() const { return customerName; }

    // Virtual function for withdrawal (overridden where needed)
    virtual void withdraw(double amount) {
        if (amount <= 0) {
            cout << ">> Invalid amount!" << endl;
            return;
        }
        if (amount > balance) {
            cout << ">> Insufficient balance!" << endl;
            return;
        }
        balance -= amount;
        cout << ">> Rs. " << amount << " withdrawn successfully." << endl;
        cout << ">> New Balance: Rs. " << balance << endl;
    }
};

#endif
