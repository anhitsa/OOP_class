#ifndef COMMAND_HISTORY_HPP
#define COMMAND_HISTORY_HPP

#include "Command.hpp"

#include <algorithm> // std::remove
#include <vector>

class CommandHistory
{
public:
    static std::vector<Command> history;
    static void save_in_history(const Command& command);
    static void remove_from_history(const Command& command);
};

#endif // COMMAND_HISTORY_HPP
