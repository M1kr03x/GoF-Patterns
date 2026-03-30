#include <iostream>
#include <vector>
#include <memory>
#include "IShape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "AreaVisitor.h"
#include "DrawVisitor.h"
int main(){
    std::vector<std::unique_ptr<IShape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));  
    shapes.push_back(std::make_unique<Square>(10.0));   
    shapes.push_back(std::make_unique<Triangle>(3, 4, 5));  

    AreaVisitor areaCalc;
    DrawVisitor drawer;

    std::cout << "Drawing" << std::endl;
    for (const auto& shape : shapes) {
        shape->accept(drawer);
    }

    std::cout << "\nArea calculation" << std::endl;
    for (const auto& shape : shapes) {
        shape->accept(areaCalc);
    }
    return 0;
}