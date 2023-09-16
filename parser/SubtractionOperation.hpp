#ifndef SUBTRACTION_OPERATION_HPP
#define SUBTRACTION_OPERATION_HPP

#include "Operation.hpp"

class SubtractionOperation : public Operation 
{
    public:
        double execute(const std::vector<double>& operands) const override 
        {
            if (operands.empty()) throw std::invalid_argument("There should be at least one argument for subtraction.");
            return std::accumulate(std::next(operands.begin()), operands.end(), operands[0], std::minus<float>());
        }
        ~SubtractionOperation() override {}

};

#endif // SUBTRACTION_OPERATION_HPP
