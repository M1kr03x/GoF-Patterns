#include <iostream>
#include <memory>
#include <string>
class Conditioner {
	std::string _mode;
	short int _temperature;
public:
	Conditioner(std::string mode, short int temperature) : _mode(mode), _temperature(temperature) {}
	//setters
	void setTemperature(short int tp) {
		_temperature = tp;
	}
	void setMode(std::string md) {
		_mode = md;
	}
	void showInfo() {
		std::cout << "\n Mode: " << _mode << "\tTemperature: " << _temperature;
	}
	//getters
	short int getTemperature() const{
		return _temperature;
	}
	std::string getMode() const{
		return _mode;
	}
};
class Commands {
public:
	virtual void execute() = 0;
	virtual ~Commands() = default;
	virtual void undo() = 0;
};
class setTemperatureCommand : public Commands {
	std::shared_ptr<Conditioner> cond;
	short int temperature;
	short int tempTemperature;
public:
	setTemperatureCommand(std::shared_ptr<Conditioner> smth, short int temp) : cond(smth) { this->temperature = temp; }
	void execute() override {
		tempTemperature = cond->getTemperature();
		cond->setTemperature(temperature);
	}
	void undo() override {
	cond->setTemperature(tempTemperature);

	}

};
class setConditionerModeCommand : public Commands {
	std::shared_ptr<Conditioner> cond;
	std::string mode;
	std::string tempMode;
public:
	setConditionerModeCommand(std::shared_ptr<Conditioner> smth, std::string cndMode) : cond(smth) { this->mode = cndMode; }
	void execute() override {
		tempMode = cond->getMode();
		cond->setMode(mode);
	}
	void undo() override {
		cond->setMode(tempMode);

	}

};
class showConditionerInfoCommand : public Commands {
	std::shared_ptr<Conditioner> cond;
public:
	showConditionerInfoCommand(std::shared_ptr<Conditioner> smth) : cond(smth){}
	void execute() override {
		cond->showInfo();
	}
	void undo() override {
		std::cout << "Info command cannot be undone\n";
	}
};

class Invoker {
	std::shared_ptr<Commands> cmd;
	std::shared_ptr<Commands> undoCmd;
public:
	void setCommand(std::shared_ptr<Commands> cmd) {
		this->cmd = cmd;
	}
	void exec(){
		if (cmd) {
			cmd->execute();
			undoCmd = cmd;
	}
	}
	void execUndo() {
		if (undoCmd) {
			undoCmd->undo();
		}
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	Invoker changer;
	int n;
	auto cond{ std::make_shared<Conditioner>("Default",10) };

	while (true) {
		std::cout << "\nВыберите действие: \n1. Установить температуру > n \n2. Изменить режим > nMode\n3. Показать результат\n4. Выйти \nEnter variant:> ";
		std::cin >> n;
		switch (n)
		{
		case(1): {
			short int temperature;
			std::cout << "\n Enter temperature > ";
			std::cin >> temperature;
			auto setTempByN{ std::make_shared<setTemperatureCommand>(cond,temperature) };
			changer.setCommand(setTempByN);
			changer.exec();
			break;
		}
		case (2): {
				   std::string mode;
				   std::cout << "\n Enter mode > ";
				   std::cin >> mode;
				   auto setMode{ std::make_shared<setConditionerModeCommand>(cond,mode) };
				   changer.setCommand(setMode);
				   changer.exec();
				   break;
			   }
		case(3): {
			std::cout << "\nConditioner atribute values\n";
			auto print{
			std::make_shared<showConditionerInfoCommand>(cond)
			};
			changer.setCommand(print);
			changer.exec();
			std::cout << std::endl;
			break;
		}
		case(4):
			return 0;
		default: std::cout << "\nWrong input ";
			break;
		}
	}
	
}

