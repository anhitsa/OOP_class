#ifndef RENDERER_H
#define RENDERER_H

#include "../PresentationElements/Item/item.h"
#include "../PresentationElements/target.h"
#include "../PresentationElements/slide.h"

#include "../UserInterface/applicationwindow.h"

#include <functional>
#include <map>
#include <string>

#include <QPainter>
#include <QPen>
#include <Qt>


class Renderer
{
public:
    Renderer(std::shared_ptr<ApplicationWindow>);
    void draw(std::shared_ptr<Target>);
    void display(std::string);

private:
    void drawItem(std::shared_ptr<Item>);
    void drawSlide(std::shared_ptr<Slide>);
    void drawCircle(std::shared_ptr<Item>, QPen&, QPainter&);
    void drawElipse(std::shared_ptr<Item>, QPen&, QPainter&);
    void drawLine(std::shared_ptr<Item>, QPen&, QPainter&);
    void drawRectangle(std::shared_ptr<Item>, QPen&, QPainter&);
    std::map<std::string, std::function<void(std::shared_ptr<Item>, QPen&, QPainter&)>> drawingFunctions;

private:
    std::shared_ptr<ApplicationWindow> appWindow;
};

#endif // RENDERER_H
