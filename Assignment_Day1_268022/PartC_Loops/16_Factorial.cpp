// 16. Factorial
#include <iostream>
using namespace std;

int main() {
    int n;
    long long fact = 1;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial not defined for negative numbers!" << endl;
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        fact *= i;
    }

    cout << "Factorial of " << n << " = " << fact << endl;
    return 0;
}
