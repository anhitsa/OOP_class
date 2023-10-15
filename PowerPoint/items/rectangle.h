#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "item.h"

class Rectangle : public Item
{
public:
    Rectangle()=default;
    void draw() override;
};

#endif // RECTANGLE_H
