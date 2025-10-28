#include <cmath>

#include "atwoodLab.h"
#include "errorAtwood.h"
#include "calc.h"

#define TESTG

#ifdef TESTG
#include <iostream>
#include <format>
#endif

void errorAtwood::calcTime(std::vector<double> time)
{
    size_t number = time.size();

    averageTime = calcData::average(time);

    double sum = 0;
    for(size_t i = 0; i < number; ++i)
    {
        sum += pow(time[i]-averageTime, 2);
    }

    double randomTimeError = sqrt(sum/(number*(number-1)));

    deltaTime = sqrt(pow(randomTimeError, 2)+pow(systemTimeError, 2));
}

void errorAtwood::calcAcceleration(double time, double h1, double h2)
{
    #ifdef TESTACC
    std::cout << std::format("h2^2 - {}\nh1*t^3 - {}\n", pow(h2, 2), h1*pow(time, 3));
    std::cout << std::format("2*t^2*h1^2 - {}\n h1*t^2 - {}\n", 2*pow(time, 2)*pow(h1, 2), h1*pow(time, 2));
    std::cout << std::endl;
std::cout << std::format("1 - {}\n2 - {}\n3 - {}", pow(h2, 2)/(h1*pow(time, 3))*systemTimeError, pow(h2, 2)/(2*pow(time, 2)*pow(h1, 2))*systemHeightError, h2/(h1*pow(time, 2))*systemHeightError);
    #endif
    deltaAcceleration = sqrt(
        pow(pow(h2, 2)/(h1*pow(time, 3))*systemTimeError, 2) +
        pow(pow(h2, 2)/(2*pow(time, 2)*pow(h1, 2))*systemHeightError, 2) +
        pow(h2/(h1*pow(time, 2))*systemHeightError, 2));
}

void errorAtwood::calcGravity(double acceleration, double mass, double addMass)
{
#ifdef TESTG
    std::cout << std::format("2*M*m - {}\nm^2 - {}\n", 2*mass+addMass, pow(addMass, 2));
    std::cout << std::format("2*a - {}\n", acceleration*2);
    std::cout << std::endl;
//std::cout << std::format("1 - {}\n2 - {}\n3 - {}", pow(h2, 2)/(h1*pow(time, 3))*systemTimeError, pow(h2, 2)/(2*pow(time, 2)*pow(h1, 2))*systemHeightError, h2/(h1*pow(time, 2))*systemHeightError);
    #endif
    deltaGravity = sqrt(
        pow(((2*mass+addMass)/addMass) * deltaAcceleration, 2) +
        pow(((2*mass*addMass)/pow(addMass, 2)) * systemMassError, 2) + 
        pow(((2*acceleration)/addMass) * systemMassError, 2));
}

std::pair<int, std::vector<std::string>> errorAtwood::oCSV(errorAtwood &exp)
{
    std::pair<int, std::vector<std::string>> tokens;

    tokens.first = 3;
    tokens.second.push_back("Delta Time,Delta Acceleration,Delta Gravity\n");
    tokens.second.push_back(std::to_string(exp.deltaTime));

    tokens.second.push_back(std::to_string(exp.deltaAcceleration));

    tokens.second.push_back(std::to_string(exp.deltaGravity));

    return tokens;
}
