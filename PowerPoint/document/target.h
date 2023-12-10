#ifndef TARGET_H
#define TARGET_H

#include <map>

class Target
{
public:
    virtual ~Target()=default;
    virtual void changeParameters(std::map<std::string, std::string> options) = 0;
    virtual void undoParametersChange() = 0;
    virtual int getId() const = 0;
};

#endif // TARGET_H
