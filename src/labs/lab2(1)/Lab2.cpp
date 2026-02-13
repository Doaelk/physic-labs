#include "labs/lab2(1)/Lab2.h"
#include "labs/lab2(1)/Lab2Exp.h"
#include "tokens/ExperimentToken.h"
#include "tokens/LabToken.h"
#include <memory>

Lab2::Lab2(pl::LabToken& token)
{
    for(std::shared_ptr<pl::ExperimentToken> expToken : token)
    {
        addExperiment(std::make_unique<Lab2Exp>(expToken));
    }
}
