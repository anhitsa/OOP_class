#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape
{
public:
    Line()=default;
    void draw(std::shared_ptr<Item>, QPainter&) override;

};

#endif // LINE_H
