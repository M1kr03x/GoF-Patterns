cmake_minimum_required(VERSION 3.10)
project(OnlineShop)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(online_shop)

target_sources(online_shop PRIVATE
    src/product.cpp
    src/onlineStore.cpp
    src/main.cpp
    src/discountSubscriber.cpp
    src/newProductSubscriber.cpp
    src/orderStatusSubscriber.cpp
)

target_include_directories(online_shop PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)~