#ifndef SLIDE_H
#define SLIDE_H

#include "Item/item.h"

#include <vector>

class Slide
{
public:
    using ID = int;
    Slide(const ID);
    void add(const std::shared_ptr<Item>&);
    void remove(const std::shared_ptr<Item>&);
    std::vector<std::shared_ptr<Item>>::iterator findItemById(const ID&);
    const ID& getId() const;
    std::string getInfo() const;
    std::vector<std::shared_ptr<Item>> getItems() const;
    ID getNewItemId() const;

private:
    std::vector<std::shared_ptr<Item>> items;
    ID id;

};

#endif // SLIDE_H
