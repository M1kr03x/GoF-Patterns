#include "../include/Drinks.h"
#include <iostream>
#include <thread>
#include <chrono>
void Coffee::brew() {
    std::cout << "Brewing " << name << " using a secret coffee recipe " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(TIME));
    std::cout << "Successfully brewed\n";
}
void Coffee::addCondiments() {
    std::cout << "Adding sugar..\n";
    std::this_thread::sleep_for(std::chrono::seconds(TIME));
    std::cout << "Now u have coffee with sugar\n";
}
void Tea::brew() {
    std::cout << "Brewing " << name << " using a secret tea recipe " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(TIME));
    std::cout << "Successfully brewed\n";
}
void Cocoa::brew() {
    std::cout << "Brewing " << name << " using a cocoa tea recipe " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(TIME));
    std::cout << "Successfully brewed\n";
}