
#include "labs/lab2(1)/Lab2Exp.h"
#include "formulas.h"
#include "tokens/ExperimentToken.h"
#include <cmath>
#include <memory>
#include <string>

Lab2Exp::Lab2Exp(std::shared_ptr<pl::ExperimentToken> token)
{
    U0 = std::stof(*(*token)["U0"]);
    U = std::stof(*(*token)["U"]);
    I = std::stof(*(*token)["I"]);
}

void Lab2Exp::calcResE()
{
    Re = pl::calcRes(U, I);
}

void Lab2Exp::calcResI()
{
    Ri = pl::calcRes(U0-U, I);
}

void Lab2Exp::calcPowE()
{
    Pe = pl::calcPow(I, Re);
}

void Lab2Exp::calcPowI()
{
    Pi = pl::calcPow(I, Ri);
}

void Lab2Exp::calcShCirCur()
{
    if(Ri == Re)
    {
        ShCr = MAXFLOAT;
        return;
    }

    ShCr = U0/(Ri-Re);
}

void Lab2Exp::calcPow0()
{
    if(ShCr == MAXFLOAT)
    {
        P0 = MAXFLOAT;
        return;
    }

    P0 = U0*ShCr/2;
}

void Lab2Exp::calcK1()
{
    K1 = Pe/P0;
}

void Lab2Exp::calcK2()
{
    K2 = Pi/P0;
}

void Lab2Exp::calcSum()
{
    Sum = 0;
}

void Lab2Exp::calcEff()
{
    Eff = Pe/P0;
}

void Lab2Exp::calcExp()
{
    calcResE();
    calcResI();
    calcPowE();
    calcPowI();
    calcShCirCur();
    calcPow0();
    calcK1();
    calcK2();
    calcSum();
    calcEff();
}

std::shared_ptr<pl::ExperimentToken> Lab2Exp::getToken() const 
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
