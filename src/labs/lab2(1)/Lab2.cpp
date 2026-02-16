#include "labs/lab2(1)/Lab2.h"
#include "Calc.h"
#include "labs/lab2(1)/Lab2Calc.h"
#include "labs/lab2(1)/Lab2Error.h"
#include "labs/lab2(1)/Lab2Exp.h"
#include "tokens/ExperimentToken.h"
#include "tokens/LabToken.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <memory>

Lab2::Lab2(std::shared_ptr<pl::LabToken> token)
{
    for(std::shared_ptr<pl::ExperimentToken> expToken : *token)
    {
        addExperiment(std::make_shared<Lab2Exp>(expToken));
    }

    setCalc(std::make_shared<Lab2Calc>());
    setError(std::make_shared<Lab2Error>());
}

void Lab2::calculateError()
{
}

void Lab2::calculateData()
{ }

void Lab2::calculateLab()
{
    std::vector<double> I;
    std::vector<double> U;
    for(std::shared_ptr<ExperimentStruct> exp : experiments)
    {
        std::shared_ptr<Lab2Exp> expLab = std::static_pointer_cast<Lab2Exp>(exp);
        I.push_back(expLab->I);
        U.push_back(expLab->U);
    }

    std::shared_ptr<Lab2Exp> expLab = std::static_pointer_cast<Lab2Exp>(experiments[0]);
    std::shared_ptr<Lab2Calc> calcLab = std::static_pointer_cast<Lab2Calc>(calculate);

    calcLab->Ia = Calc::average(I);
    calcLab->Ua = Calc::average(U);
    calcLab->Ri = std::abs(Calc::coeffA(I, U));
    //calcLab->Re = expLab->U0 - calcLab->Ia * calcLab->Ri;
    calcLab->ShCr = expLab->U0/calcLab->Ri;
    calcLab->P0 = expLab->U0*calcLab->Ia;
    calcLab->Pi = calcLab->Ia*calcLab->Ia*calcLab->Ri;
    calcLab->Eff = (calcLab->P0-calcLab->Pi)/calcLab->P0;

    std::shared_ptr<Lab2Error> errorLab = std::static_pointer_cast<Lab2Error>(errors);

    errorLab->U = Calc::randomMiss(U);
    errorLab->I = Calc::randomMiss(I);
    errorLab->Ri = std::abs(Calc::deltaCoeffA(I, Calc::dy(calcLab->Ua, expLab->U0-calcLab->Ia*calcLab->Ri)));
    //errorLab->Re = sqrt(pow(calcLab->Ri*errorLab->I, 2)+
    //                    pow(calcLab->Ia*errorLab->Ri, 2));
    errorLab->ShCr = std::abs(expLab->U0/pow(calcLab->Ri, 2)*errorLab->Ri);
    errorLab->P0 = std::abs(expLab->U0*errorLab->I);
    errorLab->Pi = sqrt(pow(calcLab->Ia*calcLab->Ia*errorLab->Ri, 2)+
                        pow(2*pow(calcLab->Ia, 3)*calcLab->Ri*errorLab->I, 2));
    errorLab->Eff = sqrt(pow(errorLab->Pi/calcLab->P0, 2)+
                         pow(calcLab->Pi*calcLab->P0*calcLab->P0*errorLab->P0, 2));
}

