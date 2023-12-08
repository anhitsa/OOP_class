#include "itemrenderer.h"
#include "../user_interface/application_window.h"

ItemRenderer::ItemRenderer() : appWindow(ApplicationWindow::getInstance())
{
    drawingFunctions = {
        {"circle", [this](const Item& item, QPen& pen, QPainter& painter) { drawCircle(item, pen, painter); }},
        {"elipse", [this](const Item& item, QPen& pen, QPainter& painter) { drawElipse(item, pen, painter); }},
        {"line", [this](const Item& item, QPen& pen, QPainter& painter) { drawLine(item, pen, painter); }},
        {"rectangle", [this](const Item& item, QPen& pen, QPainter& painter) { drawRectangle(item, pen, painter); }}
    };
}

void ItemRenderer::drawItem(const Item& item)
{
    QPainter painter(&appWindow.pixmap);
    painter.setBrush(Qt::Dense7Pattern);
    QPen pen;
    pen.setWidth(5);
    drawingFunctions[item.kind](item, pen, painter);
    painter.end();

    appWindow.imageLabel->setPixmap(appWindow.pixmap.scaled(appWindow.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    appWindow.imageLabel->show();
}

void ItemRenderer::drawCircle(const Item& item, QPen& pen, QPainter& painter)
{
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    painter.drawEllipse(item.top_left.x, item.top_left.y, item.width, item.width);
}

void ItemRenderer::drawElipse(const Item& item, QPen& pen, QPainter& painter)
{
    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.drawEllipse(item.top_left.x, item.top_left.y, item.width, item.height);
}

void ItemRenderer::drawRectangle(const Item& item, QPen& pen, QPainter& painter)
{
    pen.setColor(Qt::yellow);
    painter.setPen(pen);
    painter.drawRect(QRect(item.top_left.x, item.top_left.y, item.width, item.height));
}

void ItemRenderer::drawLine(const Item& item, QPen& pen, QPainter& painter)
{
    pen.setColor(Qt::green);
    painter.setPen(pen);
    painter.drawLine(item.top_left.x, item.top_left.y, item.top_left.x + item.width, item.top_left.y + item.width);
}
