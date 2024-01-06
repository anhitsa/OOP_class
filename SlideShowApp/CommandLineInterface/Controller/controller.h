#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../CommandFactory/commandfactory.h"
#include "../CommandParser/commandparser.h"
#include "../../UserInterface/commandlineinputbox.h"
#include "../../UserInterface/commandlineoutputLog.h"

#include <memory>

class Controller
{
public:
    Controller();
    std::shared_ptr<CommandLineInputBox> getCommandLineInputBox() const;
    std::shared_ptr<CommandLineOutputLog> getCommandLineOutputBox() const;
    std::shared_ptr<CommandFactory> getCommandFactory() const;
    void setCommandFactory(std::shared_ptr<CommandFactory>);

private:
    CommandParser commandParser;
    std::shared_ptr<CommandFactory> commandFactory;
    std::shared_ptr<CommandLineInputBox> commandLineInputBox;
    std::shared_ptr<CommandLineOutputLog> commandLineOutputBox;

};

#endif // CONTROLLER_H
