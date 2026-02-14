#pragma once

#include "labs/LabStruct.h"
#include "tokens/LabToken.h"

class Lab2 : public LabStruct
{
public:
    explicit Lab2(std::shared_ptr<pl::LabToken>);

    void calculateError() override;
    
    std::shared_ptr<pl::LabToken> getToken() const override;   
};
