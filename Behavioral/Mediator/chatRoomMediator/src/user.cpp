#include "../include/user.h"
#include "../include/chatRoom.h"
User::User(const std::string& name) : _name(name) {

}
std::string User::getName() const {return _name;}
void User::receive(const std::string& sender, const std::string &message){
    std::cout << " " << _name << " recieved from " << sender 
                  << ": \"" << message << "\"" << std::endl;
} 

 void User::send(const std::string& message) {
        std::cout << "\n" << _name << " send: \"" << message << "\"" << std::endl;
        if (room) {
            room->broadcast(message, shared_from_this());
        }
}
void User::setRoom(std::shared_ptr<ChatRoom> rm){
    room = rm;
}
User::~User(){

}