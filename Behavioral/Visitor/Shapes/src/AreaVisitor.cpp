#include "AreaVisitor.h"
#include <iostream>
#include <cmath>
void AreaVisitor::visit(Circle&c){
    std::cout<< "Circle area: " << 3.14 * c.radius * c.radius << std::endl; 
}
void AreaVisitor::visit(Square&s){
    std::cout<< "Square area: " << s.side * s.side <<std::endl;  
}
void AreaVisitor::visit(Triangle&t){
    double p = (t.a + t.b + t.c) / 2.0;
    double area = std::sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
    std::cout<< "Triangle area: " <<area<<std::endl; 
}
