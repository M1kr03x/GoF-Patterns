#include "../include/AirContidionerDevice.h"
#include "../include/LightDevice.h"
#include "../include/MusicCenterDevice.h"
#include "../include/TVDevice.h"
#include "../include/commandHandler.h"
#include <vector>
int main(){
    std::vector<std::shared_ptr<ICommand>> history;
    
    auto tv = std::make_shared<TV>();
    auto light = std::make_shared<Light>();
    auto musicCenter = std::make_shared<MusicCenter>();
    auto conditioner = std::make_shared<Conditioner>();

    auto changeChannelCommand = std::make_shared<commandHandler<TV,unsigned int>>(tv,&TV::getChannel,&TV::setChannel,10);
    auto changeLightColorCommand = std::make_shared<commandHandler<Light,unsigned int>>(light, &Light::getLightColor,&Light::setLightColor, 0xFFFFF);
    auto changeVolumeCommand = std::make_shared<commandHandler<MusicCenter,unsigned int>>(musicCenter, &MusicCenter::getVolume,&MusicCenter::setVolume, 50);
    auto changeTemperatureCommand = std::make_shared<commandHandler<Conditioner,float>>(conditioner,&Conditioner::getTemperature,&Conditioner::setTemperature,24.5f);

    changeChannelCommand->execute();
    history.push_back(changeChannelCommand);

    changeLightColorCommand->execute();
    history.push_back(changeLightColorCommand);

    changeVolumeCommand->execute();
    history.push_back(changeVolumeCommand);

    changeTemperatureCommand->execute();
    history.push_back(changeTemperatureCommand);

    for(const auto& vec : history){
        vec->undo();
    }
}