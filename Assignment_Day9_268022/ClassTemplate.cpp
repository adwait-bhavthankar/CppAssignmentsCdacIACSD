#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


// 1. SafeArray Template Class

template <typename T>
class SafeArray {
private:
    T* data;              // Pointer to the heap array
    int capacity;         // Total available space
    int currentSize;      // Number of elements currently added

    // Helper function to double array size when full
    void resize() {
        int newCapacity = capacity * 2;
        cout << "Dynamic resize triggered: Capacity " << capacity << " -> " << newCapacity << "." << endl;

        // Step 1: Allocate a bigger room
        T* newData = new T[newCapacity];

        // Step 2: Copy items over
        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i];
        }

        // Step 3: Free the old array
        delete[] data;

        // Step 4: Point to the new array
        data = newData;
        capacity = newCapacity;
    }

public:
    // Default Constructor: start with 4 slots
    SafeArray() {
        capacity = 4;
        currentSize = 0;
        data = new T[capacity];
    }

    // Parameterized Constructor
    SafeArray(int initCapacity) {
        if (initCapacity <= 0) {
            capacity = 4;
        } else {
            capacity = initCapacity;
        }
        currentSize = 0;
        data = new T[capacity];
    }

    // Destructor: Clean up memory when object dies
    ~SafeArray() {
        delete[] data;
    }

    // Copy Constructor: Deep copy
    SafeArray(const SafeArray<T>& other) {
        capacity = other.capacity;
        currentSize = other.currentSize;
        data = new T[capacity];
        for (int i = 0; i < currentSize; i++) {
            data[i] = other.data[i];
        }
    }

    // Assignment Operator: Deep copy
    SafeArray<T>& operator=(const SafeArray<T>& other) {
        if (this != &other) { // Avoid self-assignment like a = a
            delete[] data;    // Delete own old data first

            capacity = other.capacity;
            currentSize = other.currentSize;
            data = new T[capacity];
            for (int i = 0; i < currentSize; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Add item at the end
    void push_back(T element) {
        if (currentSize == capacity) {
            resize();
        }
        data[currentSize] = element;
        currentSize++;
    }

    // Remove last item
    void pop_back() {
        if (currentSize > 0) {
            currentSize--;
        }
    }

    int size() {
        return currentSize;
    }

    int getCapacity() {
        return capacity;
    }

    // Array indexing: arr[index]
    T& operator[](int index) {
        // Defensive bounds check
        if (index < 0 || index >= currentSize) {
            throw out_of_range("Index " + to_string(index) + " out of bounds!");
        }
        return data[index];
    }
};


// 2. Custom Product Class for Testing

class Product {
private:
    int id;
    string name;
    double price;

public:
    // Default constructor (Mandatory so "new T[size]" works)
    Product() {
        id = 0;
        name = "";
        price = 0.0;
    }

    Product(int i, string n, double p) {
        id = i;
        name = n;
        price = p;
    }

    void display() {
        cout << "[ID: " << id << ", Name: " << name << ", Price: $" << price << "]";
    }
};


// 3. Main Function

int main() {

    // Test 1: Testing with Product class

    cout << "SafeArray<Product> Initialized." << endl;
    SafeArray<Product> products;

    products.push_back(Product(101, "Phone", 699.99));
    products.push_back(Product(102, "Tablet", 499.99));
    products.push_back(Product(103, "Laptop", 899.99));
    products.push_back(Product(104, "Monitor", 199.99));

    // The 5th item exceeds initial capacity of 4 -> triggers resize
    products.push_back(Product(105, "Keyboard", 49.99));
    cout << "Pushed 5 items." << endl;

    // Normal safe access
    cout << "Element at index 2: ";
    products[2].display();
    cout << endl;

    // Out-of-bounds access caught with try-catch
    try {
        cout << "Attempting access at index 10 -> ";
        products[10].display();
    }
    catch (out_of_range& e) {
        cout << "Exception Caught: " << e.what() << endl;
    }

 
    // Test 2: Testing with primitive int
    cout << "\nSafeArray<int> Testing:" << endl;
    SafeArray<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    cout << "Item at index 1: " << numbers[1] << endl;
    cout << "Size: " << numbers.size() << ", Capacity: " << numbers.getCapacity() << endl;


    // Test 3: Testing with string

    cout << "\nSafeArray<string> Testing:" << endl;
    SafeArray<string> words;
    words.push_back("Hello");
    words.push_back("World");

    cout << "Item at index 0: " << words[0] << endl;

    return 0;
}