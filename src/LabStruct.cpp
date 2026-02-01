#include "LabStruct.h"
#include "labs/IExperiment.h"

IExperiment* LabStruct::operator[] (const int i) 
{ return experiments[i].get(); }

int LabStruct::getQuantityExperiments() 
{ return experiments.size(); }

void LabStruct::addExperiment(std::unique_ptr<IExperiment> e)
{ experiments.push_back(std::move(e)); }



