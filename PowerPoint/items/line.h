#ifndef LINE_H
#define LINE_H

#include "item.h"

class Line : public Item
{
public:
    Line()
    {
        top_left.x = bottom_right.x = top_left.y = bottom_right.y = 0;
        width = height = 1;
        id = 0;
    }
};

#endif // LINE_H
