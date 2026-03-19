#include "../include/SupportHandler.h"
#include <iostream>
#include <chrono>
#include <thread>

std::shared_ptr<IHandler> SupportHandler::setNext(std::shared_ptr<IHandler> nx) {
    _next = nx;
    return _next;
}

void SupportHandler::handler(std::unique_ptr<SupportRequest> sup) {
    if (sup->getRequestType() == getSupportedType()) {
        std::cout << getHandlerName() << " solving your problem..\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "Your problem:\n " << sup->getRequestContent() 
                  << "\n has been successfully solved\n";
        return;
    } 
    else if (_next) {
        _next->handler(std::move(sup));
    } 
    else {
        std::cout << "No support available for this type of request.\n";
    }
}