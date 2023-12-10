#include "documentmanager.h"

DocumentManager& DocumentManager::getInstance()
{
    static DocumentManager instance;
    return instance;
}

std::shared_ptr<Document> DocumentManager::getDocument() const
{
    return document;
}

void DocumentManager::setDocument(std::shared_ptr<Document> doc)
{
    document = std::move(doc);
}
