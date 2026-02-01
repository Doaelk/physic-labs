#pragma once

#include "tokens/ExperimentToken.h"

#include <vector>

//FIX ME 
//add return refferences
namespace pl
{

class LabToken
{
private:
    std::vector<pl::ExperimentToken> token;

public:
    void addRow(pl::ExperimentToken);
    pl::ExperimentToken operator[](const int i) const;
    int size() const;
};

};
