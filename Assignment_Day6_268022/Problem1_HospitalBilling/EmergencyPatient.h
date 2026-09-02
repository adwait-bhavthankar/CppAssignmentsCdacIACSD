#ifndef EMERGENCYPATIENT_H
#define EMERGENCYPATIENT_H

#include "InPatient.h"

// =============================================
// Derived class: EmergencyPatient (from InPatient)
// Includes InPatient charges + emergency + ambulance
// =============================================
class EmergencyPatient : public InPatient {
private:
    double emergencyCharges;    // Emergency service charges
    double ambulanceCharges;    // Ambulance service charges
    string emergencyType;       // Type of emergency (e.g., accident, cardiac, etc.)

public:
    // Constructor
    EmergencyPatient(int id, string name, int age, int days,
                     double roomCharge, double doctor, double meds, double treat,
                     double emergency, double ambulance, string type)
        : InPatient(id, name, age, days, roomCharge, doctor, meds, treat),
          emergencyCharges(emergency),
          ambulanceCharges(ambulance),
          emergencyType(type) {}

    // Virtual destructor
    virtual ~EmergencyPatient() {
        cout << "EmergencyPatient destructor called for: " << patientName << endl;
    }

    // Calculate total bill for EmergencyPatient
    // Includes all InPatient charges + emergency + ambulance
    double calculateBill() override {
        return InPatient::calculateBill() + emergencyCharges + ambulanceCharges;
    }

    // Display EmergencyPatient details
    void displayPatientDetails() override {
        InPatient::displayPatientDetails();  // Call InPatient display
        cout << "  ** EMERGENCY DETAILS **" << endl;
        cout << "  Emergency Type   : " << emergencyType << endl;
        cout << "  Emergency Charges: Rs. " << emergencyCharges << endl;
        cout << "  Ambulance Charges: Rs. " << ambulanceCharges << endl;
        cout << "  ** TOTAL BILL (with emergency) : Rs. " << calculateBill() << " **" << endl;
        cout << "-----------------------------------" << endl;
    }

    // Accessors for RTTI-specific display
    double getEmergencyCharges() const { return emergencyCharges; }
    double getAmbulanceCharges() const { return ambulanceCharges; }
    string getEmergencyType() const { return emergencyType; }
};

#endif
