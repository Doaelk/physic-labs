#include "labs/lab2(1)/Lab2.h"
#include "labs/ExperimentStruct.h"
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

std::shared_ptr<pl::LabToken> Lab2::getToken() const
{
    pl::LabToken out;

    for(std::shared_ptr<ExperimentStruct> exp : experiments)
    {
        out.addRow(*exp->getToken());       
    }

    return std::make_shared<pl::LabToken>(out);
}
