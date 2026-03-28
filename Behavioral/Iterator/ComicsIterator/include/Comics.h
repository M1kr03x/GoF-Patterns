#ifndef COMICS_H
#define COMICS_H

#include <iostream>
#include <string>

class Comics {
    std::string title;
    std::string author;
    std::string year;
    std::string publisher;
public:
    Comics(std::string t, std::string a, std::string y, std::string p);
    void printInfo();
};

#endif