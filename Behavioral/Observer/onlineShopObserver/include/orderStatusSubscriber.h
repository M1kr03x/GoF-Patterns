#include "../include/observer.h"
class OrderStatusSubscriber : public Observer{
    public:
    void update(const std::string&, const std::string&)  override;
};