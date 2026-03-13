#include "../include/orderStatusSubscriber.h"
void OrderStatusSubscriber::update(const std::string& propName, const std::string& propValue) {
    std::cout<< propName + " has been changed to " + propValue + "\n";
}