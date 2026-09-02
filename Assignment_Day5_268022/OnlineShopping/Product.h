#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
using namespace std;

// ============================
// Class: Product
// Stores product details
// ============================
class Product {
private:
    int productId;
    string productName;
    double price;
    int quantity;

public:
    // Parameterized constructor
    Product(int pId = 0, string pName = "Unknown", double pPrice = 0.0, int qty = 0)
        : productId(pId), productName(pName), price(pPrice), quantity(qty) {}

    // Function to initialize product details
    void setProduct(int pId, string pName, double pPrice, int qty) {
        productId = pId;
        productName = pName;
        price = pPrice;
        quantity = qty;
    }

    // Calculate total price for this product (price x quantity)
    double getTotalPrice() const {
        return price * quantity;
    }

    // Function to display product details
    void displayProduct() const {
        cout << "  Product ID       : " << productId << endl;
        cout << "  Product Name     : " << productName << endl;
        cout << "  Price (per unit) : Rs. " << price << endl;
        cout << "  Quantity         : " << quantity << endl;
        cout << "  Line Total       : Rs. " << getTotalPrice() << endl;
    }

    // Accessors
    int getProductId() const { return productId; }
    string getProductName() const { return productName; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
};

#endif
