#include "slide.h"

#include <memory>

Slide::Slide(const ID id) : id(id)
{

}

const Slide::ID& Slide::getId() const
{
    return id;
}

void Slide::add(const std::shared_ptr<Item>& item)
{
    items.push_back(item);
}

void Slide::remove(const std::shared_ptr<Item>& item)
{
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end())
        items.erase(it);
}

std::vector<std::shared_ptr<Item>>::iterator Slide::findItemById(const ID& itemId)
{
    return std::find_if(items.begin(), items.end(),
                        [itemId](const auto& item) {
                            return item->getId() == itemId;
                        });
}

std::vector<std::shared_ptr<Item>> Slide::getItems() const
{
    return items;
}

std::string Slide::getInfo() const
{
    std::string info;
    info += "Slide id: " + std::to_string(id) + "\n";
    for(auto& item : items)
        info += item->getInfo();
    return info;
}

Slide::ID Slide::getNewItemId() const
{
    return items.size() + 1;
}
