#include "labs/lab2(1)/Lab2Calc.h"

std::shared_ptr<pl::ExperimentToken> Lab2Calc::getToken() const 
{
    pl::ExperimentToken out;

    out.setExperimentData("Re", std::to_string(Re));
    out.setExperimentData("Ri", std::to_string(Ri));
    out.setExperimentData("Pe", std::to_string(Pe));
    out.setExperimentData("Pi", std::to_string(Pi));
    out.setExperimentData("ShCr", std::to_string(ShCr));
    out.setExperimentData("P0", std::to_string(P0));
    out.setExperimentData("K1", std::to_string(K1));
    out.setExperimentData("K2", std::to_string(K2));
    out.setExperimentData("Sum", std::to_string(Sum));
    out.setExperimentData("Eff", std::to_string(Eff));

    return std::make_shared<pl::ExperimentToken>(out);
}
