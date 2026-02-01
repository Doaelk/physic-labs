#pragma once

#include "labs/ExperimentStruct.h"

#include<vector>

struct PendulumExperiment : ExperimentStruct
{
    double shkaloebonen;
    double length;
    double mathTime;
    std::vector<double> time;
};
