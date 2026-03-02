#pragma once
struct Trade {
    int buyOrderId;   // ID of the buy order involved in the trade
    int sellOrderId;  // ID of the sell order involved in the trade
    double price;     // Price at which the trade was executed
    int quantity;     // Quantity of units traded

    // Constructor to initialize all trade members using initializer list
    Trade(int buyOrderId, int sellOrderId, double price, int quantity)
        : buyOrderId(buyOrderId), sellOrderId(sellOrderId), price(price), quantity(quantity) {}
};