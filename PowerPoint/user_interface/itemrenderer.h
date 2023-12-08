#ifndef ITEMRENDERER_H
#define ITEMRENDERER_H

#include "../items/item.h"

#include <functional>
#include <string>
#include <unordered_map>

#include <QPainter>
#include <QPen>
#include <Qt>

class ApplicationWindow;

class ItemRenderer
{
public:
    ItemRenderer();
    void drawItem(const Item&);

private:
    void drawCircle(const Item&, QPen& pen, QPainter&);
    void drawElipse(const Item&, QPen& pen, QPainter&);
    void drawLine(const Item&, QPen& pen, QPainter&);
    void drawRectangle(const Item&, QPen& pen, QPainter&);
    std::unordered_map<std::string, std::function<void(const Item&, QPen&, QPainter&)>> drawingFunctions;

private:
    ApplicationWindow& appWindow;
};

#endif // ITEMRENDERER_H
