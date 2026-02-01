#include "tokens/LabToken.h"
#include "tokens/ExperimentToken.h"

#include <vector>

void pl::LabToken::addRow(pl::ExperimentToken row)
{ token.push_back(row); }

pl::ExperimentToken pl::LabToken::operator[](const int i) const
{ return token[i]; }

int pl::LabToken::size() const
{ return token.size(); }

