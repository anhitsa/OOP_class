#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H

#include "command.h"
#include "../../Serializer/serializer.h"

class SaveCommand: public Command
{
public:
    SaveCommand(std::map<std::string, std::string> options, std::shared_ptr<Document>, std::shared_ptr<Serializer>);
    void execute() override;

public:
    std::string path;

private:
    std::shared_ptr<Document> document;
    std::shared_ptr<Serializer> serializer;

};

#endif // SAVECOMMAND_H
