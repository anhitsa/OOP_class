#ifndef DISPLAYCOMMAND_H
#define DISPLAYCOMMAND_H

#include "command.h"
#include "../../PresentationElements/document.h"
#include "../../Renderer/renderer.h"

#include <memory>

class DisplayCommand: public Command
{
public:
    DisplayCommand(std::map<std::string, std::string> options, std::shared_ptr<Document>, std::shared_ptr<Renderer>);
    void execute() override;

private:
    void displaySlide();
    void displayItem();

private:
    std::shared_ptr<Document> document;
    std::shared_ptr<Renderer> renderer;

};

#endif // DISPLAYCOMMAND_H
