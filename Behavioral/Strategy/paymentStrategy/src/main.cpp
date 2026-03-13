#include "../include/paymentContext.h"
#include "../include/cryptoPayment.h"
#include "../include/payPalPayment.h"
#include "../include/creditCardPayment.h"

int main(){
    auto person = std::make_unique<PaymentContext>(500);
    while(true){
    std::cout<< "Welcome to ===CANAL DOBRA AND BANKA PRIKOLOV===\n";
    std::cout<< "Choose an option to continue\n" <<
    "[1]. Insert some money\n" <<
    "[2]. Choose payment type\n" <<
    "[3]. Pay\n" <<
    "[4]. Exit\n";
    std::cout << "Enter variant digit >> ";
    int variant;
    std::cin>> variant;
    switch (variant)
    {
    case 1:
        std::cin >> *person;
        break;
    case 2:{
        std::cout << "[1]. Paypal\n" <<
                    "[2]. Crypto\n" <<
                    "[3]. Credit card\n";
        int var2;
        std::cin>> var2;
        switch (var2)
        {
        case 1:
            person->setPaymentType(std::make_unique<PayPalPayment>());
            break;
        case 2:
        person->setPaymentType(std::make_unique<CryptoPayment>());
        break;
        case 3:
        person->setPaymentType(std::make_unique<CreditCardPayment>());
        break;
        
        default:
        std::cout<< "Wrong option\n";
            break;
        } break;
    }
        case 3: person->pay(person->getAmount());
        break;
        case 4: return 0;
    default:
        std::cout<< "Wrong option\n";
        break;
    }
}
}