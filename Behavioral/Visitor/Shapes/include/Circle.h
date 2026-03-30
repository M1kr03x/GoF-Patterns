#ifndef CIRCLE_H
#define CIRCLE_H
#include "IShape.h"
#include "IVisitor.h"
class Circle : public IShape{
public:
double radius;
Circle(double r) : radius(r) {}
void accept(IVisitor& v) override{
    v.visit(*this);
}
};
#endif