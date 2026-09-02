// =====================================================
// Problem 2: Financial Account Management System
// Demonstrates: Inheritance, Polymorphism, RTTI
// =====================================================

#include <iostream>
#include <vector>
#include <typeinfo>
#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include "FixedDepositAccount.h"

using namespace std;

// Function to display menu
void displayMenu() {
    cout << "\n========== FINANCIAL ACCOUNT MANAGEMENT SYSTEM ==========" << endl;
    cout << "1. Create Savings Account" << endl;
    cout << "2. Create Current Account" << endl;
    cout << "3. Create Fixed Deposit Account" << endl;
    cout << "4. Display All Accounts" << endl;
    cout << "5. Calculate Returns for All Accounts" << endl;
    cout << "6. Withdraw from an Account" << endl;
    cout << "7. Identify Account Types using RTTI" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    // Vector of Account pointers to store all account types
    vector<Account*> accounts;
    int choice;

    do {
        displayMenu();
        if (!(cin >> choice)) break;  // Handle EOF gracefully

        switch (choice) {

        // ---- Create Savings Account ----
        case 1: {
            int accNo;
            string name;
            double bal, rate, minBal;

            cout << "\n--- Enter Savings Account Details ---" << endl;
            cout << "Account Number: "; cin >> accNo;
            cin.ignore();
            cout << "Customer Name: "; getline(cin, name);
            cout << "Initial Balance (Rs.): "; cin >> bal;
            cout << "Interest Rate (% per annum): "; cin >> rate;
            cout << "Minimum Balance (Rs.): "; cin >> minBal;

            // Create SavingsAccount on heap and store pointer
            accounts.push_back(new SavingsAccount(accNo, name, bal, rate, minBal));
            cout << ">> Savings Account created successfully!" << endl;
            break;
        }

        // ---- Create Current Account ----
        case 2: {
            int accNo;
            string name;
            double bal, overdraft, charges;

            cout << "\n--- Enter Current Account Details ---" << endl;
            cout << "Account Number: "; cin >> accNo;
            cin.ignore();
            cout << "Customer Name: "; getline(cin, name);
            cout << "Initial Balance (Rs.): "; cin >> bal;
            cout << "Overdraft Limit (Rs.): "; cin >> overdraft;
            cout << "Monthly Service Charges (Rs.): "; cin >> charges;

            // Create CurrentAccount on heap and store pointer
            accounts.push_back(new CurrentAccount(accNo, name, bal, overdraft, charges));
            cout << ">> Current Account created successfully!" << endl;
            break;
        }

        // ---- Create Fixed Deposit Account ----
        case 3: {
            int accNo, tenure;
            string name;
            double bal, principal, rate;

            cout << "\n--- Enter Fixed Deposit Account Details ---" << endl;
            cout << "Account Number: "; cin >> accNo;
            cin.ignore();
            cout << "Customer Name: "; getline(cin, name);
            cout << "Account Balance (Rs.): "; cin >> bal;
            cout << "Principal Amount (Rs.): "; cin >> principal;
            cout << "Interest Rate (% per annum): "; cin >> rate;
            cout << "Deposit Tenure (years): "; cin >> tenure;

            // Create FixedDepositAccount on heap and store pointer
            accounts.push_back(new FixedDepositAccount(accNo, name, bal, principal, rate, tenure));
            cout << ">> Fixed Deposit Account created successfully!" << endl;
            break;
        }

        // ---- Display All Accounts using polymorphism ----
        case 4: {
            if (accounts.empty()) {
                cout << "\n>> No accounts found!" << endl;
                break;
            }
            cout << "\n========== ALL ACCOUNT DETAILS ==========" << endl;
            for (int i = 0; i < accounts.size(); i++) {
                // Polymorphic call - calls the correct derived class method
                accounts[i]->displayAccountInfo();
            }
            break;
        }

        // ---- Calculate Returns for All Accounts ----
        case 5: {
            if (accounts.empty()) {
                cout << "\n>> No accounts found!" << endl;
                break;
            }
            cout << "\n========== RETURNS SUMMARY ==========" << endl;
            for (int i = 0; i < accounts.size(); i++) {
                double returns = accounts[i]->calculateReturns();
                cout << accounts[i]->getCustomerName() << " -> Returns: Rs. " << returns << endl;
            }
            cout << "========================================" << endl;
            break;
        }

        // ---- Withdraw from an Account ----
        case 6: {
            if (accounts.empty()) {
                cout << "\n>> No accounts found!" << endl;
                break;
            }

            // Display account index list
            cout << "\n--- Select Account ---" << endl;
            for (int i = 0; i < accounts.size(); i++) {
                cout << "  " << (i + 1) << ". " << accounts[i]->getCustomerName() << endl;
            }
            int idx;
            cout << "Enter account number (1-" << accounts.size() << "): ";
            cin >> idx;

            if (idx < 1 || idx > accounts.size()) {
                cout << ">> Invalid account selection!" << endl;
                break;
            }

            double amount;
            cout << "Enter amount to withdraw (Rs.): "; cin >> amount;

            // Polymorphic call to withdraw
            accounts[idx - 1]->withdraw(amount);
            break;
        }

        // ---- RTTI: Identify actual type of each account ----
        case 7: {
            if (accounts.empty()) {
                cout << "\n>> No accounts found!" << endl;
                break;
            }
            cout << "\n========== RTTI - ACCOUNT TYPE IDENTIFICATION ==========" << endl;
            for (int i = 0; i < accounts.size(); i++) {
                cout << "\nAccount Holder: " << accounts[i]->getCustomerName() << endl;

                // Using typeid to get the actual runtime type
                cout << "  Runtime Type (typeid): " << typeid(*accounts[i]).name() << endl;

                // Using dynamic_cast to safely identify and access derived class info

                // Check if account is SavingsAccount
                SavingsAccount* savingsPt = dynamic_cast<SavingsAccount*>(accounts[i]);
                if (savingsPt != nullptr) {
                    cout << "  ** Identified as: SavingsAccount **" << endl;
                    cout << "  Interest Rate   : " << savingsPt->getInterestRate() << "% per annum" << endl;
                    cout << "  Minimum Balance : Rs. " << savingsPt->getMinimumBalance() << endl;
                    cout << "  Interest Earned : Rs. " << savingsPt->calculateReturns() << endl;
                }
                // Check if account is CurrentAccount
                else {
                    CurrentAccount* currentPt = dynamic_cast<CurrentAccount*>(accounts[i]);
                    if (currentPt != nullptr) {
                        cout << "  ** Identified as: CurrentAccount **" << endl;
                        cout << "  Overdraft Limit : Rs. " << currentPt->getOverdraftLimit() << endl;
                        cout << "  Service Charges : Rs. " << currentPt->getServiceCharges() << " /month" << endl;
                    }
                    // Check if account is FixedDepositAccount
                    else {
                        FixedDepositAccount* fdPt = dynamic_cast<FixedDepositAccount*>(accounts[i]);
                        if (fdPt != nullptr) {
                            cout << "  ** Identified as: FixedDepositAccount **" << endl;
                            cout << "  Principal Amount: Rs. " << fdPt->getPrincipalAmount() << endl;
                            cout << "  Interest Rate   : " << fdPt->getInterestRate() << "% per annum" << endl;
                            cout << "  Deposit Tenure  : " << fdPt->getDepositTenure() << " years" << endl;
                            cout << "  Maturity Amount : Rs. " << fdPt->getMaturityAmount() << endl;
                        }
                    }
                }
            }
            cout << "\n========================================================" << endl;
            break;
        }

        // ---- Exit and clean up memory ----
        case 8: {
            cout << "\n>> Cleaning up memory..." << endl;
            // Delete all dynamically allocated account objects
            for (int i = 0; i < accounts.size(); i++) {
                delete accounts[i];
            }
            accounts.clear();
            cout << ">> Thank you for using Financial Account Management System!" << endl;
            break;
        }

        default:
            cout << "\n>> Invalid choice! Please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
