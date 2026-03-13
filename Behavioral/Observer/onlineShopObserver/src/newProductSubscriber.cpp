#include "../include/newProductSubscriber.h"
void NewProductSubscriber::update(const std::string& propName, const std::string& propValue) 
{
    std::cout << "New " + propName + " " + propValue + " has been released\n"; 
}