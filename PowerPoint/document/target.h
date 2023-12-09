#ifndef TARGET_H
#define TARGET_H

#include <unordered_map>

class Target
{
public:
    virtual ~Target()=default;
    virtual void changeParameters(std::unordered_map<std::string, std::string> options) = 0;
    virtual void undoParametersChange() = 0;
};

#endif // TARGET_H
