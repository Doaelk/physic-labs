#pragma once

#include "labs/LabStruct.h"
#include "tokens/LabToken.h"
#include <memory>

enum class LabType 
{
    LAB1,   
    LAB2,
    LAB3,
    LAB4,
    LAB5
};

class LabFactory
{
public:
    static std::shared_ptr<LabStruct> create(const LabType, std::shared_ptr<pl::LabToken>) noexcept(false);
};
