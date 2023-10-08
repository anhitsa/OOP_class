#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "item.h"

class Triangle : public Item
{
public:
    Triangle()
    {
        top_left.x = bottom_right.x = top_left.y = bottom_right.y = 0;
        width = height = 1;
        id = 0;
    }
};

#endif // TRIANGLE_H
