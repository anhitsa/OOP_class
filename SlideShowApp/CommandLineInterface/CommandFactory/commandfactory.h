#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "../Commands/command.h"
#include "../../ActionHandler/ActionManager/actionmanager.h"
#include "../../PresentationElements/Item/coord.h"
#include "../../PresentationElements/document.h"
#include "../../PresentationElements/Item/item.h"
#include "../../Renderer/renderer.h"
#include "../../Serializer/serializer.h"

#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>

class CommandFactory
{
public:
    CommandFactory()=default;
    CommandFactory(std::shared_ptr<Document>, std::shared_ptr<Renderer>, std::shared_ptr<Serializer>, std::shared_ptr<ActionManager>);
    std::unique_ptr<Command> createCommand(const std::string, std::map<std::string, std::string>);

private:
    std::map<std::string, std::function<std::unique_ptr<Command>(const std::map<std::string, std::string>&)>> commands;

};

#endif // COMMANDFACTORY_H
