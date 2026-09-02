#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

// ============================
// Class: BankAccount
// Stores account details and handles transactions
// ============================
class BankAccount {
private:
    int accountNumber;
    string customerName;
    double balance;

public:
    // Parameterized constructor
    BankAccount(int accNo = 0, string name = "Unknown", double bal = 0.0)
        : accountNumber(accNo), customerName(name), balance(bal) {}

    // Deposit money
    void deposit(double amount) {
        if (amount <= 0) {
            cout << ">> Invalid deposit amount!" << endl;
            return;
        }
        balance += amount;
        cout << ">> Rs. " << amount << " deposited successfully." << endl;
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << ">> Invalid withdrawal amount!" << endl;
            return;
        }
        if (amount > balance) {
            cout << ">> Insufficient balance!" << endl;
            return;
        }
        balance -= amount;
        cout << ">> Rs. " << amount << " withdrawn successfully." << endl;
    }

    // Display balance
    void displayBalance() const {
        cout << "  Account Number : " << accountNumber << endl;
        cout << "  Customer Name  : " << customerName << endl;
        cout << "  Balance        : Rs. " << balance << endl;
    }

    // Accessors
    int getAccountNumber() const { return accountNumber; }
    string getCustomerName() const { return customerName; }
    double getBalance() const { return balance; }
};

#endif
