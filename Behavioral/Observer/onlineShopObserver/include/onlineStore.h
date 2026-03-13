#include <vector>
#include "Product.h"
#include "subject.h"
class OnlineStore : public ISubject{
private:
std::vector<std::unique_ptr<Product>> products; 
std::map<std::string,std::vector<std::shared_ptr<Observer>>> subscribers;
struct Prod{

};
public:
Product* findProduct(const std::string&);

void addProduct(std::unique_ptr<Product>);
//getters
float getProductPrice() const;
std::string getProductName() const;
int getProductDiscount() const;
//setters
void setProductPrice(const std::string&,float);
void setProductName(const std::string&,const std::string&);
void setProductDiscount(const std::string&,int );
//Interface overrides
OnlineStore& subscribe(std::shared_ptr<Observer>,const std::string&) override;
OnlineStore& unsubscribe(std::shared_ptr<Observer>,const std::string&) override;
void notifyObservers(const std::string&,const std::string&, const std::string&) override;
};