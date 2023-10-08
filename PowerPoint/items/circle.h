#ifndef CIRCLE_H
#define CIRCLE_H

#include "item.h"

class Circle : public Item
{
public:
    Circle()
    {
        top_left.x = bottom_right.x = top_left.y = bottom_right.y = 0;
        width = height = 1;
        id = 0;
    }
};

#endif // CIRCLE_H
