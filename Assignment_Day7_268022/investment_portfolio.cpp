#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

class InvestmentAsset {
protected:
    string assetTicker;
    string assetName;
    double initialPrincipal;

public:
    InvestmentAsset(string ticker, string name, double principal)
        : assetTicker(ticker), assetName(name), initialPrincipal(principal) {}

    virtual ~InvestmentAsset() {}

    virtual double calculateProjectedValue(int durationYears) = 0;
    virtual double calculateRiskScore() = 0;
    virtual void displayStatement(int durationYears) = 0;

    double getInitialPrincipal() const { return initialPrincipal; }
};

class EquityStock : public InvestmentAsset {
    double annualGrowthRate;
    double dividendYield;
    double beta;

public:
    EquityStock(string ticker, string name, double principal, double growth, double dividend, double b)
        : InvestmentAsset(ticker, name, principal), annualGrowthRate(growth),
          dividendYield(dividend), beta(b) {}

    double calculateProjectedValue(int durationYears) override {
        return initialPrincipal * pow(1.0 + annualGrowthRate + dividendYield, durationYears);
    }

    double calculateRiskScore() override {
        double score = beta * 4.5;
        return max(1.0, min(10.0, score));
    }

    void displayStatement(int durationYears) override {
        double projected = calculateProjectedValue(durationYears);
        double riskScore = calculateRiskScore();
        double growth = ((projected - initialPrincipal) / initialPrincipal) * 100.0;

        string volatility;
        if (riskScore < 3.0) volatility = "Low Volatility";
        else if (riskScore < 5.0) volatility = "Low-Moderate Volatility";
        else if (riskScore < 7.0) volatility = "Moderate-High Volatility";
        else volatility = "High Volatility";

        cout << fixed << setprecision(2);
        cout << "[Equity Stock] " << assetTicker << " - " << assetName << endl;
        cout << "Initial Principal   : $" << initialPrincipal << endl;
        cout << "Projected (" << durationYears << " Yrs)  : $" << projected
             << " (Net Growth: " << growth << "%)" << endl;
        cout << "Risk Score          : " << riskScore << " / 10.00 (" << volatility << ")" << endl;
    }
};

class RealEstateTrust : public InvestmentAsset {
    double rentalCapRate;
    double propertyAppreciationRate;
    double managementFeeRate;

public:
    RealEstateTrust(string ticker, string name, double principal, double rental, double appreciation, double mgmt)
        : InvestmentAsset(ticker, name, principal), rentalCapRate(rental),
          propertyAppreciationRate(appreciation), managementFeeRate(mgmt) {}

    double calculateProjectedValue(int durationYears) override {
        double netRate = rentalCapRate + propertyAppreciationRate - managementFeeRate;
        return initialPrincipal * pow(1.0 + netRate, durationYears);
    }

    double calculateRiskScore() override {
        return 3.5;
    }

    void displayStatement(int durationYears) override {
        double projected = calculateProjectedValue(durationYears);
        double riskScore = calculateRiskScore();
        double growth = ((projected - initialPrincipal) / initialPrincipal) * 100.0;

        cout << fixed << setprecision(2);
        cout << "[Real Estate] " << assetTicker << " - " << assetName << endl;
        cout << "Initial Principal   : $" << initialPrincipal << endl;
        cout << "Projected (" << durationYears << " Yrs)  : $" << projected
             << " (Net Growth: " << growth << "%)" << endl;
        cout << "Risk Score          : " << riskScore << " / 10.00 (Low-Moderate Volatility)" << endl;
    }
};

class CryptoStaking : public InvestmentAsset {
    double stakingAPY;
    double networkSlashingPenaltyRate;

public:
    CryptoStaking(string ticker, string name, double principal, double apy, double penalty)
        : InvestmentAsset(ticker, name, principal), stakingAPY(apy),
          networkSlashingPenaltyRate(penalty) {}

    double calculateProjectedValue(int durationYears) override {
        double effectiveYield = stakingAPY - networkSlashingPenaltyRate;
        return initialPrincipal * pow(1.0 + effectiveYield, durationYears);
    }

    double calculateRiskScore() override {
        return 8.5;
    }

