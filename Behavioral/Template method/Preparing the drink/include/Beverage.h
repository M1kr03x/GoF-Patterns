#include <string>
inline constexpr int TIME = 2;
class Beverage {
public:
    Beverage(std::string n) : name(n){}
     void prepare() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }
protected:
    std::string name;

    void boilWater();
    void pourInCup();

    virtual void addCondiments() {};
    virtual void brew() = 0;    
    virtual ~Beverage() = default;
};