#include "addslideaction.h"

AddSlideAction::AddSlideAction(std::shared_ptr<Slide> slide, std::shared_ptr<Document> document)
    : slide(slide), document(document)
{

}

void AddSlideAction::execute()
{
    document->add(slide);
}

void AddSlideAction::undo()
{
    document->remove(slide);
}
