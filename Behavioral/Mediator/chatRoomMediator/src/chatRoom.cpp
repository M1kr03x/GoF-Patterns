#include "../include/user.h"
#include "../include/chatRoom.h"
 ChatRoom::ChatRoom(const std::string& roomName = "Default chat") : name(roomName) {
        std::cout << "Created a room: " << name << std::endl;
    }
void ChatRoom::join(std::shared_ptr<User> user) {
        std::cout << "\n" << user->getName() << " join channel" << name << std::endl;
        user->setRoom(shared_from_this());
        users.push_back(user);
        broadcast("Joined user: ", user);
}
    void ChatRoom::broadcast(const std::string& message, std::shared_ptr<User> sender) {
        std::cout << "Channel " << name << " sharing a message: " << std::endl;
        
        for (auto& user : users) {
            if (user != sender) { 
                user->receive(sender->getName(), message);
            }
        }
    }


    void  ChatRoom::showParticipants() {
        std::cout << "\nRoom members " << name << ":" << std::endl;
        for (size_t i = 0; i < users.size(); ++i) {
            std::cout << "  " << i+1 << ". " << users[i]->getName() << std::endl;
        }
    }

