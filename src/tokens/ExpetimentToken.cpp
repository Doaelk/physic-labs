#include "tokens/ExperimentToken.h"

#include <string>

void pl::ExperimentToken::addData(std::string d)
{ token.push_back(d); }

const std::string pl::ExperimentToken::operator[](const int i) const
{ return token[i]; }

int pl::ExperimentToken::size() const
{ return token.size(); }
