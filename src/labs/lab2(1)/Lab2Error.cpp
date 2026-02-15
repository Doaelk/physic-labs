#pragma once

#include "labs/lab2(1)/Lab2Error.h"

std::shared_ptr<pl::ExperimentToken> Lab2Error::getToken() const 
{
    pl::ExperimentToken out;

    out.setExperimentData("Error U", std::to_string(U));
    out.setExperimentData("Error I", std::to_string(I));
    out.setExperimentData("Error Re", std::to_string(Re));
    out.setExperimentData("Error Ri", std::to_string(Ri));
    out.setExperimentData("Error Pe", std::to_string(Pe));
    out.setExperimentData("Error Pi", std::to_string(Pi));
    out.setExperimentData("Error ShCr", std::to_string(ShCr));
    out.setExperimentData("Error P0", std::to_string(P0));
    out.setExperimentData("Error K1", std::to_string(K1));
    out.setExperimentData("Error K2", std::to_string(K2));
    out.setExperimentData("Error Sum", std::to_string(Sum));
    out.setExperimentData("Error Eff", std::to_string(Eff));

    return std::make_shared<pl::ExperimentToken>(out);
}
