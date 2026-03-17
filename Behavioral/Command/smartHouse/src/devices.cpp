#include "../include/AirContidionerDevice.h";
#include "../include/LightDevice.h";
#include "../include/MusicCenterDevice.h";
#include "../include/TVDevice.h";
#include    <iostream>
void Conditioner::turnOn(){
    isEnabled_ = true;
    std::cout<< "Conditioner enabled\n";
}
void Conditioner::turnOff(){
    isEnabled_ = true;
    std::cout<< "Conditioner disabled\n";
}
void Conditioner::setMode(const std::string& mode){
    currentMode = mode;
    std::cout << "Current mode has been switched to" << mode << std::endl;
}
void Conditioner::setTemperature(float temp){
    temperature = temp;
    std::cout<< "Current temperature has been changed to: " << temp << std::endl;
}

float Conditioner::getTemperature() const{
    return temperature;
}
std::string Conditioner::getMode() const{
    return currentMode;
}