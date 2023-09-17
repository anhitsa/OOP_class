#ifndef OPERATION_HPP
#define OPERATION_HPP

#include "../factory/OperationFactory.hpp"

class Operation 
{
    public:
        virtual double calculate(const std::vector<double>& operands) const = 0;
        virtual ~Operation() {}
};


#endif // OPERATION_HPP