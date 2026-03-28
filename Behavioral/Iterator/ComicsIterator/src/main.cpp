#include <iostream>
#include <memory>
#include "../include/ComicsCollection.h"

int main() {
    ComicsCollection coll;

    auto c1 = std::make_shared<Comics>(
        "Чистая архитектура", 
        "Роберт Мартин", 
        "2017", 
        "Питер"
    );
    auto c2 = std::make_shared<Comics>(
        "Приемы объектно-ориентированного проектирования (GoF)", 
        "Э. Гамма, Р. Хелм, Р. Джонсон, Дж. Влиссидес", 
        "1994", 
        "Addison-Wesley"
    );
    coll.addComics(c1.get());
    coll.addComics(c2.get());

    Iterator<Comics*>* it = coll.createIterator();

    while (it->hasNext()) {
        (*it)->printInfo();
        std::cout << std::endl;
        ++(*it);
    }

    delete it;
    return 0;
}