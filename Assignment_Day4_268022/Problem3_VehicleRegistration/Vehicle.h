#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

// ============================
// Class: Vehicle
// Stores vehicle details
// Uses a static member to count registrations
// ============================
class Vehicle {
private:
    string registrationNumber;
    string ownerName;
    string vehicleType;

    // Static data member shared by all Vehicle objects
    static int totalVehicles;

public:
    // Parameterized constructor
    Vehicle(string regNo = "N/A", string name = "Unknown", string type = "N/A") {
        registrationNumber = regNo;
        ownerName = name;
        vehicleType = type;
        totalVehicles++;  // Increment count on each creation
    }

    // Display vehicle details
    void displayVehicle() const {
        cout << "  Registration Number : " << registrationNumber << endl;
        cout << "  Owner Name          : " << ownerName << endl;
        cout << "  Vehicle Type        : " << vehicleType << endl;
    }

    // Static member function to display the total count
    static void displayTotalVehicles() {
        cout << "\n>> Total Registered Vehicles: " << totalVehicles << endl;
    }

    // Static member function to get the count
    static int getTotalVehicles() { return totalVehicles; }
};

// Initialize the static data member
int Vehicle::totalVehicles = 0;

#endif
