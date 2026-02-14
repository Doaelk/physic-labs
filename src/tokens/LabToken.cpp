#include <memory>
#include <stdexcept>
#include <vector>

#include "tokens/LabToken.h"
#include "tokens/ExperimentToken.h"

void pl::LabToken::addRow(pl::ExperimentToken& exp)
{ token.push_back(std::make_shared<pl::ExperimentToken>(exp)); }

std::shared_ptr<pl::ExperimentToken> pl::LabToken::operator[](const int i) const
{ 
    if(i < 0 || i >= token.size())
        throw std::out_of_range("LabToken index out of range");

    return token[i]; 
}

int pl::LabToken::size() const
{ return token.size(); }


std::vector<std::shared_ptr<pl::ExperimentToken>>::iterator pl::LabToken::begin()
{ return token.begin();}

std::vector<std::shared_ptr<pl::ExperimentToken>>::iterator pl::LabToken::end()
{ return token.end();}

