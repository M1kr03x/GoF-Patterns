#include <iostream>
#include <memory>
#include "onlineStore.h"
#include "discountSubscriber.h"
#include "newProductSubscriber.h"
#include "orderStatusSubscriber.h"

int main() {
    OnlineStore store;
    auto discountHunter = std::make_shared<DiscountSubscriber>();
    auto productWatcher = std::make_shared<NewProductSubscriber>();
    auto priceWatcher = std::make_shared<OrderStatusSubscriber>();
    store.subscribe(discountHunter, "discount");  
    store.subscribe(productWatcher, "name");    
    store.subscribe(priceWatcher, "price"); 
    auto iphone = std::make_unique<Product>("iPhone 15", 1000.0f, 0);
    auto samsung = std::make_unique<Product>("Samsung S24", 900.0f, 5);
    store.addProduct(std::move(iphone));
    store.addProduct(std::move(samsung));
    store.setProductPrice("iPhone 15", 950.0f);
    store.setProductDiscount("Samsung S24", 15);
    store.setProductName("Samsung S24", "Galaxy S24");
    Product* p1 = store.findProduct("iPhone 15");
    if (p1) {
        std::cout << "iPhone 15 price: " << p1->_price << "\n";
    }
    Product* p2 = store.findProduct("Galaxy S24");
    if (p2) {
        std::cout << "Galaxy S24 discount: " << p2->_discount << "\n";
    }
    return 0;
}