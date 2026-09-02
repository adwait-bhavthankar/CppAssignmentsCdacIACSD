// Dynamic Memory Allocation - Product Prices (menu driven)
#include <iostream>
using namespace std;

void acceptPrices(double* prices, int n) {
    cout << "Enter price of " << n << " products:\n";
    for (int i = 0; i < n; i++) {
        cout << "Product " << (i + 1) << " price: ";
        cin >> prices[i];
    }
}

void displayPrices(double* prices, int n) {
    cout << "Product prices: ";
    for (int i = 0; i < n; i++) {
        cout << prices[i] << " ";
    }
    cout << endl;
}

void highestLowest(double* prices, int n) {
    double highest = prices[0], lowest = prices[0];
    int hiIdx = 0, loIdx = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] > highest) { highest = prices[i]; hiIdx = i; }
        if (prices[i] < lowest) { lowest = prices[i]; loIdx = i; }
    }
    cout << "Highest-priced product : Product " << (hiIdx + 1)
         << " = Rs. " << highest << endl;
    cout << "Lowest-priced product  : Product " << (loIdx + 1)
         << " = Rs. " << lowest << endl;
}

void inventoryValue(double* prices, int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += prices[i];
    }
    cout << "Total inventory value : Rs. " << total << endl;
    cout << "Average product price : Rs. " << total / n << endl;
}

void aboveBelowAverage(double* prices, int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += prices[i];
    }
    double avg = total / n;

    int above = 0, below = 0;
    for (int i = 0; i < n; i++) {
        if (prices[i] > avg) above++;
        else if (prices[i] < avg) below++;
    }

    cout << "Products above average price : " << above << endl;
    cout << "Products below average price : " << below << endl;
}

void searchPrice(double* prices, int n, double key) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (prices[i] == key) {
            cout << "Price Rs. " << key << " found for product " << (i + 1) << "." << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Price Rs. " << key << " not found." << endl;
    }
}

void applyDiscount(double* prices, int n) {
    double discount;
    cout << "Enter discount percentage: ";
    cin >> discount;

    for (int i = 0; i < n; i++) {
        prices[i] = prices[i] * (1.0 - discount / 100.0);
    }

    cout << "Discount applied. Updated prices:\n";
    displayPrices(prices, n);
}

int main() {
    int n;
    cout << "Enter number of products (N): ";
    cin >> n;

    double* prices = new double[n];

    int choice;
    do {
        cout << "\n=== PRODUCT PRICE MENU ===" << endl;
        cout << "1. Accept and display product prices" << endl;
        cout << "2. Find highest and lowest-priced products" << endl;
        cout << "3. Calculate total inventory value and average price" << endl;
        cout << "4. Count products above and below average price" << endl;
        cout << "5. Search for a product price" << endl;
        cout << "6. Apply discount to all prices" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                acceptPrices(prices, n);
                displayPrices(prices, n);
                break;
            case 2:
                highestLowest(prices, n);
                break;
            case 3:
                inventoryValue(prices, n);
                break;
            case 4:
                aboveBelowAverage(prices, n);
                break;
            case 5: {
                double key;
                cout << "Enter price to search: ";
                cin >> key;
                searchPrice(prices, n, key);
                break;
            }
            case 6:
                applyDiscount(prices, n);
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    delete[] prices;
    return 0;
}
