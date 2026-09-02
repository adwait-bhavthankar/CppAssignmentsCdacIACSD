// 13. Print Numbers - for, while, do-while
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    cout << "\nUsing for loop: ";
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }

    cout << "\nUsing while loop: ";
    int j = 1;
    while (j <= n) {
        cout << j << " ";
        j++;
    }

    cout << "\nUsing do-while loop: ";
    int k = 1;
    do {
        cout << k << " ";
        k++;
    } while (k <= n);

    cout << endl;
    return 0;
}
