#include "OrderBook.h"
#include <iostream>

// Add a new order to the appropriate queue (buy or sell)
void OrderBook::addOrder(const Order& order) {
    if (order.isBuy) {
        buyOrders.push(order);  // Add to buy orders priority queue
    } else {
        sellOrders.push(order); // Add to sell orders priority queue
    }
}

// Display all orders in the order book
void OrderBook::printOrderBook() {
    // Print all buy orders in priority order
    std::cout << "Buy Orders:" << std::endl;
    std::priority_queue<Order, std::vector<Order>, CompareBuy> tempBuy = buyOrders;
    while (!tempBuy.empty()) {
        Order order = tempBuy.top();
        tempBuy.pop();
        std::cout << "ID: " << order.id << ", Price: " << order.price 
                  << ", Quantity: " << order.quantity 
                  << ", Timestamp: " << order.timestamp << std::endl;
    }

    // Print all sell orders in priority order
    std::cout << "Sell Orders:" << std::endl;
    std::priority_queue<Order, std::vector<Order>, CompareSell> tempSell = sellOrders;
    while (!tempSell.empty()) {
        Order order = tempSell.top();
        tempSell.pop();
        std::cout << "ID: " << order.id << ", Price: " << order.price 
                  << ", Quantity: " << order.quantity 
                  << ", Timestamp: " << order.timestamp << std::endl;
    }
}
