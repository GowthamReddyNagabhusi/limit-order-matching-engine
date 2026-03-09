#include "MatchingEngine.h"

std::vector<Trade> MatchingEngine::processOrder(const Order& order) {
    orderBook.addOrder(order); 
    return orderBook.matchOrders(); // Return the list of trades executed as a result of processing the order
}
void MatchingEngine::printOrderBook() const {
    orderBook.printOrderBook(); // Call the print function of the order book to display current orders
}