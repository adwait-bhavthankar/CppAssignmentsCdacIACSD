#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
using namespace std;

// ============================
// Base class: Patient
// Stores common patient details
// ============================
class Patient {
protected:
    int patientId;
    string patientName;
    int age;
    int numberOfDaysAdmitted;

public:
    // Constructor
    Patient(int id, string name, int age, int days)
        : patientId(id), patientName(name), age(age), numberOfDaysAdmitted(days) {}

    // Virtual destructor for proper cleanup of derived objects
    virtual ~Patient() {
        cout << "Patient destructor called for: " << patientName << endl;
    }

    // Pure virtual function - must be overridden by derived classes
    virtual double calculateBill() = 0;

    // Virtual function to display patient details
    virtual void displayPatientDetails() {
        cout << "-----------------------------------" << endl;
        cout << "  Patient ID       : " << patientId << endl;
        cout << "  Patient Name     : " << patientName << endl;
        cout << "  Age              : " << age << endl;
        cout << "  Days Admitted    : " << numberOfDaysAdmitted << endl;
    }

    // Get patient name (used for RTTI display)
    string getPatientName() const { return patientName; }
};

#endif
