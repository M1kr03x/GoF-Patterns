#include <algorithm>
#include <iostream>
#include "../include/onlineStore.h"

OnlineStore& OnlineStore::subscribe(std::shared_ptr<Observer> subscriber, const std::string& type){
    subscribers[type].push_back(subscriber);
    return *this;
}
OnlineStore& OnlineStore::unsubscribe(std::shared_ptr<Observer> subscriber, const std::string& type){
    auto& tempVec = subscribers[type];
    auto iterator = std::remove(tempVec.begin(), tempVec.end(), subscriber);
    tempVec.erase(iterator, tempVec.end()); 
    return *this;
}
void OnlineStore::notifyObservers(const std::string& type, const std::string& propName, const std::string&propValue){
 for(std::shared_ptr<Observer> sub : subscribers[type]){
    sub->update(propName,propValue);
 }
}
    Product* OnlineStore::findProduct(const std::string& name) {
        for (auto& p : products) {
            if (p->_productName == name) return p.get();
        }
        return nullptr;
    }

    void OnlineStore::setProductPrice(const std::string& name, float newPrice) {
        Product* p = findProduct(name);
        if (p) {
            p->_price = newPrice;
            notifyObservers("price", "Price", std::to_string(newPrice));
        }
    }

    void OnlineStore::setProductDiscount(const std::string& name, int newDiscount) {
        Product* p = findProduct(name);
        if (p) {
            p->_discount = newDiscount;
            notifyObservers("discount", "Discount", std::to_string(newDiscount));
        }
    }
void OnlineStore::setProductName(const std::string& name, const std::string& newName){
        Product* p = findProduct(name);
        if (p) {
            p->_productName = newName;
            notifyObservers("name", "Product", newName);
        }
}
void OnlineStore::addProduct(std::unique_ptr<Product> prod){
    products.push_back(std::move(prod));
}