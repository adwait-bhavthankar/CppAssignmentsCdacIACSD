#ifndef OUTPATIENT_H
#define OUTPATIENT_H

#include "Patient.h"

// ======================================
// Derived class: OutPatient (from Patient)
// Charges: consultation, diagnostic tests, medicines
// ======================================
class OutPatient : public Patient {
private:
    double consultationFee;    // Doctor consultation fee
    double diagnosticTests;    // Cost of diagnostic tests
    double medicines;          // Cost of medicines

public:
    // Constructor
    OutPatient(int id, string name, int age, int days,
               double consult, double tests, double meds)
        : Patient(id, name, age, days),
          consultationFee(consult),
          diagnosticTests(tests),
          medicines(meds) {}

    // Virtual destructor
    virtual ~OutPatient() {
        cout << "OutPatient destructor called for: " << patientName << endl;
    }

    // Calculate total bill for OutPatient
    double calculateBill() override {
        return consultationFee + diagnosticTests + medicines;
    }

    // Display OutPatient details
    void displayPatientDetails() override {
        Patient::displayPatientDetails();  // Call base class display
        cout << "  Type             : OutPatient" << endl;
        cout << "  Consultation Fee : Rs. " << consultationFee << endl;
        cout << "  Diagnostic Tests : Rs. " << diagnosticTests << endl;
        cout << "  Medicines        : Rs. " << medicines << endl;
        cout << "  -----------------------------------" << endl;
        cout << "  TOTAL BILL       : Rs. " << calculateBill() << endl;
        cout << "-----------------------------------" << endl;
    }
};

#endif
