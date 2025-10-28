#pragma once

#include <vector>
#include <string>

struct ErrorOberbeck
{
    double systemTimeError = 0.001;
    double systemHeightError = 0.001;
    double systemMassError = 0.00001;

    double deltaTime;
    double deltaAcceleration;
    double deltaAngleAcceleration;
    double deltaForceMoment;
    double deltaInertiaMoment;
    double deltaInertiaG;
    double deltaFrictionForce;

    void calcTime(std::vector<double> time);
    void calcAcceleration(double t, double h); 
    void calcAngleAcceleration(double a, double r);
    void calcForceMoment(double m, double r, double a);
    void calcInertiaMoment(double k, double b);
    void calcFrictionForce(double K, double b, double J);
    void calcInertiaG(double K1, double K2, double b1, double b2, double J);

    static std::pair<int, std::vector<std::string>> oCSV(ErrorOberbeck &exp);
};
