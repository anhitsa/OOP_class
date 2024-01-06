#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle()=default;
    void draw(std::shared_ptr<Item>, QPainter&) override;

};

#endif // RECTANGLE_H
