#pragma once
#include "Order.h"
enum class OrderType {
    LIMIT,
    MARKET
};
// Represents a single order in the matching engine
struct Order{
    private:
    int id;                  // Unique identifier for the order
    bool isBuy;              // True for buy orders, false for sell orders
    double price;            // Price per unit
    int quantity;            // Number of units in the order
    long long timestamp;     // Time when the order was placed
    OrderType type;         // Type of the order (LIMIT or MARKET)
    public:
    // Constructor to initialize all order members using initializer list
    Order(int id, bool isBuy, double price, int quantity, long long timestamp, OrderType type)
        : id(id), isBuy(isBuy), price(price), quantity(quantity), timestamp(timestamp), type(type) {}
    // Getter functions to access private members of the Order struct
    int getId() const { return id; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    bool isBuyOrder() const { return isBuy; }
    long long getTimestamp() const { return timestamp; }
    OrderType getType() const { return type; }
    // Setter function to update the quantity of the order after a trade is executed
    void setQuantity(int newQuantity) { quantity = newQuantity; }
};

