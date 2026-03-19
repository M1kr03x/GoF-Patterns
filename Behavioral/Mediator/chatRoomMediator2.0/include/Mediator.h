#include "User.h"
class Mediator {
public:
	virtual void addUser(std::shared_ptr<User>) = 0;
	virtual void removeUser(std::shared_ptr<User>) = 0;
	virtual void sendMessage(const std::string&, User*) = 0;
	virtual void notify(User*) = 0;
	virtual ~Mediator() = default;
	
};
