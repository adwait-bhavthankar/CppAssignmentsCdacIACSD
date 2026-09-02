// =====================================================
// Problem 3: Vehicle Registration System
// Demonstrates: class, constructor, static data member
// and static member function, array of objects
// =====================================================

#include <iostream>
#include "Vehicle.h"

using namespace std;

int main() {
    const int SIZE = 4;  // Number of vehicles

    cout << "========== VEHICLE REGISTRATION SYSTEM ==========" << endl;

    // Create an array of Vehicle objects
    Vehicle vehicles[SIZE] = {
        Vehicle("MH12AB1234", "Alice Johnson", "Car"),
        Vehicle("MH01CD5678", "Bob Smith", "Motorcycle"),
        Vehicle("KA05EF9012", "Carol Davis", "Truck"),
        Vehicle("DL08GH3456", "David Wilson", "Car")
    };

    // Display all vehicle records
    cout << "\n--- All Registered Vehicles ---" << endl;
    for (int i = 0; i < SIZE; i++) {
        vehicles[i].displayVehicle();
        cout << "---------------------------------" << endl;
    }

    // Display the total number of registered vehicles (via static member)
    cout << "\n--- Registration Count ---" << endl;
    Vehicle::displayTotalVehicles();

    return 0;
}
