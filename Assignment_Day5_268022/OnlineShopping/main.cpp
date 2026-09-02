// =====================================================
// Online Shopping Order Management System
// Demonstrates: Containment (objects within objects)
// =====================================================

#include <iostream>
#include "Customer.h"
#include "Product.h"
#include "Order.h"

using namespace std;

int main() {
    cout << "========== ONLINE SHOPPING ORDER MANAGEMENT SYSTEM ==========" << endl;

    // ----- Create Customer objects -----
    Customer cust1(101, "Alice Johnson", "9876543210");
    Customer cust2(102, "Bob Smith", "9123456780");
    Customer cust3(103, "Carol Davis", "9988776655");

    // ----- Create Product objects (id, name, price per unit, quantity) -----
    Product prod1(201, "Wireless Mouse", 799.99, 2);
    Product prod2(202, "Mechanical Keyboard", 2999.50, 1);
    Product prod3(203, "USB-C Laptop Charger", 1499.00, 3);

    // ----- Create Order objects containing Customer and Product -----
    // Each Order contains (has-a) one Customer and one Product
    Order order1(301, cust1, prod1);
    Order order2(302, cust2, prod2);
    Order order3(303, cust3, prod3);

    // ----- Display complete order details for all orders -----
    order1.displayOrder();
    order2.displayOrder();
    order3.displayOrder();

    // ----- Demonstrate accessor usage (optional) -----
    cout << "\n>> Summary of all orders:" << endl;
    cout << "  Order " << order1.getOrderId()
         << " -> " << order1.getCustomer().getCustomerName()
         << " bought " << order1.getProduct().getProductName()
         << " x " << order1.getProduct().getQuantity()
         << " = Rs. " << order1.getTotalAmount() << endl;

    cout << "  Order " << order2.getOrderId()
         << " -> " << order2.getCustomer().getCustomerName()
         << " bought " << order2.getProduct().getProductName()
         << " x " << order2.getProduct().getQuantity()
         << " = Rs. " << order2.getTotalAmount() << endl;

    cout << "  Order " << order3.getOrderId()
         << " -> " << order3.getCustomer().getCustomerName()
         << " bought " << order3.getProduct().getProductName()
         << " x " << order3.getProduct().getQuantity()
         << " = Rs. " << order3.getTotalAmount() << endl;

    return 0;
}
