// 4. Reverse digits via reference parameter
#include <iostream>
using namespace std;

void reverseDigits(int& num) {
    int reversed = 0;
    int temp = num;

    while (temp != 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    num = reversed;
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    cout << "Original number: " << n << endl;
    reverseDigits(n);
    cout << "Reversed number: " << n << endl;

    return 0;
}
