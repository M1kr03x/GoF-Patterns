#ifndef SUPPORT_REQUEST_H
#define SUPPORT_REQUEST_H

#include <string>

enum class SupportType { Technical, Billing, General, Complaint };

class SupportRequest {
private:
    SupportType requestType;
    std::string requestContent;
public:
    SupportRequest(SupportType type, const std::string& rC) 
        : requestType(type), requestContent(rC) {}
    
    SupportType getRequestType() const { return requestType; }
    std::string getRequestContent() const { return requestContent; }
};

#endif