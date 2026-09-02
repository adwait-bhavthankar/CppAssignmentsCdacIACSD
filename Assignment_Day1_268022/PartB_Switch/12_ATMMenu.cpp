// 12. ATM Menu
#include <iostream>
using namespace std;

int main() {
    double balance = 10000.0;
    int choice;

    do {
        cout << "\n=== ATM MENU ===" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Current balance: Rs. " << balance << endl;
                break;
            case 2: {
                double amount;
                cout << "Enter deposit amount: ";
                cin >> amount;
                if (amount > 0) {
                    balance += amount;
                    cout << "Deposited successfully. Balance: Rs. " << balance << endl;
                } else {
                    cout << "Invalid amount!" << endl;
                }
                break;
            }
            case 3: {
                double amount;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    cout << "Withdrawn successfully. Balance: Rs. " << balance << endl;
                } else if (amount > balance) {
                    cout << "Insufficient balance!" << endl;
                } else {
                    cout << "Invalid amount!" << endl;
                }
                break;
            }
            case 4:
                cout << "Thank you for using the ATM!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
