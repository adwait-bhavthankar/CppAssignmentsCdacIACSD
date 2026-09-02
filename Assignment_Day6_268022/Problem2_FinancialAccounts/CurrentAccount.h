#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"

// ======================================
// Derived class: CurrentAccount (from Account)
// Provides overdraft facility, applies service charges
// ======================================
class CurrentAccount : public Account {
private:
    double overdraftLimit;    // Maximum overdraft allowed
    double serviceCharges;    // Monthly service charges

public:
    // Constructor
    CurrentAccount(int accNo, string name, double bal, double overdraft, double charges)
        : Account(accNo, name, bal), overdraftLimit(overdraft), serviceCharges(charges) {}

    // Virtual destructor
    virtual ~CurrentAccount() {
        cout << "CurrentAccount destructor called for: " << customerName << endl;
    }

    // Calculate returns (service charges are deducted, so negative return)
    // Returns the net effect: overdraft usage minus service charges
    double calculateReturns() override {
        // Net return = negative of service charges (cost to customer)
        return -serviceCharges;
    }

    // Display CurrentAccount details
    void displayAccountInfo() override {
        Account::displayAccountInfo();  // Call base class display
        cout << "  Account Type     : Current Account" << endl;
        cout << "  Overdraft Limit  : Rs. " << overdraftLimit << endl;
        cout << "  Service Charges  : Rs. " << serviceCharges << " /month" << endl;
        cout << "  Available (with overdraft): Rs. " << (balance + overdraftLimit) << endl;
        cout << "-----------------------------------" << endl;
    }

    // Override withdrawal to allow overdraft
    void withdraw(double amount) override {
        if (amount <= 0) {
            cout << ">> Invalid amount!" << endl;
            return;
        }
        // Allow withdrawal up to balance + overdraft limit
        if (amount > (balance + overdraftLimit)) {
            cout << ">> Exceeds overdraft limit! Maximum withdrawal: Rs. "
                 << (balance + overdraftLimit) << endl;
            return;
        }
        balance -= amount;
        cout << ">> Rs. " << amount << " withdrawn successfully." << endl;
        if (balance < 0) {
            cout << ">> ** WARNING: Account is in overdraft! **" << endl;
        }
        cout << ">> Balance: Rs. " << balance << endl;
    }

    // Accessors for RTTI display
    double getOverdraftLimit() const { return overdraftLimit; }
    double getServiceCharges() const { return serviceCharges; }
};

#endif
