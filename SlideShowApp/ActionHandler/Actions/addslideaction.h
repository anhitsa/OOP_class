#ifndef ADDSLIDEACTION_H
#define ADDSLIDEACTION_H

#include "commandaction.h"
#include "../../PresentationElements/document.h"

#include <memory>

class AddSlideAction : public CommandAction
{
public:
    AddSlideAction(std::shared_ptr<Slide> slide, std::shared_ptr<Document> document);
    void execute() override;
    void undo() override;

private:
    std::shared_ptr<Slide> slide;
    std::shared_ptr<Document> document;

};

#endif // ADDSLIDEACTION_H
