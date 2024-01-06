#ifndef REMOVESLIDEACTION_H
#define REMOVESLIDEACTION_H

#include "commandaction.h"
#include "../../PresentationElements/document.h"

class RemoveSlideAction : public CommandAction
{
public:
    RemoveSlideAction(std::shared_ptr<Slide>, std::shared_ptr<Document>);
    void execute() override;
    void undo() override;

private:
    std::shared_ptr<Slide> slide;
    std::shared_ptr<Document> document;

};

#endif // REMOVESLIDEACTION_H
