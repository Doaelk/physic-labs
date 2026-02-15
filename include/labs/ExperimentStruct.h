#pragma once

#include "tokens/ExperimentToken.h"
#include <memory>

class ExperimentStruct 
{
public:
    ExperimentStruct() = default;
    ExperimentStruct(pl::ExperimentToken&);

    ExperimentStruct(ExperimentStruct&&) = default;
    ExperimentStruct& operator=(ExperimentStruct&&) = default;

    ExperimentStruct(const ExperimentStruct&) = delete;
    ExperimentStruct& operator=(const ExperimentStruct&) = delete;

    ~ExperimentStruct() = default;

    virtual std::shared_ptr<pl::ExperimentToken> getToken() const = 0;
};
