// 18. Palindrome Number
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    int original = n;
    int reversed = 0;
    int temp = n;

    while (temp != 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    if (original == reversed) {
        cout << original << " is a palindrome." << endl;
    } else {
        cout << original << " is not a palindrome." << endl;
    }

    return 0;
}
