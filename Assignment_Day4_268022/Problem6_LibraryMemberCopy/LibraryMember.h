#ifndef LIBRARYMEMBER_H
#define LIBRARYMEMBER_H

#include <iostream>
#include <string>
using namespace std;

// ============================
// Class: LibraryMember
// Demonstrates: constructor, copy constructor, destructor
// ============================
class LibraryMember {
private:
    int memberId;
    string name;
    int booksIssued;

public:
    // Parameterized constructor
    LibraryMember(int id = 0, string n = "Unknown", int books = 0)
        : memberId(id), name(n), booksIssued(books) {
        cout << "Constructor called for member: " << name << " (ID: " << memberId << ")" << endl;
    }

    // Copy constructor
    LibraryMember(const LibraryMember& other)
        : memberId(other.memberId), name(other.name), booksIssued(other.booksIssued) {
        cout << "Copy constructor called. Duplicating member: " << name << endl;
    }

    // Destructor - displays message when object is removed
    ~LibraryMember() {
        cout << "Destructor called. Removing member: " << name << " (ID: " << memberId << ")" << endl;
    }

    // Display member details
    void display() const {
        cout << "  Member ID      : " << memberId << endl;
        cout << "  Member Name    : " << name << endl;
        cout << "  Books Issued   : " << booksIssued << endl;
    }
};

#endif
