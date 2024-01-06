#ifndef REMOVEITEMACTION_H
#define REMOVEITEMACTION_H

#include "commandaction.h"
#include "../../PresentationElements/slide.h"

#include <memory>

class RemoveItemAction : public CommandAction
{
public:
    RemoveItemAction(std::shared_ptr<Item>, std::shared_ptr<Slide>);
    void execute() override;
    void undo() override;

private:
    std::shared_ptr<Item> item;
    std::shared_ptr<Slide> slide;

};

#endif // REMOVEITEMACTION_H
