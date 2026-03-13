#include <iostream>
#include "../include/paymentContext.h"

PaymentContext::PaymentContext(int amount) : _amount(amount){}
void PaymentContext::setAmount(int amount){
    _amount = amount;
}
int PaymentContext::getAmount() const{
    return _amount;
}
void PaymentContext::setPaymentType(std::unique_ptr<IPaymentStrategy> type){
    
    strategy = std::move(type);
    
}
void PaymentContext::pay(int amount){
    bool success =false;
    if(strategy!=nullptr)  success = strategy->pay(amount);
    else{ std::cout<<"Payment type not selected\n"; return;}
    
    if(success) std::cout<< "Succesfull payment\n";
}

std::istream& operator>>(std::istream& is, PaymentContext& pc){
    std::cout<< "Enter amount of ROUBLES >> ";
    if (is >> pc._amount) { 
        if (pc._amount <= 0) {
            std::cout << "Amount must be positive. Your balabnce now is 0 AHAHAHHAHA\n";
            pc._amount = 0;
        }
    } else {
        std::cout << "Now way u can enter non-int.\n";
        pc._amount = 0;
        is.clear();
        is.ignore(10000, '\n');
    }
    
    return is;
}