#ifndef DIVISION_OPERATION_HPP
#define DIVISION_OPERATION_HPP

#include "Operation.hpp"

class DivisionOperation : public Operation 
{
    public:
        double execute(const std::vector<double>& operands) const override 
        {
            if (operands.empty()) throw std::invalid_argument("There should be at least one argument for division.");
            return std::accumulate(std::next(operands.begin()), operands.end(), operands[0], std::divides<double>());
        }
        ~DivisionOperation() override {}
};

#endif // DIVISION_OPERATION_HPP
