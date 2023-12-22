#ifndef ITEM_H
#define ITEM_H

#include "../target.h"
#include "rectangle.h"

#include <string>

class Item : public Target
{
public:
    Item(std::string kind, Rectangle rect, ID id);
    Item& operator=(const Item& other);
    bool operator==(const Item& other) const { return this->id == other.id; }

    void setKind(const std::string&);
    void setGeometry(const Rectangle&);
    void setId(const ID&);
    std::string getInfo() const override;
    const std::string& getKind() const;
    Rectangle getGeometry() const;
    const ID& getId() const override;

private:
    std::string kind;
    Rectangle rect;
    ID id;

};

#endif // ITEM_H
