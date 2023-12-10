#ifndef DISPLAYCOMMAND_H
#define DISPLAYCOMMAND_H

#include "command.h"
#include "../user_interface/renderer.h"

#include <map>
#include <memory>

class DisplayCommand: public Command
{
public:
    DisplayCommand(std::map<std::string, std::string> options);
    void execute() override;

private:
    std::shared_ptr<Target> determineTarget();

private:
    Renderer renderer;
    std::map<std::string, std::string> options;
};

#endif // DISPLAYCOMMAND_H
