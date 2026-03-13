#pragma once
#include "IPaymentStrategy.h"
class CryptoPayment : public IPaymentStrategy{
public:
bool pay(int) override;
};