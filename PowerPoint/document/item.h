#ifndef ITEM_H
#define ITEM_H

#include "coord.h"
#include "target.h"

#include <map>
#include <string>

//TK: May be this is good idea to make slide and item addable targets by I can't image it;s benefits yet, we can discuss it later
class Item : public Target
{
public:
    //TK: There is no need to have such variations of constructor, you need Rect class instead, and item will take rect 
    Item(std::string kind, Coord top_left, int height, int width, int id);
    Item(std::string kind, Coord top_left, Coord bottom_right, int id);
    Item(std::string kind, Coord top_left, Coord bottom_right, int height, int width, int id);
    void changeParameters(std::map<std::string, std::string> options) override;
    //TK: Undo is not responsibility of the item itself
    void undoParametersChange() override;
    Item& operator=(const Item& other);
    bool operator==(const Item& other) const { return this->id == other.id; }

    void setKind(const std::string&);
    const std::string& getKind() const;
    //TK: Set get whole geometry instead
    void setTopLeft(const Coord&);
    const Coord& getTopLeft() const;
    void setBottomRight(const Coord&);
    const Coord& getBottomRight() const;
    void setHeight(int);
    int getHeight() const;
    void setWidth(int);
    int getWidth() const;

    //TK: define id type, at least something like: using ItemId = int;
    void setId(int); //TK: You should allow to change item's Id, it should be initialized once and never changed
    int getId() const override;

private:
    std::string kind;
    Coord top_left, bottom_right;
    int height, width;
    int id; //TK: should be ItemId const id;

    std::map<std::string, std::variant<Coord, int>> prevParameters;

private:
    void saveParameters(); // TK: What is this for?

 };

#endif // ITEM_H
