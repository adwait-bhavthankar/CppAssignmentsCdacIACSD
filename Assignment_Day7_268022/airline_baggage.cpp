#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class FlightTicket {
protected:
    string passengerName;
    string flightNumber;
    double baseFare;
    int baggageCount;
    double totalWeightKg;

public:
    FlightTicket(string name, string flightNo, double fare, int bags, double weight)
        : passengerName(name), flightNumber(flightNo), baseFare(fare),
          baggageCount(bags), totalWeightKg(weight) {}

    virtual ~FlightTicket() {}

    virtual double calculateTotalFare() = 0;
    virtual void printBoardingPass() = 0;

    double getBaseFare() const { return baseFare; }
    string getPassengerName() const { return passengerName; }
    string getFlightNumber() const { return flightNumber; }
    int getBaggageCount() const { return baggageCount; }
    double getTotalWeightKg() const { return totalWeightKg; }
};

class EconomyTicket : public FlightTicket {
    double extraBagFeePerKg;
    double seatSelectionFee;

public:
    EconomyTicket(string name, string flightNo, double fare, int bags, double weight,
                  double extraFee, double seatFee)
        : FlightTicket(name, flightNo, fare, bags, weight),
          extraBagFeePerKg(extraFee), seatSelectionFee(seatFee) {}

    double calculateTotalFare() override {
        double excessCharges = 0.0;

        if (baggageCount > 1) {
            excessCharges += (baggageCount - 1) * 50.0;
        }

        if (totalWeightKg > 15.0) {
            excessCharges += (totalWeightKg - 15.0) * extraBagFeePerKg;
        }

        return baseFare + seatSelectionFee + excessCharges;
    }

    void printBoardingPass() override {
        double totalFare = calculateTotalFare();
        double excessCharges = totalFare - baseFare - seatSelectionFee;
        double extraBagFee = (baggageCount > 1) ? (baggageCount - 1) * 50.0 : 0.0;
        double extraWeightFee = (totalWeightKg > 15.0) ? (totalWeightKg - 15.0) * extraBagFeePerKg : 0.0;

        cout << fixed << setprecision(2);
        cout << "[BOARDING PASS - ECONOMY CLASS]" << endl;
        cout << "Passenger        : " << passengerName << endl;
        cout << "Flight Number    : " << flightNumber << endl;
        cout << "Base Fare        : $" << baseFare << endl;
        cout << "Seat Surcharge   : $" << seatSelectionFee << endl;

        if (excessCharges > 0) {
            cout << "Baggage Charge   : $" << excessCharges;
            bool hasExtraBag = extraBagFee > 0;
            bool hasExcessWeight = extraWeightFee > 0;
            cout << " (";
            if (hasExtraBag) {
                cout << (baggageCount - 1) << " Extra Bag: $" << extraBagFee;
                if (hasExcessWeight) cout << " + ";
            }
            if (hasExcessWeight) {
                cout << (totalWeightKg - 15.0) << "kg Excess: $" << extraWeightFee;
            }
            cout << ")" << endl;
        } else {
            cout << "Baggage Charge   : $0.00 (Within Allowance)" << endl;
        }

        cout << "TOTAL FARE       : $" << totalFare << endl;
    }

    double getExtraBagFee() const { return extraBagFeePerKg; }
    double getSeatSelectionFee() const { return seatSelectionFee; }
};

class BusinessTicket : public FlightTicket {
    double loungeAccessFee;
    double priorityBoardingFee;

public:
    BusinessTicket(string name, string flightNo, double fare, int bags, double weight,
                   double loungeFee, double priorityFee)
        : FlightTicket(name, flightNo, fare, bags, weight),
          loungeAccessFee(loungeFee), priorityBoardingFee(priorityFee) {}

    double calculateTotalFare() override {
        double excessCharges = 0.0;

        if (totalWeightKg > 32.0) {
            excessCharges = (totalWeightKg - 32.0) * 20.0;
        }

        return baseFare + loungeAccessFee + priorityBoardingFee + excessCharges;
    }

    void printBoardingPass() override {
        double totalFare = calculateTotalFare();
        double excessCharges = totalFare - baseFare - loungeAccessFee - priorityBoardingFee;

        cout << fixed << setprecision(2);
        cout << "[BOARDING PASS - BUSINESS CLASS]" << endl;
        cout << "Passenger        : " << passengerName << endl;
        cout << "Flight Number    : " << flightNumber << endl;
        cout << "Base Fare        : $" << baseFare << endl;
        cout << "VIP Amenities    : Lounge ($" << loungeAccessFee << ") + Priority Boarding ($"
             << priorityBoardingFee << ")" << endl;

        if (excessCharges > 0) {
            cout << "Baggage Charge   : $" << excessCharges << " ("
                 << (totalWeightKg - 32.0) << "kg Excess @ $20/kg)" << endl;
        } else {
            cout << "Baggage Charge   : $0.00 (Within Allowance)" << endl;
        }

        cout << "TOTAL FARE       : $" << totalFare << endl;
    }

