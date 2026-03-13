#include "../include/observer.h"
class DiscountSubscriber : public Observer{
    public:
    void update(const std::string&, const std::string&)  override;
};