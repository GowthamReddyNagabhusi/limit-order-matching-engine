#pragma once

#include "OrderBook.h"
#include "Trade.h"
#include <vector>

class MatchingEngine {
private:
    OrderBook orderBook;

public:
    std::vector<Trade> processOrder(const Order& order);
    void printOrderBook() const; // Delegate to the order book's print function
};