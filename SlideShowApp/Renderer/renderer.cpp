#include "renderer.h"
#include "../UserInterface/applicationwindow.h"

Renderer::Renderer(std::shared_ptr<ApplicationWindow> applicationWindow) : appWindow(std::move(applicationWindow))
{
    //TK: Drawing functions will not stay as simple, it will be better to use Shapes instead of lambdas
    drawingFunctions = {
        {"circle", [this](std::shared_ptr<Item> item, QPen& pen, QPainter& painter) { drawCircle(item, pen, painter); }},
        {"elipse", [this](std::shared_ptr<Item> item, QPen& pen, QPainter& painter) { drawElipse(item, pen, painter); }},
        {"line", [this](std::shared_ptr<Item> item, QPen& pen, QPainter& painter) { drawLine(item, pen, painter); }},
        {"rectangle", [this](std::shared_ptr<Item> item, QPen& pen, QPainter& painter) { drawRectangle(item, pen, painter); }}
    };
}

void Renderer::draw(std::shared_ptr<Target> target)
{
    //TK: you can use Visitor pattern instead of dynamic casts
    if (std::dynamic_pointer_cast<Item>(target))
        drawItem(std::dynamic_pointer_cast<Item>(target));
    else if (std::dynamic_pointer_cast<Slide>(target))
        drawSlide(std::dynamic_pointer_cast<Slide>(target));
}

void Renderer::display(std::string textToBeDisplayed)
{
    appWindow->displayTextOnOutputTerminal(textToBeDisplayed);
}

void Renderer::drawItem(std::shared_ptr<Item> item)
{
    QPainter painter(&appWindow->pixmap);
    painter.setBrush(Qt::Dense7Pattern);
    QPen pen;
    pen.setWidth(5);
    drawingFunctions[item->getKind()](item, pen, painter);
    painter.end();

    appWindow->imageLabel->setPixmap(appWindow->pixmap.scaled(appWindow->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    appWindow->imageLabel->show();
}

void Renderer::drawSlide(std::shared_ptr<Slide> slide)
{
    appWindow->setBlankScreen();
    for (auto& target : slide->getTargets())
        draw(target);
}

void Renderer::drawCircle(std::shared_ptr<Item> item, QPen& pen, QPainter& painter)
{
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    painter.drawEllipse(item->getGeometry().getTopLeft().getX(), item->getGeometry().getTopLeft().getY(), item->getGeometry().getWidth(), item->getGeometry().getWidth());
}

void Renderer::drawElipse(std::shared_ptr<Item> item, QPen& pen, QPainter& painter)
{
    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.drawEllipse(item->getGeometry().getTopLeft().getX(), item->getGeometry().getTopLeft().getY(), item->getGeometry().getWidth(), item->getGeometry().getHeight());
}

void Renderer::drawRectangle(std::shared_ptr<Item> item, QPen& pen, QPainter& painter)
{
    pen.setColor(Qt::yellow);
    painter.setPen(pen);
    painter.drawRect(QRect(item->getGeometry().getTopLeft().getX(), item->getGeometry().getTopLeft().getY(),item->getGeometry().getWidth(), item->getGeometry().getHeight()));
}

void Renderer::drawLine(std::shared_ptr<Item> item, QPen& pen, QPainter& painter)
{
    pen.setColor(Qt::green);
    painter.setPen(pen);
    painter.drawLine(item->getGeometry().getTopLeft().getX(), item->getGeometry().getTopLeft().getY(), item->getGeometry().getTopLeft().getX() + item->getGeometry().getWidth(), item->getGeometry().getTopLeft().getY() + item->getGeometry().getWidth());
}
