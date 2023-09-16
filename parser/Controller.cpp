#include <iostream>
#include <sstream>

#include "Controller.hpp"

void Controller::run() 
{
    std::string input;
    std::cout << "Enter a command: ";

    while (std::getline(std::cin, input) && input != "quit") 
    {
        std::istringstream iss(input);
        try 
        {
            Command command = CommandParser::parseCommand(iss);
            double result = commandExecutor.executeCommand(command, operationFactory);
            std::cout << "Result: " << result << std::endl;
        } catch (const std::exception& e) 
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::cout << "Enter a command: ";
    }
    std::cout << "quitting ..." << std::endl;
}
