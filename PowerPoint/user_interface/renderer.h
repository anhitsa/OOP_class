#ifndef RENDERER_H
#define RENDERER_H

#include "../document/item.h"
#include "../document/slide.h"
#include "../document/target.h"

#include <functional>
#include <map>
#include <string>

#include <QPainter>
#include <QPen>
#include <Qt>

class ApplicationWindow;

class Renderer
{
public:
    Renderer();
    void draw(std::shared_ptr<Target>);
    void display(std::shared_ptr<Target>);

private:
    void drawItem(std::shared_ptr<Item>);
    void drawSlide(std::shared_ptr<Slide>);
    void drawCircle(std::shared_ptr<Item>, QPen&, QPainter&);
    void drawElipse(std::shared_ptr<Item>, QPen&, QPainter&);
    void drawLine(std::shared_ptr<Item>, QPen&, QPainter&);
    void drawRectangle(std::shared_ptr<Item>, QPen&, QPainter&);
    std::map<std::string, std::function<void(std::shared_ptr<Item>, QPen&, QPainter&)>> drawingFunctions;

private:
    ApplicationWindow& appWindow;
};

#endif // RENDERER_H
