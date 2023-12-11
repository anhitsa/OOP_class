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
    //TK: Create file first, before serialization, serialization itself could be costly action, 
    // if file is failed toi open (i.e. because of poermission) then you do not need to do serialization  
    auto path = options.at("path");
    std::ofstream documentJson(path, std::ofstream::trunc);
    documentJson << jsonContents;
    documentJson.close();
}
