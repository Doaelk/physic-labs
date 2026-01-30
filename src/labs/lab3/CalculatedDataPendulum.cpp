#include "CalculatedDataPendulum.h"
#include "constants.h"
#include "calc.h"

#include <cmath>

void CalculatedDataPendulum::calcAverageTime(std::vector<double> &time)
{
    averTime = calcData::average(time);
}

void CalculatedDataPendulum::calcPeriod(double shkaloebonen, double time)
{
    period=time/shkaloebonen;
}

void CalculatedDataPendulum::calcPeriod(double shkaloebonen){ CalculatedDataPendulum::calcPeriod(shkaloebonen, averTime); }

void CalculatedDataPendulum::calcGravity(double length)
{
    gravity=4*pow(constants::pi, 2)*length/pow(period, 2);
}

void CalculatedDataPendulum::calcK(double T2, double L1, double L2)
{
    k = (period*period-T2*T2)/(L2-L1);
}

void CalculatedDataPendulum::calcGravityWithK()
{
    gk = 4*pow(constants::pi, 2)/k;
}

std::pair<int, std::vector<std::string>> CalculatedDataPendulum::oCSV(CalculatedDataPendulum &exp)
{
    std::pair<int, std::vector<std::string>> tokens;

    tokens.first = 5;
    tokens.second.push_back("average Time,period,gravity,k,gk\n");
    tokens.second.push_back(std::to_string(exp.averTime));
    tokens.second.push_back(std::to_string(exp.period));
    tokens.second.push_back(std::to_string(exp.gravity));
    tokens.second.push_back(std::to_string(exp.k));
    tokens.second.push_back(std::to_string(exp.gk));

    return tokens;

}
