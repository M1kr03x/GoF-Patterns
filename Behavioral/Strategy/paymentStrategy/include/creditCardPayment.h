#pragma once
#include "IPaymentStrategy.h"
class CreditCardPayment : public IPaymentStrategy{
public:
bool pay(int) override;
};