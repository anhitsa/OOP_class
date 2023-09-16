#ifndef POW_OPERATION_HPP
#define POW_OPERATION_HPP

#include "Operation.hpp"

class PowOperation : public Operation 
{
    public:
        double execute(const std::vector<double>& operands) const override 
        {
            if (operands.size() != 2) throw std::invalid_argument("There should be two arguments for 'pow'.");
            return std::pow(operands[0], operands[1]);
        }
        ~PowOperation() override {}

};

#endif // POW_OPERATION_HPP
