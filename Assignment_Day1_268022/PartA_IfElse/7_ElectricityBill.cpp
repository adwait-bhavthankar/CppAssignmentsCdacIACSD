// 7. Simple Electricity Bill
// Slabs:
//   First 100 units  : Rs. 5 per unit
//   101-200 units    : Rs. 7 per unit
//   201-300 units    : Rs. 9 per unit
//   Above 300 units  : Rs. 12 per unit
#include <iostream>
using namespace std;

int main() {
    int units;
    double bill = 0.0;

    cout << "Enter electricity units consumed: ";
    cin >> units;

    if (units < 0) {
        cout << "Invalid units!" << endl;
        return 0;
    }

    if (units <= 100) {
        bill = units * 5.0;
    } else if (units <= 200) {
        bill = 100 * 5.0 + (units - 100) * 7.0;
    } else if (units <= 300) {
        bill = 100 * 5.0 + 100 * 7.0 + (units - 200) * 9.0;
    } else {
        bill = 100 * 5.0 + 100 * 7.0 + 100 * 9.0 + (units - 300) * 12.0;
    }

    cout << "Units consumed       : " << units << endl;
    cout << "Total bill           : Rs. " << bill << endl;
    cout << "Slabs used           :" << endl;
    cout << "  First 100 units    : Rs. 5/unit" << endl;
    cout << "  101-200 units      : Rs. 7/unit" << endl;
    cout << "  201-300 units      : Rs. 9/unit" << endl;
    cout << "  Above 300 units    : Rs. 12/unit" << endl;

    return 0;
}
