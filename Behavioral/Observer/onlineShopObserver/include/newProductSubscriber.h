#include "../include/observer.h"
class NewProductSubscriber : public Observer{
    public:
    void update(const std::string&, const std::string&)  override;
};