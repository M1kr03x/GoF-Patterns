#pragma once
#include "IDevice.h"
class TV : public Device{
    public:
void turnOn() override;
void turnOff() override;
void setChannel(unsigned int);
unsigned int getChannel() const;
private:
unsigned int channel;
};