#ifndef INPATIENT_H
#define INPATIENT_H

#include "Patient.h"

// ======================================
// Derived class: InPatient (from Patient)
// Charges: room, doctor, medicines, treatment
// ======================================
class InPatient : public Patient {
protected:
    double roomChargePerDay;    // Room charge per day
    double doctorConsultation;  // Doctor consultation fee
    double medicines;           // Cost of medicines
    double treatment;           // Treatment charges

public:
    // Constructor
    InPatient(int id, string name, int age, int days,
              double roomCharge, double doctor, double meds, double treat)
        : Patient(id, name, age, days),
          roomChargePerDay(roomCharge),
          doctorConsultation(doctor),
          medicines(meds),
          treatment(treat) {}

    // Virtual destructor
    virtual ~InPatient() {
        cout << "InPatient destructor called for: " << patientName << endl;
    }

    // Calculate total bill for InPatient
    double calculateBill() override {
        return (roomChargePerDay * numberOfDaysAdmitted)
               + doctorConsultation
               + medicines
               + treatment;
    }

    // Display InPatient details
    void displayPatientDetails() override {
        Patient::displayPatientDetails();  // Call base class display
        cout << "  Type             : InPatient" << endl;
        cout << "  Room Charge/Day  : Rs. " << roomChargePerDay << endl;
        cout << "  Doctor Fee       : Rs. " << doctorConsultation << endl;
        cout << "  Medicines        : Rs. " << medicines << endl;
        cout << "  Treatment        : Rs. " << treatment << endl;
        cout << "  -----------------------------------" << endl;
        cout << "  TOTAL BILL       : Rs. " << calculateBill() << endl;
        cout << "-----------------------------------" << endl;
    }

    // Accessors for derived class EmergencyPatient
    double getRoomChargePerDay() const { return roomChargePerDay; }
    double getDoctorConsultation() const { return doctorConsultation; }
    double getMedicines() const { return medicines; }
    double getTreatment() const { return treatment; }
};

#endif
