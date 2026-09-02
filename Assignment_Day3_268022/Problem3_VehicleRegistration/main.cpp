// =====================================================
// Problem 3: Vehicle Registration System
// Demonstrates: class, constructors, static member,
// array of objects
// =====================================================

#include <iostream>
#include "Vehicle.h"

using namespace std;

int main() {
    const int SIZE = 4;  // Number of vehicles

    // Create an array of Vehicle objects
    Vehicle vehicles[SIZE] = {
        Vehicle("MH12AB1234", "Ravi Kumar", "Car"),
        Vehicle("MH01CD5678", "Priya Sharma", "Bike"),
        Vehicle("DL3EC9012", "Amit Patel", "Truck"),
        Vehicle("KA05FG3456", "Sneha Reddy", "Car")
    };

    cout << "========== VEHICLE REGISTRATION SYSTEM ==========" << endl;

    // Display all vehicles
    cout << "\n--- All Registered Vehicles ---" << endl;
    for (int i = 0; i < SIZE; i++) {
        vehicles[i].display();
        cout << "---------------------------------" << endl;
    }

    // Display total number of registered vehicles
    cout << "\nTotal Registered Vehicles : " << Vehicle::getTotalVehicles() << endl;

    return 0;
}
