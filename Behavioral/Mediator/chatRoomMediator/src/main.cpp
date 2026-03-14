#include <iostream>
#include "../include/user.h"
#include "../include/chatRoom.h"
int main(){
    auto room = std::make_shared<ChatRoom>("Room");
    auto jebrony = std::make_shared<User>("jebro");
    auto mctraXXXer = std::make_shared<User>("McTRX");
    auto jerom = std::make_shared<User>("Jerom");
    
    room->join(jebrony);
    room->join(mctraXXXer);
    room->join(jerom);
    
    room->showParticipants();

    jebrony->send("Hello guys");
    mctraXXXer->send("God daaaamn");
    jerom->send("ISNT IT A MEDIATOR REALISATION????");   
    return 0;
}