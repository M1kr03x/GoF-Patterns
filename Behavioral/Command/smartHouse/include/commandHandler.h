#include "IDevice.h"
#include "ICommand.h"
#include <memory>
template <typename device, typename T>
class commandHandler : public ICommand{
    std::shared_ptr<device> dev;
    using getterPtr = T(device::*)() const;
    using setterPtr = void (device::*)(T);
    T value;
    T oldValue;
    setterPtr setter;
    getterPtr getter;
    public:
    commandHandler(std::shared_ptr<device> d, getterPtr g, setterPtr s, T val) : dev(d), getter(g), setter(s), value(val){
        oldValue = T();
    }
    void execute() override{
        if(dev){
            oldValue = (dev.get()->*getter)();
            (dev.get()->*setter)(value);
        }
    }
    void undo() override{
        if(oldValue!=T() and dev){
            (dev.get()->*setter)(oldValue);
        }
    }
};