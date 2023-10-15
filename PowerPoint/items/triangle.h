#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "item.h"

class Triangle : public Item
{
public:
    Triangle()=default;
    void draw() override;
};

#endif // TRIANGLE_H
