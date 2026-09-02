// 11. Menu-Driven Area Calculator
#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "=== AREA CALCULATOR ===" << endl;
    cout << "1. Circle" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Square" << endl;
    cout << "4. Triangle" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            double r;
            cout << "Enter radius: ";
            cin >> r;
            cout << "Area of circle: " << (3.14159 * r * r) << endl;
            break;
        }
        case 2: {
            double l, w;
            cout << "Enter length and width: ";
            cin >> l >> w;
            cout << "Area of rectangle: " << (l * w) << endl;
            break;
        }
        case 3: {
            double s;
            cout << "Enter side: ";
            cin >> s;
            cout << "Area of square: " << (s * s) << endl;
            break;
        }
        case 4: {
            double b, h;
            cout << "Enter base and height: ";
            cin >> b >> h;
            cout << "Area of triangle: " << (0.5 * b * h) << endl;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
