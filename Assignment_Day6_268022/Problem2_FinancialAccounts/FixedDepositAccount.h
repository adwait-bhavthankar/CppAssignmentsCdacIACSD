#ifndef FIXEDDEPOSITACCOUNT_H
#define FIXEDDEPOSITACCOUNT_H

#include "Account.h"

// =================================================
// Derived class: FixedDepositAccount (from Account)
// Earns returns based on principal, rate, and tenure
// =================================================
class FixedDepositAccount : public Account {
private:
    double principalAmount;   // Fixed deposit principal
    double interestRate;      // Annual interest rate (in percentage)
    int depositTenure;        // Deposit tenure in years

public:
    // Constructor
    FixedDepositAccount(int accNo, string name, double bal,
                        double principal, double rate, int tenure)
        : Account(accNo, name, bal),
          principalAmount(principal), interestRate(rate), depositTenure(tenure) {}

    // Virtual destructor
    virtual ~FixedDepositAccount() {
        cout << "FixedDepositAccount destructor called for: " << customerName << endl;
    }

    // Calculate maturity amount using simple interest formula
    // Maturity = Principal + (Principal * Rate * Tenure / 100)
    double calculateReturns() override {
        return principalAmount * interestRate * depositTenure / 100.0;
    }

    // Calculate the maturity amount
    double getMaturityAmount() {
        return principalAmount + calculateReturns();
    }

    // Display FixedDepositAccount details
    void displayAccountInfo() override {
        Account::displayAccountInfo();  // Call base class display
        cout << "  Account Type     : Fixed Deposit Account" << endl;
        cout << "  Principal Amount : Rs. " << principalAmount << endl;
        cout << "  Interest Rate    : " << interestRate << "% per annum" << endl;
        cout << "  Deposit Tenure   : " << depositTenure << " years" << endl;
        cout << "  Interest Earned  : Rs. " << calculateReturns() << endl;
        cout << "  Maturity Amount  : Rs. " << getMaturityAmount() << endl;
        cout << "-----------------------------------" << endl;
    }

    // Override withdrawal - FD typically doesn't allow withdrawal before maturity
    void withdraw(double amount) override {
        cout << ">> Withdrawal not allowed on Fixed Deposit account before maturity!" << endl;
    }

    // Accessors for RTTI display
    double getPrincipalAmount() const { return principalAmount; }
    double getInterestRate() const { return interestRate; }
    int getDepositTenure() const { return depositTenure; }
};

#endif
