#include "labs/lab2(1)/Lab2.h"
#include "Calc.h"
#include "labs/lab2(1)/Lab2Calc.h"
#include "labs/lab2(1)/Lab2Error.h"
#include "labs/lab2(1)/Lab2Exp.h"
#include "tokens/ExperimentToken.h"
#include "tokens/LabToken.h"
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
    calcLab->Ri = Calc::coeffA(I, U);
    calcLab->ShCr = expLab->U0/calcLab->Ri;
    calcLab->P0 = expLab->U0*calcLab->ShCr;
    calcLab->Pi = calcLab->Ia*calcLab->Ia*calcLab->Ri;
    calcLab->Eff = (calcLab->P0-calcLab->Pi)/calcLab->P0;
}

void Lab2::calculateLab()
{
    calculateData();
}

