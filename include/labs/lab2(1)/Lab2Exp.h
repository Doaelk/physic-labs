#pragma once

#include "labs/ExperimentStruct.h"
#include "tokens/ExperimentToken.h"
#include <memory>

class Lab2Exp : public ExperimentStruct
{
public:
    float U0, U, I;
    float Re = 0, Ri = 0, Pe = 0, Pi = 0, ShCr = 0, P0 = 0, K1 = 0, K2 = 0, Sum = 0, Eff = 0;

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

    void calcExp() override;

    explicit Lab2Exp(std::shared_ptr<pl::ExperimentToken>);    
    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
