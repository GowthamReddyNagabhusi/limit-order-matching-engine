# Limit Order Matching Engine

A C++ implementation of a limit order matching engine that matches buy and sell orders using priority queues.

## Project Overview

This project implements a matching engine that processes financial orders and executes trades when buy and sell orders meet at matching prices. The engine uses priority queues to efficiently manage orders based on price and timestamp priorities.

## Architecture

### Core Components

- **Order**: Represents a single buy or sell order with ID, direction, price, quantity, and timestamp
- **OrderBook**: Manages separate priority queues for buy and sell orders, executes order matching
- **MatchingEngine**: Main engine that processes incoming orders and returns executed trades
- **Trade**: Represents an executed trade with buyer ID, seller ID, price, and quantity

### Order Matching Logic

- **Buy Orders**: Ordered by highest price first, with earlier timestamps taking priority
- **Sell Orders**: Ordered by lowest price first, with earlier timestamps taking priority

## Build Instructions

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Usage

Run the executable to process sample orders:

```
./limit-order-matching-engine
```

## Recent Changes (March 2, 2026)

### Bug Fixes
- Fixed namespace error in `MatchingEngine.cpp` - changed `std::orderBook` to `orderBook` for correct member access
- Made `matchOrders()` public in `OrderBook.h` to allow access from `MatchingEngine`

### Code Documentation
- Added comprehensive comments to `main.cpp` explaining:
  - Include statements and dependencies
  - Main function workflow
  - Order creation and processing logic
  - Trade execution and output formatting

## File Structure

```
src/
├── main.cpp           - Entry point with order processing logic
├── MatchingEngine.h   - Engine class definition
├── MatchingEngine.cpp - Engine implementation
├── OrderBook.h        - Order book class with matching logic
├── OrderBook.cpp      - Order book implementation
├── Order.h            - Order data structure
├── Trade.h            - Trade data structure
tests/                 - Test files (directory)
CMakeLists.txt         - Build configuration
```

## Status

The project is fully functional with all compilation errors resolved. The matching engine successfully processes orders and executes trades based on price matching criteria.
