#ifndef CHANGEACTION_H
#define CHANGEACTION_H

#include "commandaction.h"
#include "../../PresentationElements/Item/item.h"

#include <map>
#include <memory>
#include <string>

class ChangeAction : public CommandAction
{
public:
    ChangeAction(std::shared_ptr<Item>, std::map<std::string, std::string>);
    void execute() override;
    void undo() override;

private:
    std::shared_ptr<Item> item;
    std::map<std::string, std::string> options;

};

#endif // CHANGEACTION_H
