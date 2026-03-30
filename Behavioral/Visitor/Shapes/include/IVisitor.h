#ifndef IVISITOR_H
#define IVISITOR_H
class Circle;
class Square;
class Triangle;
class IVisitor{
public:
virtual void visit(Circle&) = 0;
virtual void visit(Square&) = 0;
virtual void visit(Triangle&) = 0;
};
#endif