#pragma once
#include "Order.h"

// Represents a single order in the matching engine
struct Order{
    int id;                  // Unique identifier for the order
    bool isBuy;              // True for buy orders, false for sell orders
    double price;            // Price per unit
    int quantity;            // Number of units in the order
    long long timestamp;     // Time when the order was placed
    
    // Constructor to initialize all order members using initializer list
    Order(int id, bool isBuy, double price, int quantity, long long timestamp)
        : id(id), isBuy(isBuy), price(price), quantity(quantity), timestamp(timestamp) {}
};

