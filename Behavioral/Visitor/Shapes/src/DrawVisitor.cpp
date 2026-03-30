#include "DrawVisitor.h"
#include <iostream>

void DrawVisitor::visit(Circle& c) {
    std::cout << "[Drawing Circle] " 
              << "Position: (0,0), "
              << "Radius: " << c.radius << std::endl;
}

void DrawVisitor::visit(Square& s) {
    std::cout << "[Drawing Square] " 
              << "Side: " << s.side << std::endl;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) std::cout << "* ";
        std::cout << "\n";
    }
}

void DrawVisitor::visit(Triangle& t) {
    std::cout << "[Drawing Triangle] " 
              << "Sides: " << t.a << ", " << t.b << ", " << t.c << std::endl;
}