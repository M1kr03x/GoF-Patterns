#ifndef USER_H
#define USER_H

#include <string>
#include <memory>

class ChatServer; 

class User : public std::enable_shared_from_this<User> {
private:
    std::string userName;
    std::weak_ptr<ChatServer> mediator;

public:
    User(const std::string& name);

    std::string getName() const;
    void sendMessage(const std::string& message);
    void recieve(const std::string& msg, const std::string& sender);
    void joinChatRoom(std::shared_ptr<ChatServer> chatGroup);
    void leaveChatRoom();
};

#endif