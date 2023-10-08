#include "userinputhandler.h"

UserInputHandler::Input UserInputHandler::getInput()
{
    std::getline(std::cin, input);
    return input;
}
