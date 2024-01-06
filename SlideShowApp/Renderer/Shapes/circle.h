#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
public:
    Circle()=default;
    void draw(std::shared_ptr<Item>, QPainter&) override;

};

#endif // CIRCLE_H
