#include "removeslideaction.h"

RemoveSlideAction::RemoveSlideAction(std::shared_ptr<Slide> slide, std::shared_ptr<Document> document) : slide(slide), document(document)
{

}

void RemoveSlideAction::execute()
{
    document->remove(slide);
}

void RemoveSlideAction::undo()
{
    document->add(slide);
}
