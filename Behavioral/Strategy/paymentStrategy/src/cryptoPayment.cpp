#include "../include/cryptoPayment.h"
bool CryptoPayment::pay(int amount){
    std::cout<< "Doing some crypto payment process..\n" << std::flush;
    //amount operation
    bool success = true;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    if(success){
    std::cout<< "Hooray! Succesfull\n";
    return true;
    } else {std::cout<< "Something went wrong in payment operation\n"; return false;}
}