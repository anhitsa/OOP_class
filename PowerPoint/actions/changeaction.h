#ifndef CHANGEACTION_H
#define CHANGEACTION_H

#include "commandaction.h"
#include "../document/target.h"

#include <map>
#include <memory>
#include <string>

class ChangeAction : public CommandAction
{
public:
    ChangeAction(std::shared_ptr<Target> target, std::map<std::string, std::string> options)
        : target(target), options(options) {}

    void execute() override;
    void undo() override;

private:
    std::shared_ptr<Target> target;
    std::map<std::string, std::string> options;

};

#endif // CHANGEACTION_H
