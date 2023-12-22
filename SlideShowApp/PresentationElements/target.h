#ifndef TARGET_H
#define TARGET_H

#include <string>

class Target
{
public:
    using ID = int;
    virtual ~Target()=default;
    virtual const ID& getId() const = 0;
    virtual std::string getInfo() const = 0;

};

#endif // TARGET_H
