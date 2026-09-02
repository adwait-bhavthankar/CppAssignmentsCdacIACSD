// Dynamic Memory Allocation - Integer Array (menu driven)
#include <iostream>
using namespace std;

void acceptArray(int* arr, int n) {
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }
}

void displayArray(int* arr, int n) {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void findLargestSmallest(int* arr, int n) {
    int largest = arr[0], smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) largest = arr[i];
        if (arr[i] < smallest) smallest = arr[i];
    }
    cout << "Largest element  : " << largest << endl;
    cout << "Smallest element : " << smallest << endl;
}

void sumAndAverage(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << "Sum     : " << sum << endl;
    cout << "Average : " << (double)sum / n << endl;
}

void countEvenOdd(int* arr, int n) {
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    cout << "Even count : " << even << endl;
    cout << "Odd count  : " << odd << endl;
}

void linearSearch(int* arr, int n, int key) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << key << " found at index " << i << "." << endl;
            found = true;
        }
    }
    if (!found) {
        cout << key << " not found in the array." << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of elements (N): ";
    cin >> n;

    int* arr = new int[n];

    int choice;
    do {
        cout << "\n=== INTEGER ARRAY MENU ===" << endl;
        cout << "1. Accept and display array elements" << endl;
        cout << "2. Find largest and smallest elements" << endl;
        cout << "3. Calculate sum and average" << endl;
        cout << "4. Count even and odd elements" << endl;
        cout << "5. Linear search for an element" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                acceptArray(arr, n);
                displayArray(arr, n);
                break;
            case 2:
                findLargestSmallest(arr, n);
                break;
            case 3:
                sumAndAverage(arr, n);
                break;
            case 4:
                countEvenOdd(arr, n);
                break;
            case 5: {
                int key;
                cout << "Enter element to search: ";
                cin >> key;
                linearSearch(arr, n, key);
                break;
            }
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    delete[] arr;
    return 0;
}
