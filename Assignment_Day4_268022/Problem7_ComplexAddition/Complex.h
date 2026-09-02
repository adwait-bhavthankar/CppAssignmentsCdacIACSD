#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

// ============================
// Class: Complex
// Represents a complex number (real + imaginary i)
// Demonstrates: operator overloading of '+'
// ============================
class Complex {
private:
    double real;
    double imag;

public:
    // Parameterized constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload the '+' operator to add two Complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Display the complex number
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << (-imag) << "i" << endl;
    }

    // Accessors
    double getReal() const { return real; }
    double getImag() const { return imag; }
};

#endif
