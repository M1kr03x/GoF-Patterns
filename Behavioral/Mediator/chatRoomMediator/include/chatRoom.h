#pragma once
#include <memory>
#include <vector>
#include <string> 
class User;
class ChatRoom : public std::enable_shared_from_this<ChatRoom>{
private:
    std::vector<std::shared_ptr<User>> users;  
    std::string name;
public:
ChatRoom(const std::string&);
void join(std::shared_ptr<User>);
void broadcast(const std::string&, std::shared_ptr<User>);
void showParticipants();
};