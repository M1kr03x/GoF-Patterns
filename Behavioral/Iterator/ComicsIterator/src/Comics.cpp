#include "../include/Comics.h"

Comics::Comics(std::string t, std::string a, std::string y, std::string p) 
    : title(t), author(a), year(y), publisher(p) {}

void Comics::printInfo() {
    std::cout << "Title: " << title << "\nAuthor: " << author 
              << "\nYear: " << year << "\nPublisher: " << publisher << std::endl;
}