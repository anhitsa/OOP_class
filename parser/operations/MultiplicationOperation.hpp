#ifndef MULTIPLICATION_OPERATION_HPP
#define MULTIPLICATION_OPERATION_HPP

#include "Operation.hpp"

class MultiplicationOperation : public Operation 
{
    public:
        double calculate(const std::vector<double>& operands) const override 
        {
            return std::accumulate(operands.begin(), operands.end(), 1.0, std::multiplies<double>());
        }
        ~MultiplicationOperation() override {}

};

#endif // MULTIPLICATION_OPERATION_HPP
