#include "labs/LabStruct.h"
#include "labs/ExperimentStruct.h"
#include "tokens/ExperimentToken.h"
#include <memory>

//ExperimentStruct* LabStruct::operator[] (const int i) 
//{ return experiments[i].get(); }

int LabStruct::getQuantityExperiments() 
{ return experiments.size(); }

void LabStruct::addExperiment(std::shared_ptr<ExperimentStruct> e)
{ experiments.push_back(e); }

void LabStruct::setCalc(std::shared_ptr<ExperimentStruct> e)
{ calculate = std::move(e); }

void LabStruct::setError(std::shared_ptr<ExperimentStruct> e)
{ errors = std::move(e); }

std::shared_ptr<pl::LabToken> LabStruct::getToken() const
{
    pl::LabToken out;

    pl::ExperimentToken token; 

    token.addExperimentData(calculate->getToken());
    token.addExperimentData(errors->getToken());
    out.addRow(token);

    //for(std::shared_ptr<ExperimentStruct> exp : experiments)
    //{
    //    out.addRow(*exp->getToken());       
    //}

    return std::make_shared<pl::LabToken>(out);
}
