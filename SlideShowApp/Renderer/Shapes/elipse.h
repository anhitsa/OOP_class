#ifndef ELIPSE_H
#define ELIPSE_H

#include "Shape.h"

class Elipse : public Shape
{
public:
    Elipse()=default;
    void draw(std::shared_ptr<Item>, QPainter&) override;

};

#endif // ELIPSE_H
