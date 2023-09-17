#ifndef OUTPUT_HANDLER_HPP
#define OUTPUT_HANDLER_HPP

#include <iostream>
#include <string>

class OutputHandler 
{
    public:
        static void print_message(const std::string& message) 
        {
            std::cout << message << std::endl;
        }

        static void print_error(const std::string& errorMessage) 
        {
            std::cerr << "Error: " << errorMessage << std::endl;
        }

        static void print_result(const double& result)
        {
            std::cout << "Result: " << result << std::endl;
        }

        static void print_command(const Command& command)
        {
            std::cout << command.operation_type << " ";
            for(auto& operand: command.operands)
            {
                std::cout << operand << " ";
            }
        }
};

#endif // OUTPUT_HANDLER_HPP
