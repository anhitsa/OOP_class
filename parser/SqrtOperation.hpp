#ifndef SQRT_OPERATION_HPP
#define SQRT_OPERATION_HPP

#include "Operation.hpp"

class SqrtOperation : public Operation 
{
    public:
        double execute(const std::vector<double>& operands) const override 
        {
            if (operands.size() != 1) throw std::invalid_argument("There should be one argument for 'sqrt'.");
            if (operands[0] < 0.0) throw std::invalid_argument("No sqrt for negative number.");
            return std::sqrt(operands[0]);
        }
        ~SqrtOperation() override {}

};

#endif // SQRT_OPERATION_HPP
