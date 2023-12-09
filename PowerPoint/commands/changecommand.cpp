#include "changecommand.h"
#include "../document/document.h"

ChangeCommand::ChangeCommand(std::unordered_map<std::string, std::string> options)
    : options(options) {}

void ChangeCommand::execute()
{
    std::shared_ptr<Target> target = determineTarget();

    std::shared_ptr<CommandAction> action = std::make_shared<ChangeAction>(target, options);
    action->execute();
    commandHistory.push(action);
}

std::shared_ptr<Target> ChangeCommand::determineTarget()
{
    if (options.find("--id") != options.end())
    {
        int targetId = options.at("--id");

        auto item = document.findItemById(targetId);
        if (item)
            options.erase("--id");
            return item;

        auto slide = document.findSlideById(targetId);
        if (slide)
            options.erase("--id");
            return slide;

        throw std::invalid_argument("Target with the given ID not found");
    }
    throw std::invalid_argument("--id option is required for the Change command");
}



/*for(auto& item : slide.items)
    {
        if(item.id == id)
        {
            if(top_left)
                item.top_left = top_left;
            if(bottom_right)
                item.bottom_right = bottom_right;
            if(height)
                item.height = height;
            if(width)
                item.width = width;
            slide.update();
            return;
        }
    }*/
