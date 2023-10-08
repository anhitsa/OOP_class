#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "item.h"

class Rectangle : public Item
{
public:
    Rectangle()
    {
        top_left.x = bottom_right.x = top_left.y = bottom_right.y = 0;
        width = height = 1;
        id = 0;
    }
};

#endif // RECTANGLE_H
