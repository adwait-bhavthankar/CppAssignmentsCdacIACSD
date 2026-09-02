#ifndef ORDER_H
#define ORDER_H

#include "Customer.h"
#include "Product.h"

// ============================
// Class: Order
// Contains (has-a) Customer and Product objects
// Demonstrates containment / composition
// ============================
class Order {
private:
    int orderId;
    Customer customer;   // Contained object (Customer)
    Product product;     // Contained object (Product)

public:
    // Constructor initializing the contained Customer and Product objects
    Order(int oId, const Customer& cust, const Product& prod)
        : orderId(oId), customer(cust), product(prod) {}

    // Calculate and return the total order amount
    double getTotalAmount() const {
        return product.getTotalPrice();
    }

    // Display complete order details
    void displayOrder() const {
        cout << "=======================================" << endl;
        cout << "  ORDER ID : " << orderId << endl;
        cout << "---------------------------------------" << endl;
        cout << "  ## CUSTOMER DETAILS ##" << endl;
        customer.displayCustomer();
        cout << "---------------------------------------" << endl;
        cout << "  ## PRODUCT DETAILS ##" << endl;
        product.displayProduct();
        cout << "---------------------------------------" << endl;
        cout << "  TOTAL ORDER AMOUNT : Rs. " << getTotalAmount() << endl;
        cout << "=======================================" << endl;
    }

    // Accessors
    int getOrderId() const { return orderId; }
    Customer getCustomer() const { return customer; }
    Product getProduct() const { return product; }
};

#endif
