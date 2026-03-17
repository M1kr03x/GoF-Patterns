#include "../include/AirContidionerDevice.h"
#include "../include/LightDevice.h"
#include "../include/MusicCenterDevice.h"
#include "../include/TVDevice.h"
#include    <iostream>
//AIRCONDITIONER.H


void Conditioner::turnOn(){
    isEnabled_ = true;
    std::cout<< "Conditioner enabled\n";
}
void Conditioner::turnOff(){
    isEnabled_ = true;
    std::cout<< "Conditioner disabled\n";
}

// SEETERS
void Conditioner::setMode(const std::string& mode){
    currentMode = mode;
    std::cout << "Current mode has been switched to" << mode << std::endl;
}
void Conditioner::setTemperature(float temp){
    temperature = temp;
    std::cout<< "Current temperature has been changed to: " << temp << std::endl;
}
// GETTERS
float Conditioner::getTemperature() const{
    return temperature;
}
std::string Conditioner::getMode() const{
    return currentMode;
}

// LIGHTDEVICE.H

void Light::turnOn(){
    isEnabled_ = true;
    std::cout<< "Lights on\n";
}
void Light::turnOff(){
    isEnabled_ = true;
    std::cout<< "Lights off\n";
}

//  SETTERS
void Light::setBrightness(short brightProcent){
    brightness = brightProcent;
    std::cout << "Bright level setted to " << brightProcent << "%\n";
}
void Light::setLightColor(unsigned int color){
    this->color = color;
    std::cout << "Color has been chaged to " << color << std::endl; 
}
//  GETTERS
short Light::getBrightness() const {return brightness;}
unsigned int Light::getLightColor() const {return color;}

//MUSICCENTER.H

void MusicCenter::turnOn(){
    isEnabled_ = true;
    std::cout<< "Music center turned on\n";
}
void MusicCenter::turnOff(){
    isEnabled_ = true;
    std::cout<< "Music center turned off\n";
}

//  SETTERS
void MusicCenter::setVolume(unsigned int volume){
this->volume = volume;
std::cout<< "Volume setted to " << volume << "%\n";
}
//  GETTERS
unsigned int MusicCenter::getVolume() const {
    return volume;
}
//TVDEVICE.H

void TV::turnOn(){
    isEnabled_ = true;
    std::cout<< "TV turned on\n";
}
void TV::turnOff(){
    isEnabled_ = true;
    std::cout<< "TV off\n";
}
//SETTERS
void TV::setChannel(unsigned int channel){
    this->channel = channel;
    std::cout <<"Channel changed to " << channel << std::endl;
}
//GETTERS
unsigned int TV::getChannel() const{
    return channel;
}