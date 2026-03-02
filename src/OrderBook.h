#pragma once
#include <queue>
#include "Order.h"
#include "Trade.h"
#include <vector>

// Comparator for buy orders prioritized by highest price, then earliest timestamp
struct CompareBuy{
    bool operator()(const Order& a, const Order& b) {
        if (a.price == b.price) {
            return a.timestamp > b.timestamp; // Earlier timestamp has higher priority
        }
        return a.price < b.price; // Higher price has higher priority
    }
};

// Comparator for sell orders prioritized by lowest price, then earliest timestamp
struct CompareSell{
    bool operator()(const Order& a, const Order& b) {
        if (a.price == b.price) {
            return a.timestamp > b.timestamp; // Earlier timestamp has higher priority
        }
        return a.price > b.price; // Lower price has higher priority
    }
};

// OrderBook class manages buy and sell orders using priority queues
class OrderBook{
    private:
        std::priority_queue<Order, std::vector<Order>, CompareBuy> buyOrders;
        std::priority_queue<Order, std::vector<Order>, CompareSell> sellOrders;
    public:
        std::vector<Trade> matchOrders(); // Function to match buy and sell orders (not implemented in this snippet)
        void addOrder(const Order& order);
        void printOrderBook();
};
