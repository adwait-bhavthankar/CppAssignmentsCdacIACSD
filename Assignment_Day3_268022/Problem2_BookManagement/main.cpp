// =====================================================
// Problem 2: Book Management System
// Demonstrates: class, constructor, array of objects,
// search for a book using its ID
// =====================================================

#include <iostream>
#include "Book.h"

using namespace std;

int main() {
    const int SIZE = 5;  // Number of books

    // Create an array of Book objects
    Book books[SIZE] = {
        Book(101, "The Great Gatsby", "F. Scott Fitzgerald", 450.0),
        Book(102, "1984", "George Orwell", 320.5),
        Book(103, "To Kill a Mockingbird", "Harper Lee", 540.0),
        Book(104, "The Alchemist", "Paulo Coelho", 275.75),
        Book(105, "Sapiens", "Yuval Noah Harari", 680.0)
    };

    cout << "========== BOOK MANAGEMENT SYSTEM ==========" << endl;

    // Display all books
    cout << "\n--- All Books ---" << endl;
    for (int i = 0; i < SIZE; i++) {
        books[i].display();
        cout << "---------------------------------" << endl;
    }

    // Search for a book using its ID
    int searchId;
    cout << "\nEnter Book ID to search: ";
    cin >> searchId;

    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (books[i].getBookId() == searchId) {
            cout << "\n--- Book Found ---" << endl;
            books[i].display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\n>> Book with ID " << searchId << " not found!" << endl;
    }

    return 0;
}
