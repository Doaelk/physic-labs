#pragma once

#include "tokens/ExperimentToken.h"

#include <memory>
#include <vector>

namespace pl
{

class LabToken
{
private:
    std::vector<std::shared_ptr<pl::ExperimentToken>> token;

public:
    void addRow(pl::ExperimentToken&);

    std::shared_ptr<pl::ExperimentToken> operator[](const int i) const;
    int size() const;

    std::vector<pl::ExperimentToken> getToken() const;

    std::vector<std::shared_ptr<pl::ExperimentToken>>::iterator begin();
    std::vector<std::shared_ptr<pl::ExperimentToken>>::iterator end();
};

};
