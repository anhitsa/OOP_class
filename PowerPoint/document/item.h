#ifndef ITEM_H
#define ITEM_H

#include "coord.h"
#include "target.h"

#include <map>
#include <string>

class Item : public Target
{
public:
    Item(std::string kind, Coord top_left, int height, int width, int id);
    Item(std::string kind, Coord top_left, Coord bottom_right, int id);
    Item(std::string kind, Coord top_left, Coord bottom_right, int height, int width, int id);
    void changeParameters(std::map<std::string, std::string> options) override;
    void undoParametersChange() override;
    Item& operator=(const Item& other);
    bool operator==(const Item& other) const { return this->id == other.id; }

    void setKind(const std::string&);
    const std::string& getKind() const;
    void setTopLeft(const Coord&);
    const Coord& getTopLeft() const;
    void setBottomRight(const Coord&);
    const Coord& getBottomRight() const;
    void setHeight(int);
    int getHeight() const;
    void setWidth(int);
    int getWidth() const;
    void setId(int);
    int getId() const override;

private:
    std::string kind;
    Coord top_left, bottom_right;
    int height, width;
    int id;

    std::map<std::string, std::variant<Coord, int>> prevParameters;

private:
    void saveParameters();

};

#endif // ITEM_H
