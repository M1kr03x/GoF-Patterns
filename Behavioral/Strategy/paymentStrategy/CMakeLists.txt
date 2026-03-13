cmake_minimum_required(VERSION 3.10)
project(paymentStrategy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(paymentStrategy)

target_sources(paymentStrategy PRIVATE
    src/creditCardPayment
    src/cryptoPayment
    src/main.cpp
    src/paymentContext
    src/payPalPayment
)

target_include_directories(paymentStrategy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)