#pragma once

#include "labs/LabStruct.h"


class PendulumLab : LabStruct
{
private: 
    void calcAverageTime();
    void calcPeriod();
    void calcGravity();
    void caclK();
    void calcGravityWithK();

public:
    void calculateLab() override;
    void calculateError() override;
};
