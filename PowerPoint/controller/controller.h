#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../parser/commandparser.h"

class Controller
{
public:
    Controller() {}
    int runPowerPointLoop(int argc, char* argv[]);

private:
    CommandParser commandParser;
};

#endif // CONTROLLER_H
