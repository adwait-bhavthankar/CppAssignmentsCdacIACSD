// 19. Count Digits
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    int count = 0;
    if (n == 0) {
        count = 1;
    } else {
        int temp = n;
        while (temp != 0) {
            temp /= 10;
            count++;
        }
    }

    cout << "Number of digits in " << n << ": " << count << endl;
    return 0;
}
