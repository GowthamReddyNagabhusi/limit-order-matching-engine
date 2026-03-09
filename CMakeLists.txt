cmake_minimum_required(VERSION 3.10)
project(LimitOrderMatchingEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    src/main.cpp
    src/MatchingEngine.cpp
    src/OrderBook.cpp
)

# Create executable
add_executable(limit-order-matching-engine ${SOURCES})

# Include directories
target_include_directories(limit-order-matching-engine PRIVATE ${CMAKE_SOURCE_DIR}/src)
