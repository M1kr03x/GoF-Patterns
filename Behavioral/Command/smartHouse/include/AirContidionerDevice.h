#pragma once
#include <string>
#include "IDevice.h"
class Conditioner : public Device{
public:
void turnOn() override;
void turnOff() override;
void setTemperature(float);
void setMode(const std::string&);
float getTemperature() const;
std::string getMode() const;
private:
float temperature;
std::string currentMode;
};