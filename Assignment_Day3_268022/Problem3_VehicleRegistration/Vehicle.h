#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

// ============================
// Class: Vehicle
// Stores vehicle registration details
// Maintains static count of registered vehicles
// ============================
class Vehicle {
private:
    string registrationNumber;
    string ownerName;
    string vehicleType;

public:
    // Static member to count total registered vehicles
    static int totalVehicles;

    // Parameterized constructor
    Vehicle(string regNo = "Unknown", string owner = "Unknown", string type = "Unknown")
        : registrationNumber(regNo), ownerName(owner), vehicleType(type) {
        totalVehicles++;
    }

    // Display vehicle details
    void display() const {
        cout << "  Registration Number : " << registrationNumber << endl;
        cout << "  Owner Name          : " << ownerName << endl;
        cout << "  Vehicle Type        : " << vehicleType << endl;
    }

    // Static accessor
    static int getTotalVehicles() { return totalVehicles; }
};

// Initialize static member
int Vehicle::totalVehicles = 0;

#endif
