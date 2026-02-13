#pragma once

#include "labs/ExperimentStruct.h"
#include "tokens/ExperimentToken.h"
#include <memory>

class Lab2Exp : public ExperimentStruct
{
private:
    float U;
    float I;

public:
    explicit Lab2Exp(std::shared_ptr<pl::ExperimentToken>);    
};
