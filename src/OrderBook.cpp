#include "OrderBook.h"
#include <iostream>
#include <algorithm>

// Add a new order to the appropriate queue (buy or sell)
void OrderBook::addOrder(const Order& order) {
    if (order.isBuy) {
        buyOrders.push(order);  // Add to buy orders priority queue
    } else {
        sellOrders.push(order); // Add to sell orders priority queue
    }
    // After adding a new order, attempt to match orders (not implemented in this snippet)
    matchOrders();
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
std::vector<Trade> OrderBook::matchOrders() {
    std::vector<Trade> trades;
    // This function will contain the logic to match buy and sell orders based on price and timestamp
        while(!buyOrders.empty() && !sellOrders.empty()) {
            Order bestBuy = buyOrders.top();
            Order bestSell = sellOrders.top();
            // Check if the best buy order can be matched with the best sell order
            if (bestBuy.price < bestSell.price) {
                break; // No match possible, exit the loop
            }
            int tradeQuantity = std::min(bestBuy.quantity, bestSell.quantity);
            // Update the quantities of the matched orders
            trades.emplace_back(bestBuy.id, bestSell.id, bestSell.price, tradeQuantity);
            bestBuy.quantity -= tradeQuantity;
            bestSell.quantity -= tradeQuantity;
            // Remove the orders from the queues
            buyOrders.pop();
            sellOrders.pop();
            // If there are remaining quantities in either order, re-add it to the queue
            if (bestBuy.quantity > 0) {
                buyOrders.push(bestBuy);
            }
            if (bestSell.quantity > 0) {
                sellOrders.push(bestSell);
            }
        }
        return trades; // Return the list of executed trades
    }
