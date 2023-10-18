#include "commanddirector.h"

std::unique_ptr<Command> CommandDirector::construct(std::unique_ptr<CommandBuilder> builder,
                                                    std::map<std::string, std::optional<std::string>> options) {
    builder->addItemName(options["item"]);
    builder->addTopLeftCoord(options["top_left"]);
    builder->addBottomRightCoord(options["bottom_right"]);
    builder->addHeight(options["height"]);
    builder->addWidth(options["width"]);
    builder->addID(options["id"]);
    return builder->getResult();
}
