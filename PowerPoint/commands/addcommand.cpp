#include "addcommand.h"
#include "../items/item.h"

int AddCommand::id_count = 0;

void AddCommand::execute(Slide& slide)
{
    std::unique_ptr<ItemBuilder> item_builder = item_builder_factory.createItemBuilder(item_name);
    auto item =  item_director.construct(std::move(item_builder), top_left, std::make_optional<Coord>(bottom_right),
                                        std::make_optional<Item::Length>(height), std::make_optional<Item::Length>(width), ++id_count);

    slide.items.push_back(std::move(item));
}


