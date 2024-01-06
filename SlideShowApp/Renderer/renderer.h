#ifndef RENDERER_H
#define RENDERER_H

#include "../PresentationElements/slide.h"
#include "Shapes/circle.h"
#include "Shapes/elipse.h"
#include "Shapes/line.h"
#include "Shapes/rectangle.h"
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
    void draw(std::shared_ptr<Slide>);
    void draw(std::shared_ptr<Item>);
    void display(std::string);

private:
    void configurePainter(QPainter&, const std::shared_ptr<Item>&);

private:
    std::shared_ptr<ApplicationWindow> appWindow;
    std::map<std::string, std::shared_ptr<Shape>>  shapeMap;
};

#endif // RENDERER_H
