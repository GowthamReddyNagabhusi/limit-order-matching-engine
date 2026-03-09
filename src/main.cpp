// Standard library includes
#include <iostream>
#include <vector>
#include <random>
// Project includes
#include "Order.h"
#include "MatchingEngine.h"
Order generateRandomOrder(int id, long long timestamp) {
    // Static random number generator to ensure it is initialized only once
    static std::mt19937 rng(std::random_device{}());

    std::uniform_int_distribution<int> sideDist(0, 1); // 0 for buy, 1 for sell
    std::uniform_real_distribution<double> priceDist(95.0, 105.0); // Random price between 95.0 and 105.0
    std::uniform_int_distribution<int> qtyDist(1, 20); // Random quantity between 1 and 20
    std::uniform_int_distribution<int> typeDist(0, 1); // 0 for LIMIT, 1 for MARKET

    bool isBuy = sideDist(rng); // Randomly determine if the order is a buy or sell
    double price = priceDist(rng); // Randomly generate a price for the order
    int quantity = qtyDist(rng); // Randomly generate a quantity for the order
    // Randomly determine the order type (LIMIT or MARKET)
    OrderType type = (typeDist(rng) == 0) ? OrderType::LIMIT : OrderType::MARKET;

    if (type == OrderType::MARKET)
        price = 0; // price irrelevant

    return Order(id, isBuy, price, quantity, timestamp, type);
}
// Main entry point for the limit order matching engine
int main() {

    MatchingEngine engine;

    const int NUM_ORDERS = 50;

    for (int i = 1; i <= NUM_ORDERS; i++) {
        Order order = generateRandomOrder(i, i);
        // Print the details of the incoming order
        std::cout << "\nIncoming Order "
                  << order.getId()
                  << (order.isBuyOrder() ? " BUY " : " SELL ")
                  << "Qty:" << order.getQuantity()
                  << " Price:" << order.getPrice()
                  << std::endl;

        auto trades = engine.processOrder(order);
        // Print details of each executed trade
        for (const auto& trade : trades) {
            std::cout << "TRADE → "
                      << trade.quantity
                      << " @ "
                      << trade.price
                      << std::endl;
        }
        // Print the current state of the order book after processing the order
        engine.printOrderBook();
    }

    return 0;
}