#pragma once
#include <iostream>
#include <thread>
#include <chrono>
class IPaymentStrategy{
    public:
~IPaymentStrategy() = default;
virtual bool pay(int) = 0;
};