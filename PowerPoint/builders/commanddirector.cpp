#include "commanddirector.h"

std::unique_ptr<Command> CommandDirector::construct(std::unique_ptr<CommandBuilder> builder, std::optional<std::string> item_name,
                                   std::optional<std::string> top_left, std::optional<std::string> bottom_right,
                                   std::optional<std::string> height, std::optional<std::string> width,
                                   std::optional<std::string> id) {
    builder->addItem(item_factory.createItem(item_name));
    builder->addTopLeftCoord(top_left);
    builder->addBottomRightCoord(bottom_right);
    builder->addHeight(height);
    builder->addWidth(width);
    builder->addID(id);
    return builder->getResult();
}
