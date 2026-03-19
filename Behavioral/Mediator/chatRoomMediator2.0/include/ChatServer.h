#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H

#include "Mediator.h"
#include <unordered_set>
#include <string>
#include <memory>

class User;

class ChatServer : public Mediator {
public:
    void addUser(std::shared_ptr<User> user) override;
    void removeUser(std::shared_ptr<User> user) override;
    void sendMessage(const std::string& msg, User* sender) override;
    void notify(User* us) override;
    
    void setChatGroupName(const std::string& n) { chatGroupName = n; }

private:
    std::unordered_set<std::shared_ptr<User>> users;
    std::string chatGroupName;
};

#endif