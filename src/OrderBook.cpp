#include "OrderBook.h"
#include <iostream>
#include <algorithm>

// Add a new order to the appropriate queue (buy or sell)
void OrderBook::addOrder(const Order& order) {
    if (order.isBuyOrder()) {
        buyOrders.push(order);  // Add to buy orders priority queue
    } else {
        sellOrders.push(order); // Add to sell orders priority queue
    }
    // After adding a new order, attempt to match orders
    matchOrders();
}


std::vector<Trade> OrderBook::matchOrders() {
    std::vector<Trade> trades;

    while (!buyOrders.empty() && !sellOrders.empty()) {

        Order bestBuy = buyOrders.top();
        Order bestSell = sellOrders.top();
        // Check if the best buy and sell orders can be matched based on price and order type
        if (bestBuy.getType() == OrderType::MARKET ||
            bestSell.getType() == OrderType::MARKET ||
            bestBuy.getPrice() >= bestSell.getPrice()) {
            // Calculate the quantity to trade (the lesser of the two order quantities)
            int tradeQuantity = std::min(bestBuy.getQuantity(), bestSell.getQuantity());
            double tradePrice = bestSell.getPrice();
            // Record the trade details in the trades vector
            trades.emplace_back(bestBuy.getId(), bestSell.getId(), tradePrice, tradeQuantity);

            buyOrders.pop();
            sellOrders.pop();
            // Update the quantities of the buy and sell orders after the trade
            if (tradeQuantity < bestBuy.getQuantity()) {
                bestBuy.setQuantity(bestBuy.getQuantity() - tradeQuantity);
                if (bestBuy.getType() == OrderType::LIMIT)
                    buyOrders.push(bestBuy);
            }

            if (tradeQuantity < bestSell.getQuantity()) {
                bestSell.setQuantity(bestSell.getQuantity() - tradeQuantity);
                if (bestSell.getType() == OrderType::LIMIT)
                    sellOrders.push(bestSell);
            }

        } else {
            break;
        }
    }

    return trades;
}
void OrderBook::printOrderBook() const {

    auto buyCopy = buyOrders;
    auto sellCopy = sellOrders;

    std::cout << "\n----- ORDER BOOK -----\n";

    std::cout << "\nBUY ORDERS:\n";
    while (!buyCopy.empty()) {
        const Order& order = buyCopy.top();
        std::cout << "Price: " << order.getPrice()
                  << " Qty: " << order.getQuantity()
                  << " ID: " << order.getId()
                  << std::endl;
        buyCopy.pop();
    }

    std::cout << "\nSELL ORDERS:\n";
    while (!sellCopy.empty()) {
        const Order& order = sellCopy.top();
        std::cout << "Price: " << order.getPrice()
                  << " Qty: " << order.getQuantity()
                  << " ID: " << order.getId()
                  << std::endl;
        sellCopy.pop();
    }

    std::cout << "----------------------\n";
}
