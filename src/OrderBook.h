#pragma once
#include <queue>
#include "Order.h"
#include "Trade.h"
#include <vector>

// Comparator for buy orders prioritized by highest price, then earliest timestamp
struct CompareBuy{
    bool operator()(const Order& a, const Order& b) {
        if (a.getPrice() == b.getPrice()) {
            return a.getTimestamp() > b.getTimestamp(); // Earlier timestamp has higher priority
        }
        return a.getPrice() < b.getPrice(); // Higher price has higher priority
    }
};

// Comparator for sell orders prioritized by lowest price, then earliest timestamp
struct CompareSell{
    bool operator()(const Order& a, const Order& b) {
        if (a.getPrice() == b.getPrice()) {
            return a.getTimestamp() > b.getTimestamp(); // Earlier timestamp has higher priority
        }
        return a.getPrice() > b.getPrice(); // Lower price has higher priority
    }
};

// OrderBook class manages buy and sell orders using priority queues
class OrderBook{
    private:
        std::priority_queue<Order, std::vector<Order>, CompareBuy> buyOrders;
        std::priority_queue<Order, std::vector<Order>, CompareSell> sellOrders;

    public:
        std::vector<Trade> matchOrders(); // Function to match buy and sell orders
        void addOrder(const Order& order); // Function to add a new order to the order book
        void printOrderBook() const; // Function to print the current state of the order book
};

