#include "../include/discountSubscriber.h"
void DiscountSubscriber::update(const std::string& propName, const std::string& propValue) {
    std::cout  << propName << " update! \n" << propName << " now is " << propValue << "%\n";
}