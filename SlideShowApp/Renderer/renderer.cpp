#include "renderer.h"
#include "../UserInterface/applicationwindow.h"

Renderer::Renderer(std::shared_ptr<ApplicationWindow> applicationWindow) : appWindow(std::move(applicationWindow))
{
    shapeMap = {
        {"circle", std::make_shared<Circle>()},
        {"elipse", std::make_shared<Elipse>()},
        {"line", std::make_shared<Line>()},
        {"rectangle", std::make_shared<Rectangle>()}
    };
}

void Renderer::display(std::string textToBeDisplayed)
{
    appWindow->displayTextOnOutputTerminal(textToBeDisplayed);
}

void Renderer::draw(std::shared_ptr<Item> item)
{
    QPainter painter(&appWindow->pixmap);
    configurePainter(painter, item);
    std::shared_ptr<Shape> shape = shapeMap[item->getKind()];
    shape->draw(item, painter);
    painter.end();
    appWindow->imageLabel->setPixmap(appWindow->pixmap.scaled(appWindow->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    appWindow->imageLabel->show();
}

void Renderer::configurePainter(QPainter& painter, const std::shared_ptr<Item>& item)
{
    QPen pen;
    pen.setWidth(5);
    QString colorName = QString::fromStdString(item->getColor());
    QColor color(colorName);
    pen.setColor(color);
    painter.setPen(pen);
}

void Renderer::draw(std::shared_ptr<Slide> slide)
{
    appWindow->setBlankScreen();
    for (auto& item : slide->getItems())
        draw(item);
}

