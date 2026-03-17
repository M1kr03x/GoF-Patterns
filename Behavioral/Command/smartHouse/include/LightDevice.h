#pragma once
#include "IDevice.h"
class Light : public Device{
public:
void turnOn() override;
void turnOff() override;
void setBrightness(short);
void setLightColor(unsigned int);
short getBrightness() const;
unsigned int getLightColor() const;
private:
unsigned int color;
short brightness;
};