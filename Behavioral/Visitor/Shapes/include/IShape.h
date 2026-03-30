#ifndef ISHAPE_H
#define ISHAPE_H
class IVisitor;
class IShape{
    public:
virtual void accept(IVisitor&) = 0;
virtual ~IShape() = default;
};

#endif