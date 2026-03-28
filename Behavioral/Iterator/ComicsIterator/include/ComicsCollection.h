#ifndef COMICSCOLLECTION_H
#define COMICSCOLLECTION_H

#include <vector>
#include "Comics.h"
#include "Iterator.h"

class ComicsCollection {
    std::vector<Comics*> comics;
public:
    void addComics(Comics* c);
    Iterator<Comics*>* createIterator();
};

#endif