#include "savecommand.h"

#include <fstream>
#include <filesystem>
#include <string>

SaveCommand::SaveCommand(std::map<std::string, std::string> options_, std::shared_ptr<Document> document, std::shared_ptr<Serializer> serializer)
    : document(std::move(document)), serializer(std::move(serializer))
{
    options = std::move(options_);
}

void SaveCommand::execute()
{
    auto path = options.at("path");
    std::ofstream documentJson(path, std::ofstream::trunc);
    if (documentJson.is_open())
    {
        std::string jsonContents = serializer->serializeToJson(document);
        documentJson << jsonContents;
        documentJson.close();
    }
}

