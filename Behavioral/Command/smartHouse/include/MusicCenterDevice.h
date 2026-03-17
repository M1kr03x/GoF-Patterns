#include "IDevice.h"
class MusicCenter : public Device{
public:
void turnOn() override;
void turnOff() override;
void setVolume(unsigned int);
unsigned int getVolume() const;
private:
unsigned int volume;
};