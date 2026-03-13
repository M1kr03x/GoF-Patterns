#pragma once
#include <string>
#include <iostream>

class Observer{
    public:
    virtual void update(const std::string&, const std::string&)  = 0;
};