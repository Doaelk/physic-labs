#pragma once

#include "labs/ExperimentStruct.h"
#include "tokens/ExperimentToken.h"
#include <memory>

class Lab2Exp : public ExperimentStruct
{
public:
    float U0, U, I;
    float Re, Ri, Pe, Pi, ShCr, P0, K1, K2, Sum, Eff;

    void calcResE();
    void calcResI();
    void calcPowE();
    void calcPowI();
    void calcShCirCur();
    void calcPow0();
    void calcK1();
    void calcK2();
    void calcSum();
    void calcEff();

    explicit Lab2Exp(std::shared_ptr<pl::ExperimentToken>);    
};
