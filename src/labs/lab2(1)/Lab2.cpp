#include "labs/lab2(1)/Lab2.h"
#include "Calc.h"
#include "labs/LabStruct.h"
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
}

void Lab2::calculateError()
{

}

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
    expLab->Ri = Calc::coeffA(I, U);
}
