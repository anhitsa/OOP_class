#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H

#include "command.h"
#include "../user_interface/renderer.h"

#include <map>
#include <memory>

class DrawCommand: public Command
{
public:
    DrawCommand(std::map<std::string, std::string> options);
    void execute() override;

private:
    std::shared_ptr<Target> determineTarget();

private:
    Renderer renderer;
    std::map<std::string, std::string> options;
};

#endif // DRAWCOMMAND_H
