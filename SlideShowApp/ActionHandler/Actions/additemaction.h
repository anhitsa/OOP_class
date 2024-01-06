#ifndef ADDITEMACTION_H
#define ADDITEMACTION_H

#include "commandaction.h"
#include "../../PresentationElements/slide.h"

#include <memory>

class AddItemAction : public CommandAction
{
public:
    AddItemAction(std::shared_ptr<Item> item, std::shared_ptr<Slide> slide);
    void execute() override;
    void undo() override;

private:
    std::shared_ptr<Item> item;
    std::shared_ptr<Slide> slide;

};

#endif // ADDITEMACTION_H
