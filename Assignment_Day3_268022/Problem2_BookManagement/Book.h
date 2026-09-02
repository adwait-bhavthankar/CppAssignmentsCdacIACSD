#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

// ============================
// Class: Book
// Stores book details and supports search by ID
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
    void display() const {
        cout << "  Book ID    : " << bookId << endl;
        cout << "  Title      : " << title << endl;
        cout << "  Author     : " << author << endl;
        cout << "  Price      : Rs. " << price << endl;
    }

    // Accessors
    int getBookId() const { return bookId; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    double getPrice() const { return price; }
};

#endif
