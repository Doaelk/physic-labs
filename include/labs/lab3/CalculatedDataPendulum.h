#pragma once 

#include <vector>
#include <string>

struct CalculatedDataPendulum
{
    double averTime;
    double period;
    double gravity;
    double k;
    double gk;

    void calcAverageTime(std::vector<double> &time);
    void calcPeriod(double shkaloebonen, double time);
    void calcPeriod(double shkaloebonen);
    void calcGravity(double length);
    void calcK(double T2, double L1, double L2);
    void calcGravityWithK();

    static std::pair<int, std::vector<std::string>> oCSV(CalculatedDataPendulum &exp);
};
