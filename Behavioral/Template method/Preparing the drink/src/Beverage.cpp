#include "../include/Beverage.h"
#include <iostream>
#include <thread>
#include <chrono>
void Beverage::boilWater() {
    std::cout << "Boiling " << name << "...";
    std::this_thread::sleep_for(std::chrono::seconds(TIME));
    std::cout << "\nYour " << name << " boiled\n";
}
void Beverage::pourInCup() {
    std::cout << "Pouring your " << name << " in the cup..\n";
    std::this_thread::sleep_for(std::chrono::seconds(TIME));
    std::cout << "Here is your " << name << std::endl;
}
