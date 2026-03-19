#include "ChatServer.h"
#include "User.h"
#include <iostream>

void ChatServer::addUser(std::shared_ptr<User> user) {
    users.insert(user);
}

void ChatServer::removeUser(std::shared_ptr<User> user) {
    users.erase(user);
}

void ChatServer::sendMessage(const std::string& msg, User* sender) {
    for (const auto& user : users) {
        if (user.get() != sender) {
            user->recieve(msg, sender->getName());
        }
    }
}

void ChatServer::notify(User* us) {
    std::cout << "User " << us->getName() << " joined to chat\n";
}