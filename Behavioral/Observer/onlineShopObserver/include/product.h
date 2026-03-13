#include <string>
#include <functional>
class Product{
public:
std::string _productName{""};
float _price{0.f};
int _discount{0};
public:
Product(const std::string&,float,int);
};