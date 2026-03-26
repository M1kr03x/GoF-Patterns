#include "../include/Drinks.h"
#include "../include/Beverage.h"
int main(){
Coffee espresso("Espresso");
espresso.prepare();
Tea greenTea("Green Tea");
greenTea.prepare();
Cocoa hotCocoa("Hot Cocoa");
hotCocoa.prepare();
Beverage* drinks[] = { &espresso, &greenTea, &hotCocoa };
for (const auto &drink : drinks) {
    drink->prepare();
}
}