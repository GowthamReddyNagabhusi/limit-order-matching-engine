#include <iostream>
#include "Order.h"
#include "OrderBook.h"
int main() {
    OrderBook orderBook;

    // Create some sample orders
    Order order1(1, true, 100.5, 10, 1622548800); // Buy order
    Order order2(2, false, 99.5, 5, 1622548810); // Sell order
    Order order3(3, true, 101.0, 15, 1622548820); // Buy order
    Order order4(4, false, 98.0, 20, 1622548830); // Sell order
    Order order5(5, true, 100.5, 20, 1622548840); // Buy order with same price as order1 but later timestamp
    Order order6(6, false, 99.5, 10, 1622548850); // Sell order with same price as order2 but later timestamp
    // Add orders to the order book
    orderBook.addOrder(order1);
    orderBook.addOrder(order2);
    orderBook.addOrder(order3);
    orderBook.addOrder(order4);
    orderBook.addOrder(order5);
    orderBook.addOrder(order6);
    
    // Print the current state of the order book
    orderBook.printOrderBook();
    return 0;
}