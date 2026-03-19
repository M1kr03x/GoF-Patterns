#ifndef CONCRETE_HANDLERS_H
#define CONCRETE_HANDLERS_H

#include "SupportHandler.h"

class TechnicalSupport : public SupportHandler {
    SupportType getSupportedType() const override { return SupportType::Technical; }
    std::string getHandlerName() const override { return "Technical Support"; }
};

class BillingSupportHandler : public SupportHandler {
    SupportType getSupportedType() const override { return SupportType::Billing; }
    std::string getHandlerName() const override { return "Billing Support"; }
};

class GeneralSupportHandler : public SupportHandler {
    SupportType getSupportedType() const override { return SupportType::General; }
    std::string getHandlerName() const override { return "General Support"; }
};

class ComplaintHandler : public SupportHandler {
    SupportType getSupportedType() const override { return SupportType::Complaint; }
    std::string getHandlerName() const override { return "Complaint Support"; }
};

#endif