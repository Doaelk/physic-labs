#pragma once

#include <vector>
#include <string>

struct calculatedDataAtwood
{
    double averTime;
    double acceleration;
    double gravity;

    void calcAcceleration(double h1, double h2);
    void calcAverageTime(std::vector<double> time);
    void calcGravity(double mass, double addMass);
    void calcGravityWithoutIn(double mass, double addMass);


    static std::pair<int, std::vector<std::string>> oCSV(calculatedDataAtwood &exp);
};
