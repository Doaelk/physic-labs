#pragma once

#include <string>
#include <vector>

//FIX ME 
//add return refferences
namespace pl 
{

class ExperimentToken
{
private:
    std::vector<std::string> token;

public:
    void addData(std::string);
    const std::string operator[](const int i) const;
    int size() const;

};

};
