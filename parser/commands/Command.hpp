#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <vector>

class Command 
{
    public:
        Command() : operation_type(""), operands({}), save_in_history(false) {}
        Command(const std::string& operation_type, bool save_in_history=false) : 
        operation_type(operation_type), operands({}), save_in_history(save_in_history) {}
        Command(const std::string& operation_type, const std::vector<double>& operands, bool save_in_history=false)
        : operation_type(operation_type), operands(operands), save_in_history(save_in_history) {}
        bool operator==(const Command& other) const
        {
            return operation_type == other.operation_type && operands == other.operands;
        }

    public:
        std::string operation_type;     
        std::vector<double> operands;
        bool save_in_history;
};


#endif // COMMAND_HPP
