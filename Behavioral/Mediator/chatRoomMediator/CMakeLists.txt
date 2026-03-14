cmake_minimum_required(VERSION 3.10)
project(chatMediator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(chatMediator)

target_sources(chatMediator PRIVATE
    src/chatRoom.cpp
    src/main.cpp
    src/user.cpp
)

target_include_directories(chatMediator PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)