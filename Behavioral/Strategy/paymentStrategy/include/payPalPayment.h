#pragma once
#include "IPaymentStrategy.h"
class PayPalPayment : public IPaymentStrategy{
    public:
    bool pay(int) override;
};