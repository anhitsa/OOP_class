#ifndef ADDITION_OPERATION_HPP
#define ADDITION_OPERATION_HPP

#include "Operation.hpp"

#include <iostream>

class AdditionOperation : public Operation 
{
    public:
        double execute(const std::vector<double>& operands) const override 
        {
            return std::accumulate(operands.begin(), operands.end(), 0.0);
        }
        ~AdditionOperation() override {}
};

#endif // ADDITION_OPERATION_HPP
