#include "ErrorPendulum.h"
#include "constants.h"
#include "calc.h"

#include <cmath>

void ErrorPendulum::calcTime(std::vector<double> time)
{
    size_t number = time.size();

    double averageTime = calcData::average(time);

    double sum = 0;
    for(size_t i = 0; i < number; ++i)
    {
        sum += pow(time[i]-averageTime, 2);
    }

    double randomTimeError = sqrt(sum/(number*(number-1)));

    deltaTime = sqrt(pow(randomTimeError, 2)+pow(systemTimeError, 2));
}

void ErrorPendulum::calcPeriod(double shkaloebonen) { calcPeriod(shkaloebonen, systemTimeError); }

void ErrorPendulum::calcPeriod(double shkaloebonen, double time)
{
    deltaPeriod = time/shkaloebonen;
}

void ErrorPendulum::calcGravity(double period, double length)
{
    deltaGravity = sqrt(pow((4*pow(physics::pi, 2)/pow(period, 2))*systemLengthError, 2) + pow((8*pow(physics::pi, 2)*length/pow(period, 3))*deltaPeriod, 2));
}

void ErrorPendulum::calcK(double T1, double T2, double L1, double L2, double deltaT)
{
    deltaK = sqrt(pow(2*T1*deltaPeriod/(pow(T2, 2)-pow(T1, 2)), 2)
                  +pow(2*T2*deltaT/(pow(T2, 2)-pow(T1, 2)), 2)
                  +2*pow((systemLengthError/(L2-L1)), 2));
}

void ErrorPendulum::calcGK(double k)
{
    deltaGK = 4*pow(physics::pi, 2)*deltaK/pow(k, 2); 
}

std::pair<int, std::vector<std::string>> ErrorPendulum::oCSV(ErrorPendulum &exp)
{
    std::pair<int, std::vector<std::string>> tokens;

    tokens.first = 5;
    tokens.second.push_back("delta Time,delta Period,delta Gravity,delta K,delta GK\n");
    tokens.second.push_back(std::to_string(exp.deltaTime));
    tokens.second.push_back(std::to_string(exp.deltaPeriod));
    tokens.second.push_back(std::to_string(exp.deltaGravity));
    tokens.second.push_back(std::to_string(exp.deltaK));
    tokens.second.push_back(std::to_string(exp.deltaGK));

    return tokens;

}
