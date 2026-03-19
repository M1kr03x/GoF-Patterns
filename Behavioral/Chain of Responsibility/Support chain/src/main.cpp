#include "ConcreteHandlers.h"
#include "SupportRequest.h"

int main() {
    auto request = std::make_unique<SupportRequest>(SupportType::Technical, "I cant do something");
    
    auto techSup = std::make_shared<TechnicalSupport>();
    auto billingSup = std::make_shared<BillingSupportHandler>();
    auto generalSup = std::make_shared<GeneralSupportHandler>();
    auto complainSup = std::make_shared<ComplaintHandler>();
    techSup->setNext(billingSup);
    billingSup->setNext(generalSup);
    generalSup->setNext(complainSup);
    techSup->handler(std::move(request));

    return 0;
}