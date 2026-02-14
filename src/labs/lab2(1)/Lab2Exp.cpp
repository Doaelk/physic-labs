
#include "labs/lab2(1)/Lab2Exp.h"
#include "formulas.h"
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

/*void Lab2Exp::calcSum()
{

}*/

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

