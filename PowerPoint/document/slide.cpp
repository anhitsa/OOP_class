#include "slide.h"

void Slide::addItem(std::unique_ptr<Item> item)
{
    items.push_back(std::move(item));
}

void Slide::update()
{
    ApplicationWindow& appWin = ApplicationWindow::getInstance();
    appWin.setBlankScreen();
    for(auto& item: items)
        item->draw();
}
