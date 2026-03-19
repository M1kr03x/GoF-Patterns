#ifndef SUPPORT_HANDLER_H
#define SUPPORT_HANDLER_H

#include "SupportRequest.h"
#include <memory>
#include <string>

class IHandler {
public:
    virtual ~IHandler() = default;
    virtual std::shared_ptr<IHandler> setNext(std::shared_ptr<IHandler> next) = 0;
    virtual void handler(std::unique_ptr<SupportRequest> sup) = 0;
};

class SupportHandler : public IHandler {
protected:
    std::shared_ptr<IHandler> _next = nullptr;
    virtual SupportType getSupportedType() const = 0;
    virtual std::string getHandlerName() const = 0;

public:
    std::shared_ptr<IHandler> setNext(std::shared_ptr<IHandler> nx) override;
    void handler(std::unique_ptr<SupportRequest> sup) override;
};

#endif