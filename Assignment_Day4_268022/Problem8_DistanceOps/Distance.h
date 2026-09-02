#ifndef DISTANCE_H
#define DISTANCE_H

#include <iostream>
using namespace std;

// ============================
// Class: Distance
// Represents a distance in feet and inches
// Demonstrates: operator overloading of '+' and '=='
// ============================
class Distance {
private:
    int feet;
    int inches;

public:
    // Parameterized constructor
    Distance(int f = 0, int i = 0) : feet(f), inches(i) {
        normalize();  // Ensure inches < 12
    }

    // Normalize inches so that 12 inches = 1 foot
    void normalize() {
        if (inches >= 12) {
            feet += inches / 12;
            inches %= 12;
        }
    }

    // Overload the '+' operator to add two Distance objects
    Distance operator+(const Distance& other) const {
        return Distance(feet + other.feet, inches + other.inches);
    }

    // Overload the '==' operator to compare two Distance objects
    bool operator==(const Distance& other) const {
        return (feet == other.feet && inches == other.inches);
    }

    // Display the distance
    void display() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }

    // Accessors
    int getFeet() const { return feet; }
    int getInches() const { return inches; }
};

#endif
