// 20. Sum of Digits
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    int sum = 0;
    int singleSum = (n < 0) ? -n : n;

    while (singleSum != 0) {
        sum += singleSum % 10;
        singleSum /= 10;
    }

    cout << "Sum of digits of " << n << " = " << sum << endl;
    return 0;
}
