// =====================================================
// Problem 2: Book Management System
// Demonstrates: class, constructor, array of objects,
// searching by ID
// =====================================================

#include <iostream>
#include "Book.h"

using namespace std;

int main() {
    const int SIZE = 5;  // Number of books

    // Create an array of Book objects
    Book books[SIZE] = {
        Book(101, "The Great Gatsby", "F. Scott Fitzgerald", 350.0),
        Book(102, "1984", "George Orwell", 420.5),
        Book(103, "To Kill a Mockingbird", "Harper Lee", 280.0),
        Book(104, "Pride and Prejudice", "Jane Austen", 310.75),
        Book(105, "The Catcher in the Rye", "J.D. Salinger", 395.0)
    };

    cout << "========== BOOK MANAGEMENT SYSTEM ==========" << endl;

    // Display all books
    cout << "\n--- All Books in Library ---" << endl;
    for (int i = 0; i < SIZE; i++) {
        books[i].displayBook();
        cout << "---------------------------------" << endl;
    }

    // Search for a book by ID
    int searchId;
    cout << "\nEnter a Book ID to search: ";
    cin >> searchId;

    bool found = false;
    for (int i = 0; i < SIZE && !found; i++) {
        if (books[i].getBookId() == searchId) {
            cout << "\n*** Book Found ***" << endl;
            books[i].displayBook();
            found = true;
        }
    }

    if (!found) {
        cout << "\n>> Book with ID " << searchId << " not found!" << endl;
    }

    return 0;
}
