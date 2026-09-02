#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

// ======================================
// Derived class: SavingsAccount (from Account)
// Earns interest based on balance
// ======================================
class SavingsAccount : public Account {
private:
    double interestRate;      // Annual interest rate (in percentage)
    double minimumBalance;    // Minimum balance required

public:
    // Constructor
    SavingsAccount(int accNo, string name, double bal, double rate, double minBal)
        : Account(accNo, name, bal), interestRate(rate), minimumBalance(minBal) {}

    // Virtual destructor
    virtual ~SavingsAccount() {
        cout << "SavingsAccount destructor called for: " << customerName << endl;
    }

    // Calculate interest earned on current balance
    double calculateReturns() override {
        return balance * interestRate / 100.0;
    }

    // Display SavingsAccount details
    void displayAccountInfo() override {
        Account::displayAccountInfo();  // Call base class display
        cout << "  Account Type    : Savings Account" << endl;
        cout << "  Interest Rate   : " << interestRate << "% per annum" << endl;
        cout << "  Minimum Balance : Rs. " << minimumBalance << endl;
        cout << "  Interest Earned : Rs. " << calculateReturns() << endl;
        cout << "-----------------------------------" << endl;
    }

    // Override withdrawal to enforce minimum balance
    void withdraw(double amount) override {
        if (amount <= 0) {
            cout << ">> Invalid amount!" << endl;
            return;
        }
        if (amount > balance) {
            cout << ">> Insufficient balance!" << endl;
            return;
        }
        if ((balance - amount) < minimumBalance) {
            cout << ">> Cannot withdraw! Balance would fall below minimum balance of Rs. " << minimumBalance << endl;
            return;
        }
        balance -= amount;
        cout << ">> Rs. " << amount << " withdrawn successfully." << endl;
        cout << ">> New Balance: Rs. " << balance << endl;
    }

    // Accessors for RTTI display
    double getInterestRate() const { return interestRate; }
    double getMinimumBalance() const { return minimumBalance; }
};

#endif
