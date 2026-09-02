// =====================================================
// Problem 1: Hospital Billing System
// Demonstrates: Inheritance, Polymorphism, RTTI
// =====================================================

#include <iostream>
#include <vector>
#include <typeinfo>
#include "Patient.h"
#include "InPatient.h"
#include "OutPatient.h"
#include "EmergencyPatient.h"

using namespace std;

// Function to display menu
void displayMenu() {
    cout << "\n========== HOSPITAL BILLING SYSTEM ==========" << endl;
    cout << "1. Add InPatient" << endl;
    cout << "2. Add OutPatient" << endl;
    cout << "3. Add EmergencyPatient" << endl;
    cout << "4. Display All Patients" << endl;
    cout << "5. Calculate All Bills" << endl;
    cout << "6. Identify Patient Types using RTTI" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    // Vector of Patient pointers to store all patient types
    vector<Patient*> patients;
    int choice;

    do {
        displayMenu();
        if (!(cin >> choice)) break;  // Handle EOF gracefully

        switch (choice) {

        // ---- Add InPatient ----
        case 1: {
            int id, age, days;
            string name;
            double roomCharge, doctor, meds, treat;

            cout << "\n--- Enter InPatient Details ---" << endl;
            cout << "Patient ID: "; cin >> id;
            cin.ignore();
            cout << "Patient Name: "; getline(cin, name);
            cout << "Age: "; cin >> age;
            cout << "Days Admitted: "; cin >> days;
            cout << "Room Charge per Day (Rs.): "; cin >> roomCharge;
            cout << "Doctor Consultation (Rs.): "; cin >> doctor;
            cout << "Medicines (Rs.): "; cin >> meds;
            cout << "Treatment (Rs.): "; cin >> treat;

            // Create InPatient object on heap and store pointer
            patients.push_back(new InPatient(id, name, age, days,
                                             roomCharge, doctor, meds, treat));
            cout << ">> InPatient added successfully!" << endl;
            break;
        }

        // ---- Add OutPatient ----
        case 2: {
            int id, age, days;
            string name;
            double consult, tests, meds;

            cout << "\n--- Enter OutPatient Details ---" << endl;
            cout << "Patient ID: "; cin >> id;
            cin.ignore();
            cout << "Patient Name: "; getline(cin, name);
            cout << "Age: "; cin >> age;
            cout << "Days Visited: "; cin >> days;
            cout << "Consultation Fee (Rs.): "; cin >> consult;
            cout << "Diagnostic Tests (Rs.): "; cin >> tests;
            cout << "Medicines (Rs.): "; cin >> meds;

            // Create OutPatient object on heap and store pointer
            patients.push_back(new OutPatient(id, name, age, days,
                                              consult, tests, meds));
            cout << ">> OutPatient added successfully!" << endl;
            break;
        }

        // ---- Add EmergencyPatient ----
        case 3: {
            int id, age, days;
            string name, emergencyType;
            double roomCharge, doctor, meds, treat, emergency, ambulance;

            cout << "\n--- Enter EmergencyPatient Details ---" << endl;
            cout << "Patient ID: "; cin >> id;
            cin.ignore();
            cout << "Patient Name: "; getline(cin, name);
            cout << "Age: "; cin >> age;
            cout << "Days Admitted: "; cin >> days;
            cout << "Room Charge per Day (Rs.): "; cin >> roomCharge;
            cout << "Doctor Consultation (Rs.): "; cin >> doctor;
            cout << "Medicines (Rs.): "; cin >> meds;
            cout << "Treatment (Rs.): "; cin >> treat;
            cout << "Emergency Charges (Rs.): "; cin >> emergency;
            cout << "Ambulance Charges (Rs.): "; cin >> ambulance;
            cin.ignore();
            cout << "Emergency Type (e.g., Accident, Cardiac): "; getline(cin, emergencyType);

            // Create EmergencyPatient object on heap and store pointer
            patients.push_back(new EmergencyPatient(id, name, age, days,
                                roomCharge, doctor, meds, treat,
                                emergency, ambulance, emergencyType));
            cout << ">> EmergencyPatient added successfully!" << endl;
            break;
        }

        // ---- Display All Patients using polymorphism ----
        case 4: {
            if (patients.empty()) {
                cout << "\n>> No patients found!" << endl;
                break;
            }
            cout << "\n========== ALL PATIENT DETAILS ==========" << endl;
            for (int i = 0; i < patients.size(); i++) {
                // Polymorphic call - calls the correct derived class method
                patients[i]->displayPatientDetails();
            }
            break;
        }

        // ---- Calculate All Bills using polymorphism ----
        case 5: {
            if (patients.empty()) {
                cout << "\n>> No patients found!" << endl;
                break;
            }
            cout << "\n========== BILL SUMMARY ==========" << endl;
            double grandTotal = 0;
            for (int i = 0; i < patients.size(); i++) {
                double bill = patients[i]->calculateBill();
                cout << patients[i]->getPatientName() << " -> Bill: Rs. " << bill << endl;
                grandTotal += bill;
            }
            cout << "-----------------------------------" << endl;
            cout << "Grand Total: Rs. " << grandTotal << endl;
            cout << "===================================" << endl;
            break;
        }

        // ---- RTTI: Identify actual type of each patient ----
        case 6: {
            if (patients.empty()) {
                cout << "\n>> No patients found!" << endl;
                break;
            }
            cout << "\n========== RTTI - PATIENT TYPE IDENTIFICATION ==========" << endl;
            for (int i = 0; i < patients.size(); i++) {
                cout << "\nPatient: " << patients[i]->getPatientName() << endl;

                // Using typeid to get the actual runtime type
                cout << "  Runtime Type (typeid): " << typeid(*patients[i]).name() << endl;

                // Using dynamic_cast to safely identify and access derived class info

                // Check if patient is EmergencyPatient
                EmergencyPatient* emergencyPt = dynamic_cast<EmergencyPatient*>(patients[i]);
                if (emergencyPt != nullptr) {
                    cout << "  ** Identified as: EmergencyPatient **" << endl;
                    cout << "  Emergency Type    : " << emergencyPt->getEmergencyType() << endl;
                    cout << "  Emergency Charges : Rs. " << emergencyPt->getEmergencyCharges() << endl;
                    cout << "  Ambulance Charges : Rs. " << emergencyPt->getAmbulanceCharges() << endl;
                }
                // Check if patient is InPatient
                else {
                    InPatient* inPt = dynamic_cast<InPatient*>(patients[i]);
                    if (inPt != nullptr) {
                        cout << "  ** Identified as: InPatient **" << endl;
                        cout << "  Room Charge/Day  : Rs. " << inPt->getRoomChargePerDay() << endl;
                        cout << "  Doctor Fee       : Rs. " << inPt->getDoctorConsultation() << endl;
                        cout << "  Medicines        : Rs. " << inPt->getMedicines() << endl;
                        cout << "  Treatment        : Rs. " << inPt->getTreatment() << endl;
                    }
                    // Check if patient is OutPatient
                    else {
                        OutPatient* outPt = dynamic_cast<OutPatient*>(patients[i]);
                        if (outPt != nullptr) {
                            cout << "  ** Identified as: OutPatient **" << endl;
                        }
                    }
                }
            }
            cout << "\n========================================================" << endl;
            break;
        }

        // ---- Exit and clean up memory ----
        case 7: {
            cout << "\n>> Cleaning up memory..." << endl;
            // Delete all dynamically allocated patient objects
            for (int i = 0; i < patients.size(); i++) {
                delete patients[i];
            }
            patients.clear();
            cout << ">> Thank you for using Hospital Billing System!" << endl;
            break;
        }

        default:
            cout << "\n>> Invalid choice! Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
