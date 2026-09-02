// 17. Reverse a Number
#include <iostream>
using namespace std;

int main() {
    int n;
    int reversed = 0;

    cout << "Enter an integer: ";
    cin >> n;

    int temp = n;
    while (temp != 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    cout << "Reverse of " << n << " = " << reversed << endl;
    return 0;
}
