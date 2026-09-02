#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
using namespace std;

// ============================
// Class: Number
// Dynamically allocates memory for an integer
// Demonstrates: constructor, copy constructor (deep copy),
// destructor
// ============================
class Number {
private:
    int* ptr;  // Pointer to dynamically allocated memory

public:
    // Parameterized constructor - allocates memory and initializes value
    Number(int value) {
        ptr = new int;          // Allocate memory
        *ptr = value;           // Store value
        cout << "Constructor called. Memory allocated, value = " << *ptr << endl;
    }

    // Copy constructor (deep copy) - creates separate memory copy
    Number(const Number& other) {
        ptr = new int;          // Allocate new memory
        *ptr = *(other.ptr);    // Copy the value (not the pointer)
        cout << "Copy constructor called. Deep copy made, value = " << *ptr << endl;
    }

    // Destructor - releases dynamically allocated memory
    ~Number() {
        cout << "Destructor called. Releasing memory ..." << endl;
        delete ptr;             // Free memory
    }

    // Get the stored value
    int getValue() const { return *ptr; }

    // Set a new value
    void setValue(int value) { *ptr = value; }

    // Display the stored value
    void display() const {
        cout << "Value: " << *ptr << endl;
    }
};

#endif
