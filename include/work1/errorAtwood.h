#pragma once

#include "atwoodLab.h"
#include "calculatedDataAtwood.h"

#include <vector>

struct errorAtwood
{
    double systemTimeError = 0.001;
    double systemHeightError = 0.001;
    double systemMassError = 0.00001;

    double averageTime;
    double deltaTime;

    double averageAcceleration;
    double deltaAcceleration;

    double averageGravity;
    double deltaGravity;

    void calcTime(std::vector<double> time);

    void calcAcceleration(double time, double h1, double h2);

    void calcGravity(double acceleration, double mass, double addMass);

    static std::pair<int, std::vector<std::string>> oCSV(errorAtwood &exp);
};
