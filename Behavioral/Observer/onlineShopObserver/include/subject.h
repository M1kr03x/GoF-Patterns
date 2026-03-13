#include <memory>
#include <map>
#include "observer.h"
class ISubject{
    public:
virtual ISubject& subscribe(std::shared_ptr<Observer>,const std::string&subscriberType) = 0;
virtual ISubject& unsubscribe(std::shared_ptr<Observer>,const std::string&subscriberType) =0;
virtual void notifyObservers(const std::string&,const std::string&, const std::string&) = 0;
~ISubject() = default;
};