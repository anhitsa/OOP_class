#ifndef CHANGEACTION_H
#define CHANGEACTION_H

#include "commandaction.h"
#include "../document/target.h"

#include <memory>
#include <string>
#include <unordered_map>

class ChangeAction : public CommandAction
{
public:
    ChangeAction(std::shared_ptr<Target> target, std::unordered_map<std::string, std::string> options)
        : target(target), options(options) {}

    void execute() override;
    void undo() override;

private:
    std::shared_ptr<Target> target;
    std::unordered_map<std::string, std::string> options;

};

#endif // CHANGEACTION_H
