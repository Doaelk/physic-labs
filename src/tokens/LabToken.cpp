#include <memory>
#include <vector>

#include "tokens/LabToken.h"
#include "tokens/ExperimentToken.h"

void pl::LabToken::addRow(pl::ExperimentToken& exp)
{ token.push_back(std::make_shared<pl::ExperimentToken>(exp)); }

std::shared_ptr<pl::ExperimentToken> pl::LabToken::operator[](const int i) const
{ return token[i]; }

int pl::LabToken::size() const
{ return token.size(); }

