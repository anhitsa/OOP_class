#include "savecommand.h"

#include <fstream>
#include <filesystem>
#include <string>

void SaveCommand::execute(Slide& slide)
{
    std::ofstream slideYaml(path, std::ofstream::trunc);
    std::string contents;

    for(auto& item : slide.items)
    {
        std::string item_block = determineItemBlockText(item);
        contents += item_block;
    }

    slideYaml << contents;
    slideYaml.close();
}

std::string SaveCommand::determineItemBlockText(const Item& item) const
{
    std::string item_block = item.kind + ":\n";
    item_block += "        top_left: " + std::to_string(item.top_left.x) + "," + std::to_string(item.top_left.y) + '\n';
    item_block += "        height: " + std::to_string(item.height) + '\n';
    item_block += "        width: " + std::to_string(item.width) + "\n\n";
    return item_block;
}
