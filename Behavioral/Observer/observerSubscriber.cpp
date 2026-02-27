#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
class observer {
public:
	void update(const std::string &propertyName, const std::string &propertyValue) const {
		std::cout << propertyName << " has been changed to " << propertyValue;
	}
};
class Account {
	
	std::string _login;
	bool _isOnline;
	std::vector<observer*> _obs;
public:
	Account(std::string login, bool isOnlne) : _login(login), _isOnline(isOnlne){}
	void addSubscriber(observer *ab) {
		_obs.push_back(ab);
	}
	void deleteSubscriber(observer* ab) {
		auto object = std::find(_obs.begin(), _obs.end(), ab);
			if (object != _obs.end()) {
				_obs.erase(object);
			}

	}
	void setLogin(const std::string &log) {
		if (_login != log) {
			_login = log;
			notify("Login", log);
		}
	}
	void setOnline(bool status) {
		if (_isOnline != status) {
			_isOnline = status;
			notify("isOnline", status ? "Online" : "Offline");
		}
	}
	std::string getLogin() {
		return _login;
	}
	bool getOnline() {
		return _isOnline;
	}
private:
	void notify(const std::string& propertyName, const std::string& propertyValue) {
		for (auto obj : _obs) { obj->update(propertyName, propertyValue); }
	}

};


int main()
{
	Account acc("Delog", false);
	observer obs;
	acc.addSubscriber(&obs);
	acc.setLogin("NewLog");
	std::cout << std::endl;
	acc.setOnline(true);

}

