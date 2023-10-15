#ifndef LINE_H
#define LINE_H

#include "item.h"

class Line : public Item
{
public:
    Line()=default;
    void draw() override;
};

#endif // LINE_H
