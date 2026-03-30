#ifndef SQUARE_H
#define SQUARE_H
#include "IShape.h"
#include "IVisitor.h"
class Square : public IShape{
public:
double side;
Square(double s) : side(s) {}
void accept(IVisitor& v) override{
    v.visit(*this);
}
};
#endif