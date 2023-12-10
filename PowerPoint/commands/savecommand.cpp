#include "../document/documentmanager.h"
#include "savecommand.h"

#include <fstream>
#include <filesystem>
#include <string>

SaveCommand::SaveCommand(std::map<std::string, std::string> options)
    : options(options) {}

void SaveCommand::execute()
{
    std::shared_ptr<Document> document = DocumentManager::getInstance().getDocument();
    std::string jsonContents = serializer.serializeToJson(document);
    auto path = options.at("path");
    std::ofstream documentJson(path, std::ofstream::trunc);
    documentJson << jsonContents;
    documentJson.close();
}
