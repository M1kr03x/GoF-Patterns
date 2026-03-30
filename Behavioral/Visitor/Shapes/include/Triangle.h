#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "IShape.h"
#include "IVisitor.h"
class Triangle : public IShape{
public:
double a,b,c;
Triangle(double a,double b,double c) : a(a),b(b),c(c) {}
void accept(IVisitor& v) override{
    v.visit(*this);
}
};
#endif