#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H

#include "command.h"
#include "../../PresentationElements/document.h"
#include "../../Renderer/renderer.h"

#include <memory>

class DrawCommand: public Command
{
public:
    DrawCommand(std::map<std::string, std::string> options, std::shared_ptr<Document>, std::shared_ptr<Renderer>);
    void execute() override;

private:
    std::shared_ptr<Target> determineTarget();

private:
    std::shared_ptr<Document> document;
    std::shared_ptr<Renderer> renderer;

};

#endif // DRAWCOMMAND_H
