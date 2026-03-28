#include "../include/ComicsCollection.h"

void ComicsCollection::addComics(Comics* c) {
    comics.push_back(c);
}

Iterator<Comics*>* ComicsCollection::createIterator() {
    return new Iterator<Comics*>(comics.data(), comics.data() + comics.size());
}