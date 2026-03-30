#ifndef DRAWVISITOR_H
#define DRAWVISITOR_H
#include "IVisitor.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
class DrawVisitor : public IVisitor {
public:
void visit(Circle&) override;
void visit(Square&) override;
void visit(Triangle&) override;
};
#endif