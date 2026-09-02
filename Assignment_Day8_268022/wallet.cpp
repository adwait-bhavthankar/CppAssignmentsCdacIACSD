#include <iostream>
#include <string>
#include <limits>
using namespace std;

class InvalidAmountException {
    string message;
public:
    InvalidAmountException(string msg) : message(msg) {}
    string what() const { return message; }
};

class InsufficientBalanceException {
    string message;
public:
    InsufficientBalanceException(string msg) : message(msg) {}
    string what() const { return message; }
};

class Wallet {
    string walletId;
    string holderName;
    double balance;

public:
    Wallet() : walletId(""), holderName(""), balance(0.0) {}
    Wallet(string id, string name, double bal) : walletId(id), holderName(name), balance(bal) {}

    string getWalletId() const { return walletId; }
    string getHolderName() const { return holderName; }
    double getBalance() const { return balance; }

    void setWalletId(string id) { walletId = id; }
    void setHolderName(string name) { holderName = name; }

    void addMoney(double amount) {
        if (amount <= 0) {
            throw InvalidAmountException("Amount must be positive.");
        }
        balance += amount;
    }

    void withdrawMoney(double amount) {
        if (amount <= 0) {
            throw InvalidAmountException("Amount must be positive.");
        }
        if (amount > balance) {
            throw InsufficientBalanceException("Insufficient balance.");
        }
        balance -= amount;
    }

    friend istream& operator>>(istream& in, Wallet& w);
    friend ostream& operator<<(ostream& out, const Wallet& w);
};

istream& operator>>(istream& in, Wallet& w) {
    cout << "Enter Wallet ID: ";
    in >> w.walletId;
    cout << "Enter Holder Name: ";
    in.ignore();
    getline(in, w.holderName);
    cout << "Enter Initial Balance: ";
    in >> w.balance;
    return in;
}

ostream& operator<<(ostream& out, const Wallet& w) {
    out << "==============================" << endl;
    out << "Wallet ID      : " << w.walletId << endl;
    out << "Holder Name    : " << w.holderName << endl;
    out << "Balance        : " << w.balance << endl;
    out << "==============================" << endl;
    return out;
}

void displayMenu() {
    cout << "\n--- Digital Wallet Menu ---" << endl;
    cout << "1. Create Wallet" << endl;
    cout << "2. Add Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Display Wallet Details" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Wallet wallet;
    bool walletCreated = false;
    int choice;
    double amount;

    do {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            clearInput();
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        try {
            switch (choice) {
                case 1:
                    cout << "\n--- Create Wallet ---" << endl;
                    cin >> wallet;
                    walletCreated = true;
                    cout << "\nWallet created successfully!" << endl;
                    cout << wallet;
                    break;

                case 2:
                    if (!walletCreated) {
                        cout << "\nPlease create a wallet first." << endl;
                        break;
                    }
                    cout << "\n--- Add Money ---" << endl;
                    cout << "Enter amount to add: ";
                    cin >> amount;
                    if (cin.fail()) {
                        clearInput();
                        throw InvalidAmountException("Invalid input. Please enter a number.");
                    }
                    wallet.addMoney(amount);
                    cout << "\nMoney added successfully!" << endl;
                    cout << wallet;
                    break;

                case 3:
                    if (!walletCreated) {
                        cout << "\nPlease create a wallet first." << endl;
                        break;
                    }
                    cout << "\n--- Withdraw Money ---" << endl;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    if (cin.fail()) {
                        clearInput();
                        throw InvalidAmountException("Invalid input. Please enter a number.");
                    }
                    wallet.withdrawMoney(amount);
                    cout << "\nMoney withdrawn successfully!" << endl;
                    cout << wallet;
                    break;

                case 4:
                    if (!walletCreated) {
                        cout << "\nPlease create a wallet first." << endl;
                        break;
                    }
                    cout << "\n--- Wallet Details ---" << endl;
                    cout << wallet;
                    break;

                case 5:
                    cout << "\nExiting... Thank you!" << endl;
                    break;

                default:
                    cout << "\nInvalid choice. Please try again." << endl;
            }
        } catch (InvalidAmountException& e) {
            cout << "\n[Error] " << e.what() << endl;
        } catch (InsufficientBalanceException& e) {
            cout << "\n[Error] " << e.what() << endl;
        } catch (...) {
            cout << "\n[Error] An unexpected error occurred." << endl;
        }

    } while (choice != 5);

    return 0;
}
