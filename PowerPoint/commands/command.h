#ifndef COMMAND_H
#define COMMAND_H

#include "../items/item.h"
#include "../document/slide.h"

#include <memory>
#include <optional>
#include <string>

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute(Slide&) = 0;
};

#endif // COMMAND_H
