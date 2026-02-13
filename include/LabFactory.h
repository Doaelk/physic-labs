#pragma once

#include "labs/LabStruct.h"
#include "tokens/LabToken.h"


class LabFactory
{
private:
    enum class LabType 
    {
        LAB1,   
        LAB2,
        LAB3,
        LAB4,
        LAB5
    };

public:
    static std::unique_ptr<LabStruct> create(const LabType, pl::LabToken&) noexcept(false);
};
