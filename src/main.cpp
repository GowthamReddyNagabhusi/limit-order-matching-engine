// Standard library includes
#include <iostream>
#include <vector>
// Project includes
#include "Order.h"
#include "MatchingEngine.h"

// Main entry point for the limit order matching engine
int main() {
    // Create an instance of the matching engine
    MatchingEngine engine;

    // Define a vector of sample orders for testing
    // Order format: (id, isBuy, price, quantity, timestamp)
    std::vector<Order> orders = {
        Order(1, true, 100.0, 10, 1),      // Buy order at 100.0
        Order(2, false, 99.0, 5, 2),       // Sell order at 99.0
        Order(3, true, 101.0, 15, 3),      // Buy order at 101.0
        Order(4, false, 98.0, 20, 4),      // Sell order at 98.0
        Order(5, true, 99.0, 10, 5),       // Buy order at 99.0
        Order(6, false, 100.0, 5, 6)       // Sell order at 100.0
    };

    // Print header for trades output
    std::cout << "Trades executed:\n";

    // Process each order through the matching engine
    for (const auto& order : orders) {
        // Process the order and get resulting trades
        auto trades = engine.processOrder(order);

        // Display each executed trade
        for (const auto& trade : trades) {
            std::cout << "Buy Order ID: " << trade.buyOrderId
                      << ", Sell Order ID: " << trade.sellOrderId
                      << ", Price: " << trade.price
                      << ", Quantity: " << trade.quantity
                      << std::endl;
        }
    }

    return 0;  // Exit the program successfully
}