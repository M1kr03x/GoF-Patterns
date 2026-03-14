#pragma once
#include <memory>
#include <string>
#include <iostream>
class ChatRoom;
class User : public std::enable_shared_from_this<User>{
private:
std::string _name;
std::shared_ptr<ChatRoom> room;
public:
std::string getName() const;
void receive(const std::string&, const std::string&);
void setRoom(std::shared_ptr<ChatRoom>);
 void send(const std::string&);
User(const std::string&);
~User();
};