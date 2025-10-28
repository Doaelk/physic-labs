#pragma once 

#include <vector>
#include <string>

struct ErrorPendulum
{
    double systemTimeError = 0.001;
    double systemLengthError = 0.001;

    double deltaTime;
    double deltaPeriod;
    double deltaGravity;
    double deltaK;
    double deltaGK;

    void calcTime(std::vector<double> time);
    void calcPeriod(double shkaloebonen);
    void calcPeriod(double shkaloebonen, double time);
    void calcGravity(double period, double length);
    void calcK(double T1, double T2, double L1, double L2, double deltaT);
    void calcGK(double k);

    static std::pair<int, std::vector<std::string>> oCSV(ErrorPendulum &exp);
};
