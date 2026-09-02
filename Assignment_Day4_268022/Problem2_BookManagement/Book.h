#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

// ============================
// Class: Book
// Stores book details
// ============================
class Book {
private:
    int bookId;
    string title;
    string author;
    double price;

public:
    // Parameterized constructor
    Book(int id = 0, string t = "Unknown", string a = "Unknown", double p = 0.0)
        : bookId(id), title(t), author(a), price(p) {}

    // Display book details
    void displayBook() const {
        cout << "  Book ID   : " << bookId << endl;
        cout << "  Title     : " << title << endl;
        cout << "  Author    : " << author << endl;
        cout << "  Price     : Rs. " << price << endl;
    }

    // Accessor for searching
    int getBookId() const { return bookId; }
    string getTitle() const { return title; }
};

#endif
