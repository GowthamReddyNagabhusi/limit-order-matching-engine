#include "MatchingEngine.h"

std::vector<Trade> MatchingEngine::processOrder(const Order& order) {
    orderBook.addOrder(order);
    return orderBook.matchOrders();
}