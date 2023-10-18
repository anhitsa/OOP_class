#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <vector>

class Validator
{
public:
    Validator()=default;
    void verifyCommandName(std::string command_name);
};

#endif // VALIDATOR_H