    double getLoungeAccessFee() const { return loungeAccessFee; }
    double getPriorityBoardingFee() const { return priorityBoardingFee; }
};

class FirstClassTicket : public FlightTicket {
    double conciergeServiceFee;

public:
    FirstClassTicket(string name, string flightNo, double fare, int bags, double weight, double conciergeFee)
        : FlightTicket(name, flightNo, fare, bags, weight), conciergeServiceFee(conciergeFee) {}

    double calculateTotalFare() override {
        double penalty = 0.0;

        if (totalWeightKg > 50.0) {
            penalty = 100.0;
        }

        return baseFare + conciergeServiceFee + penalty;
    }

    void printBoardingPass() override {
        double totalFare = calculateTotalFare();
        double penalty = (totalWeightKg > 50.0) ? 100.0 : 0.0;

        cout << fixed << setprecision(2);
        cout << "[BOARDING PASS - FIRST CLASS]" << endl;
        cout << "Passenger        : " << passengerName << endl;
        cout << "Flight Number    : " << flightNumber << endl;
        cout << "Base Fare        : $" << baseFare << endl;
        cout << "Concierge Fee    : $" << conciergeServiceFee << endl;

        if (penalty > 0) {
            cout << "Baggage Charge   : $" << penalty << " (Exceeds 50kg Limit)" << endl;
        } else {
            cout << "Baggage Charge   : $0.00 (Within 50kg Complimentary Allowance)" << endl;
        }

        cout << "TOTAL FARE       : $" << totalFare << endl;
    }

    double getConciergeServiceFee() const { return conciergeServiceFee; }
};

int main() {
    int N;

    cout << "=== GLOBAL AIRLINES RESERVATION & BAGGAGE ENGINE ===" << endl;
    cout << "Enter number of passenger bookings to process: ";
    cin >> N;

    FlightTicket** manifest = new FlightTicket*[N];

    for (int i = 0; i < N; ++i) {
        int choice;
        string name, flightNo;
        double fare;
        int baggageCount;
        double totalWeight;

        cout << "\n--- Passenger #" << (i + 1) << " Entry ---" << endl;
        cout << "Select Fare Class (1: Economy, 2: Business, 3: First Class): ";
        cin >> choice;
        cout << "Enter Passenger Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Flight Number: ";
        cin >> flightNo;
        cout << "Enter Base Fare ($): ";
        cin >> fare;
        cout << "Enter Baggage Count: ";
        cin >> baggageCount;
        cout << "Enter Total Baggage Weight (kg): ";
        cin >> totalWeight;

        switch (choice) {
            case 1: {
                double extraFee, seatFee;
                cout << "Enter Extra Bag Fee Rate ($/kg): ";
                cin >> extraFee;
                cout << "Enter Seat Selection Fee ($): ";
                cin >> seatFee;
                manifest[i] = new EconomyTicket(name, flightNo, fare, baggageCount, totalWeight, extraFee, seatFee);
                break;
            }
            case 2: {
                double loungeFee, priorityFee;
                cout << "Enter Lounge Access Fee ($): ";
                cin >> loungeFee;
                cout << "Enter Priority Boarding Fee ($): ";
                cin >> priorityFee;
                manifest[i] = new BusinessTicket(name, flightNo, fare, baggageCount, totalWeight, loungeFee, priorityFee);
                break;
            }
            case 3: {
                double conciergeFee;
                cout << "Enter Concierge Service Fee ($): ";
                cin >> conciergeFee;
                manifest[i] = new FirstClassTicket(name, flightNo, fare, baggageCount, totalWeight, conciergeFee);
                break;
            }
            default:
                cout << "Invalid choice. Defaulting to Economy." << endl;
                manifest[i] = new EconomyTicket(name, flightNo, fare, baggageCount, totalWeight, 15.0, 25.0);
                break;
        }
    }

    cout << "\n==================== FLIGHT BOARDING MANIFEST ====================" << endl;

    double totalRevenue = 0.0;
    for (int i = 0; i < N; ++i) {
        manifest[i]->printBoardingPass();
        totalRevenue += manifest[i]->calculateTotalFare();
        if (i < N - 1) {
            cout << "------------------------------------------------------------------" << endl;
        }
    }

    cout << "==================================================================" << endl;
    cout << "FLIGHT MANIFEST REVENUE SUMMARY:" << endl;
    cout << "Total Passengers Checked In : " << N << endl;
    cout << fixed << setprecision(2);
    cout << "Total Revenue Collected     : $" << totalRevenue << endl;
    cout << "==================================================================" << endl;

    for (int i = 0; i < N; ++i) {
        delete manifest[i];
    }
    delete[] manifest;
    manifest = nullptr;

    cout << "Memory cleaned up successfully. " << N << " passenger objects deallocated." << endl;

    return 0;
}
