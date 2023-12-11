#include "controller/controller.h"

int main(int argc, char *argv[])
{
    //TK: Instead of controller here should be application
    Controller controller;
    controller.runPowerPointLoop(argc, argv); //TK: runPowerPointLoop simply could be called run()
    return 0; //TK: Return value should be whatever run() returned
}
