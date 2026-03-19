#include "ChatServer.h"
#include "User.h"
#include <memory>
int main(){
auto students = std::make_shared<ChatServer>();
students->setChatGroupName("Students group chat");
auto oleg = std::make_shared<User>("Oleg");
auto polina = std::make_shared<User>("Polina");
auto infcurse = std::make_shared<User>("Infcurse");
oleg->joinChatRoom(students);
polina->joinChatRoom(students);
infcurse->joinChatRoom(students);
infcurse->sendMessage("Hello world!");
polina->sendMessage("Hello !");
infcurse->leaveChatRoom();
}