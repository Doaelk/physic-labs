#pragma once

#include "tokens/ExperimentToken.h"

class ExperimentStruct 
{
public:
    ExperimentStruct() = default;
    ExperimentStruct(pl::ExperimentToken&);

    ExperimentStruct(ExperimentStruct&&) = default;
    ExperimentStruct& operator=(ExperimentStruct&&) = default;

    ExperimentStruct(const ExperimentStruct&) = delete;
    ExperimentStruct& operator=(const ExperimentStruct&) = delete;

    virtual ~ExperimentStruct() = default;
};
