#include "CommandHistory.hpp"

std::vector<Command> CommandHistory::history;

void CommandHistory::save_in_history(const Command& command)
{
    history.push_back(command);
}

void CommandHistory::remove_from_history(const Command& command)
{
    history.erase(std::remove(history.begin(), history.end(), command), history.end());
}
