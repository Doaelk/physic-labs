#pragma once

#include <vector>
#include <string>

struct CalculatedDataOberbeck
{
    double averageTime;
    double acceleration;
    double angleAcceleration;
    double forceMoment;
    double inertiaMoment;
    double inertiaG;
    double frictionForce;

    void calcAverageTime(std::vector<double> &time);
    void calcAcceleration(double h); 
    void calcAngleAcceleration(double r);
    void calcForceMoment(double m, double r);
    void calcInertiaMoment();
    void calcFrictionForce();
    void calcInertiaG(double force, double angle);

    static std::pair<int, std::vector<std::string>> oCSV(CalculatedDataOberbeck &exp);
};
