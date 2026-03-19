#include "User.h"
#include "ChatServer.h"
#include <iostream>

User::User(const std::string& name) : userName(name) {}

std::string User::getName() const { 
    return userName; 
}

void User::sendMessage(const std::string& message) {
    if (auto med = mediator.lock()) {
        med->sendMessage(message, this);
    }
}

void User::recieve(const std::string& msg, const std::string& sender) {
    std::cout << "User " << userName << " recieved message [ " << msg 
              << " ] from " << sender << std::endl;
}

void User::joinChatRoom(std::shared_ptr<ChatServer> chatGroup) {
    if (!chatGroup) return;
    mediator = chatGroup;
    chatGroup->addUser(shared_from_this());
    chatGroup->notify(this);
}

void User::leaveChatRoom() {
    if (auto med = mediator.lock()) {
        med->removeUser(shared_from_this());
    }
    mediator.reset();
    std::cout << userName << " Left the chat room.\n";
}