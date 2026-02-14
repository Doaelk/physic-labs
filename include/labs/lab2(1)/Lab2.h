#pragma once

#include "labs/LabStruct.h"
#include "tokens/LabToken.h"

class Lab2 : public LabStruct
{
public:
    explicit Lab2(pl::LabToken&);
    void calculateLab()  override;
    void calculateError()  override;
};
