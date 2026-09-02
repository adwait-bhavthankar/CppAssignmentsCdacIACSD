// 1. Swap using pointers (pass by address)
#include <iostream>
using namespace std;

void swapByPointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;
    cout << "Enter two integers: ";
    cin >> x >> y;

    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapByPointer(&x, &y);
    cout << "After swap : x = " << x << ", y = " << y << endl;

    return 0;
}
