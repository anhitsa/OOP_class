#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include "document.h"

#include <memory>

class Document;

class DocumentManager
{
public:
    static DocumentManager& getInstance();
    std::shared_ptr<Document> getDocument() const;
    void setDocument(std::shared_ptr<Document> doc);

private:
    DocumentManager() = default;
    std::shared_ptr<Document> document;

};


#endif // DOCUMENTMANAGER_H
