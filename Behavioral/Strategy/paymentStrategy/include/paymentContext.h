#pragma once
#include <memory>
#include "IPaymentStrategy.h"
class PaymentContext{
    private:
    int _amount;
    std::unique_ptr<IPaymentStrategy> strategy = nullptr;
    public:
    PaymentContext(int amount);
    void setPaymentType(std::unique_ptr<IPaymentStrategy>);
    void setAmount(int value);
    int getAmount() const;
    void pay(int amount);
    friend std::istream& operator>>(std::istream& is, PaymentContext& pc);
};