#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

// ============================
// Class: Customer
// Stores basic customer details
// ============================
class Customer {
private:
    int customerId;
    string customerName;
    string contactNumber;

public:
    // Parameterized constructor
    Customer(int id = 0, string name = "Unknown", string contact = "N/A")
        : customerId(id), customerName(name), contactNumber(contact) {}

    // Function to initialize customer details
    void setCustomer(int id, string name, string contact) {
        customerId = id;
        customerName = name;
        contactNumber = contact;
    }

    // Function to display customer details
    void displayCustomer() const {
        cout << "  Customer ID      : " << customerId << endl;
        cout << "  Customer Name    : " << customerName << endl;
        cout << "  Contact Number   : " << contactNumber << endl;
    }

    // Accessors
    int getCustomerId() const { return customerId; }
    string getCustomerName() const { return customerName; }
    string getContactNumber() const { return contactNumber; }
};

#endif
