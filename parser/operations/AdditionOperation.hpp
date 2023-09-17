#ifndef ADDITION_OPERATION_HPP
#define ADDITION_OPERATION_HPP

#include "Operation.hpp"

class AdditionOperation : public Operation 
{
    public:
        double calculate(const std::vector<double>& operands) const override 
        {
            return std::accumulate(operands.begin(), operands.end(), 0.0);
        }
        ~AdditionOperation() override {}
};

#endif // ADDITION_OPERATION_HPP
