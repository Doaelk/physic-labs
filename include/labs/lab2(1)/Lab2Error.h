#pragma once

#include "labs/ExperimentStruct.h"

class Lab2Error : public ExperimentStruct
{
public:
    float U = 0, I = 0, Re = 0, Ri = 0, Pe = 0, Pi = 0, ShCr = 0, P0 = 0, K1 = 0, K2 = 0, Sum = 0, Eff = 0;

    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
