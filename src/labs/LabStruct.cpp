#include "labs/LabStruct.h"
#include "labs/ExperimentStruct.h"
#include <memory>

//ExperimentStruct* LabStruct::operator[] (const int i) 
//{ return experiments[i].get(); }

int LabStruct::getQuantityExperiments() 
{ return experiments.size(); }

void LabStruct::addExperiment(std::shared_ptr<ExperimentStruct> e)
{ experiments.push_back(std::move(e)); }

void LabStruct::addError(std::shared_ptr<ExperimentStruct> e)
{ errors.push_back(std::move(e)); }

void LabStruct::calculateLab() 
{
    for(std::shared_ptr<ExperimentStruct> exp : experiments)
    {
        exp->calcExp();   
    }
}


