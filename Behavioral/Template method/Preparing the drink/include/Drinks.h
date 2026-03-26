#include "Beverage.h"
class Coffee : public Beverage {
    using Beverage::Beverage;
public:
    void brew() override;
    void addCondiments() override;
};