    void displayStatement(int durationYears) override {
        double projected = calculateProjectedValue(durationYears);
        double riskScore = calculateRiskScore();
        double growth = ((projected - initialPrincipal) / initialPrincipal) * 100.0;

        cout << fixed << setprecision(2);
        cout << "[Crypto Staking] " << assetTicker << " - " << assetName << endl;
        cout << "Initial Principal   : $" << initialPrincipal << endl;
        cout << "Projected (" << durationYears << " Yrs)  : $" << projected
             << " (Net Growth: " << growth << "%)" << endl;
        cout << "Risk Score          : " << riskScore << " / 10.00 (High Risk/Yield)" << endl;
    }
};

int main() {
    int N, durationYears;

    cout << "=== AUTOMATED INVESTMENT PORTFOLIO & YIELD ANALYZER ===" << endl;
    cout << "Enter number of assets (N): ";
    cin >> N;
    cout << "Enter investment duration horizon (years): ";
    cin >> durationYears;

    InvestmentAsset** portfolio = new InvestmentAsset*[N];

    for (int i = 0; i < N; ++i) {
        int choice;
        string ticker, name;
        double principal;

        cout << "\n--- Asset #" << (i + 1) << " Entry ---" << endl;
        cout << "Select Type (1: Equity Stock, 2: REIT, 3: Crypto Staking): ";
        cin >> choice;
        cout << "Enter Ticker: ";
        cin >> ticker;
        cout << "Enter Asset Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Initial Principal ($): ";
        cin >> principal;

        switch (choice) {
            case 1: {
                double growth, dividend, beta;
                cout << "Enter Expected Annual Growth Rate (e.g. 0.10 for 10%): ";
                cin >> growth;
                cout << "Enter Annual Dividend Yield (e.g. 0.015 for 1.5%): ";
                cin >> dividend;
                cout << "Enter Beta: ";
                cin >> beta;
                portfolio[i] = new EquityStock(ticker, name, principal, growth, dividend, beta);
                break;
            }
            case 2: {
                double rental, appreciation, mgmt;
                cout << "Enter Rental Cap Rate: ";
                cin >> rental;
                cout << "Enter Property Appreciation Rate: ";
                cin >> appreciation;
                cout << "Enter Management Fee Rate: ";
                cin >> mgmt;
                portfolio[i] = new RealEstateTrust(ticker, name, principal, rental, appreciation, mgmt);
                break;
            }
            case 3: {
                double apy, penalty;
                cout << "Enter Staking APY: ";
                cin >> apy;
                cout << "Enter Network Slashing Risk Penalty: ";
                cin >> penalty;
                portfolio[i] = new CryptoStaking(ticker, name, principal, apy, penalty);
                break;
            }
            default:
                cout << "Invalid choice. Defaulting to Equity Stock." << endl;
                portfolio[i] = new EquityStock(ticker, name, principal, 0.08, 0.02, 1.0);
                break;
        }
    }

    cout << "\n==================== PORTFOLIO PERFORMANCE REPORT ====================" << endl;

    double totalInvested = 0.0;
    double totalProjected = 0.0;
    double weightedRiskSum = 0.0;

    for (int i = 0; i < N; ++i) {
        portfolio[i]->displayStatement(durationYears);
        totalInvested += portfolio[i]->getInitialPrincipal();
        totalProjected += portfolio[i]->calculateProjectedValue(durationYears);
        weightedRiskSum += portfolio[i]->calculateRiskScore() * portfolio[i]->getInitialPrincipal();

        if (i < N - 1) {
            cout << "----------------------------------------------------------------------" << endl;
        }
    }

    double totalProfit = totalProjected - totalInvested;
    double profitPercent = (totalProfit / totalInvested) * 100.0;
    double weightedRisk = weightedRiskSum / totalInvested;

    cout << "=======================================================================" << endl;
    cout << "PORTFOLIO AGGREGATE SUMMARY:" << endl;
    cout << fixed << setprecision(2);
    cout << "Total Invested Principal    : $" << totalInvested << endl;
    cout << "Total Projected Value       : $" << totalProjected << endl;
    cout << "Total Projected Profit      : $" << totalProfit << " (+" << profitPercent << "%)" << endl;
    cout << "Weighted Avg Risk Score     : " << weightedRisk << " / 10.00" << endl;
    cout << "=======================================================================" << endl;

    for (int i = 0; i < N; ++i) {
        delete portfolio[i];
    }
    delete[] portfolio;
    portfolio = nullptr;

    cout << "Memory cleaned up successfully. " << N << " asset instances deallocated." << endl;

    return 0;
}
