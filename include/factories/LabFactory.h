#pragma once

#include "labs/LabStruct.h"
#include "tokens/lab/LabToken.h"
enum class LabType 
{
    
};

class LabFactory
{
public:
    static std::unique_ptr<LabStruct> create(const LabType, const pl::LabToken&) noexcept(false);
};
