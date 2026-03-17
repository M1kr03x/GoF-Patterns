#pragma once
class Device{
    public:
virtual ~Device() = default;
bool isEnabled() {return isEnabled_;}
virtual void turnOff() = 0;
virtual void turnOn() = 0; 
protected:
bool isEnabled_;

};