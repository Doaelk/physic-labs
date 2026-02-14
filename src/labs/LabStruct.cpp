#include "labs/LabStruct.h"
#include "labs/ExperimentStruct.h"

//ExperimentStruct* LabStruct::operator[] (const int i) 
//{ return experiments[i].get(); }

int LabStruct::getQuantityExperiments() 
{ return experiments.size(); }

void LabStruct::addExperiment(std::unique_ptr<ExperimentStruct> e)
{ experiments.push_back(std::move(e)); }

void LabStruct::addCalcError(std::unique_ptr<ExperimentStruct> e)
{ errors.push_back(std::move(e)); }



