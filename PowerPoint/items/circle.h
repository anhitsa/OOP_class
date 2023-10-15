#ifndef CIRCLE_H
#define CIRCLE_H

#include "item.h"

class Circle : public Item
{
public:
    Circle()=default;
    void draw() override;

};

#endif // CIRCLE_H
