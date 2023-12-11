#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <vector>

//TK: Since here you are not doing real semantic analysis, in this context validation could be part of the command clases itself
//TK: Here validator seperation is too artificial, parser directly need to use command for their validation
class Validator
{
public:
    Validator()=default;
    void verifyCommandName(std::string command_name);
};

#endif // VALIDATOR_H
