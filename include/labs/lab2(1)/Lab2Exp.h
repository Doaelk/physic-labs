#pragma once

#include "labs/ExperimentStruct.h"
#include "tokens/ExperimentToken.h"
#include <memory>

class Lab2Exp : public ExperimentStruct
{
public:
    float U0, U, I;

    explicit Lab2Exp(std::shared_ptr<pl::ExperimentToken>);    
    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
