#ifndef OPERATION_HPP
#define OPERATION_HPP

#include "OperationFactory.hpp"

class Operation 
{
    public:
        virtual double execute(const std::vector<double>& operands) const = 0;
        virtual ~Operation() {}
};


#endif // OPERATION_HPP