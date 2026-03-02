#pragma once

#include "OrderBook.h"
#include "Trade.h"
#include <vector>

class MatchingEngine {
private:
    OrderBook orderBook;

public:
    std::vector<Trade> processOrder(const Order& order);
};