#ifndef COMMANDBUILDER_H
#define COMMANDBUILDER_H

#include "../items/item.h"

#include <memory>
#include <optional>

class Command;

class CommandBuilder
{
public:
    virtual void addItem(const std::optional<std::unique_ptr<Item>>) {}
    virtual void addTopLeftCoord(const std::optional<std::string>) {}
    virtual void addBottomRightCoord(const std::optional<std::string>) {}
    virtual void addHeight(const std::optional<std::string>) {}
    virtual void addWidth(const std::optional<std::string>) {}
    virtual void addID(const std::optional<std::string>) {}
    virtual std::unique_ptr<Command> getResult() = 0;
    virtual ~CommandBuilder() = default;
};

#endif // COMMANDBUILDER_H
