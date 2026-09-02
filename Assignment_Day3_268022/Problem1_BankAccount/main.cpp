// =====================================================
// Problem 1: Bank Account System
// Demonstrates: class, constructor, member functions,
// array of objects
// =====================================================

#include <iostream>
#include "BankAccount.h"

using namespace std;

int main() {
    const int SIZE = 5;  // Number of accounts

    // Create an array of BankAccount objects
    // Each object is initialized using the parameterized constructor
    BankAccount accounts[SIZE] = {
        BankAccount(1001, "Alice Johnson", 50000.0),
        BankAccount(1002, "Bob Smith", 25000.0),
        BankAccount(1003, "Carol Davis", 78000.5),
        BankAccount(1004, "David Wilson", 12000.0),
        BankAccount(1005, "Emma Brown", 34000.25)
    };

    cout << "========== BANK ACCOUNT SYSTEM ==========" << endl;

    // Display all accounts
    cout << "\n--- All Account Balances ---" << endl;
    for (int i = 0; i < SIZE; i++) {
        accounts[i].displayBalance();
        cout << "---------------------------------" << endl;
    }

    // Perform a deposit on account[0]
    cout << "\n--- Deposit Rs. 5000 into Alice's account ---" << endl;
    accounts[0].deposit(5000);
    cout << "Updated balance: Rs. " << accounts[0].getBalance() << endl;

    // Perform a withdrawal on account[1]
    cout << "\n--- Withdraw Rs. 3000 from Bob's account ---" << endl;
    accounts[1].withdraw(3000);
    cout << "Updated balance: Rs. " << accounts[1].getBalance() << endl;

    // Attempt to overdraw (should fail)
    cout << "\n--- Attempt to withdraw Rs. 99999 from David's account ---" << endl;
    accounts[3].withdraw(99999);

    // Display final status of all accounts
    cout << "\n--- Final Account Status ---" << endl;
    for (int i = 0; i < SIZE; i++) {
        accounts[i].displayBalance();
        cout << "---------------------------------" << endl;
    }

    return 0;
}
