#include <iostream>
#include <memory>
#include <string>
#include <vector>
class Product {
private:
	std::string _name;
	float _price;
public:
	Product(float price, std::string name) : _name(name),_price(price){}
	//setters
	void setPrice(float f) {
		_price = f;
	}
	void setName(std::string name) {
		_name = name;
	}
	//getters
	float getPrice() const { return _price; }
	std::string getName() const {return _name; }

};

class DiscountStrategy {
public:
	virtual float getDiscount(float price) = 0;
	virtual std::string getInfo() = 0;
};
class GoldenCustomerDiscount : public DiscountStrategy{
	

	float getDiscount(float price) override{
		return price * 0.8f;
	}
	std::string getInfo() override{
		return "Golden customer discount";
	}
};
class SilverCustomerDiscount : public DiscountStrategy {
	float getDiscount(float price) override {
		return price * 0.85f;
	}
	std::string getInfo() override {
		return "Silver customer discount";
	}
};
class BronzeCustomerDiscount : public DiscountStrategy {
	float getDiscount(float price) override {
		return price * 0.9f;
	}
	std::string getInfo() override {
		return "Bronze customer discount";
	}
};
class DefaultCustomerDiscount : public DiscountStrategy {
	float getDiscount(float price) override {
		return price;
	}
	std::string getInfo() override {
		return "You dont have discount";
	}
};
class Cart {
private:	
	std::vector<Product> products;
	std::unique_ptr<DiscountStrategy> discount;
	
public:
	void setStrategy(std::unique_ptr<DiscountStrategy> strategy) {
		discount = std::move(strategy);
	}
	Cart& addProduct(const Product&smth ) {
		products.push_back(smth);
		return *this;
	}
	float getProductsSum() {
		float sum{0};
		if (products.size() == 0) { std::cout << "Cart is empty"; return 0; }
		for (const auto& it : products) {
			sum += discount->getDiscount(it.getPrice());
		}
		return sum;
	}
	
};
int main()
{
	setlocale(LC_ALL, "ru");
	Product iphone(1000.f, "iphone");
	Product pocoX3NFC(50000.f, "PocoX3nfc");
	Product apple(50.f, "Green apple");
	Cart shoppingCart;
	shoppingCart.addProduct(iphone).addProduct(pocoX3NFC);
	shoppingCart.setStrategy(std::make_unique<GoldenCustomerDiscount>());
	float sum = shoppingCart.getProductsSum();
	std::cout <<"Total sum = " << sum;


}

