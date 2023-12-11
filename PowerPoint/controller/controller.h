#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../parser/commandparser.h"

class Controller
{
public:
    Controller() {}
    int runPowerPointLoop(int argc, char* argv[]); //TK: argc & argv should be handled by the application, not controller

private:
    CommandParser commandParser;
};

#endif // CONTROLLER_H
