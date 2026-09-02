// 8. Simple Calculator
#include <iostream>
using namespace std;

int main() {
    int choice;
    double a, b;

    cout << "=== SIMPLE CALCULATOR ===" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    switch (choice) {
        case 1:
            cout << "Result: " << a << " + " << b << " = " << (a + b) << endl;
            break;
        case 2:
            cout << "Result: " << a << " - " << b << " = " << (a - b) << endl;
            break;
        case 3:
            cout << "Result: " << a << " * " << b << " = " << (a * b) << endl;
            break;
        case 4:
            if (b != 0) {
                cout << "Result: " << a << " / " << b << " = " << (a / b) << endl;
            } else {
                cout << "Division by zero not allowed!" << endl;
            }
            break;
        case 5:
            cout << "Result: " << (int)a << " % " << (int)b << " = "
                 << ((int)a % (int)b) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
