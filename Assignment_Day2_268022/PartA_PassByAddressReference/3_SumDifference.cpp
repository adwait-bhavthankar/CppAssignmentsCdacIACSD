// 3. Sum and difference via reference parameters
#include <iostream>
using namespace std;

void calculate(int a, int b, int& sum, int& diff) {
    sum = a + b;
    diff = a - b;
}

int main() {
    int x, y;
    int sum, diff;

    cout << "Enter two integers: ";
    cin >> x >> y;

    calculate(x, y, sum, diff);

    cout << "Sum       : " << x << " + " << y << " = " << sum << endl;
    cout << "Difference: " << x << " - " << y << " = " << diff << endl;

    return 0;
}
