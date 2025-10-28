#include <cmath>
#include "calculatedDataAtwood.h"
#include "constants.h"
#include "calc.h"

void calculatedDataAtwood::calcAcceleration(double h1, double h2)
{
    acceleration = pow(h2, 2)/(2*h1*pow(averTime, 2));
}

/*void calculatedDataAtwood::calcAcceleration(double M, double m, double J, double j)
{
    acceleration = (physics::g*m)/(2*M+m+(J/pow(j, 2)));
}*/

void calculatedDataAtwood::calcAverageTime(std::vector<double> time)
{
    averTime = 0;
    size_t quantityTime = time.size();
    for(size_t i = 0; i < quantityTime; ++i)
    {
        averTime += time[i];
    }
    averTime /= quantityTime;
}

void calculatedDataAtwood::calcGravity(double mass, double addMass)
{
    
}

void calculatedDataAtwood::calcGravityWithoutIn(double mass, double addMass)
{
    gravity = acceleration*(2*mass+addMass)/addMass;
}

/*void calculatedDataAtwood::calcVelocity(double h, double t)
{
    velocity = h/t;
}

/*calculatedDataAtwood calculatedDataAtwood::iCVS(std::vector<std::string> &tokens)
{
    calculatedDataAtwood exp;

    for(size_t i = 0; i < tokens.size(); ++i)
    {
        exp.velocity = std::stod(tokens[i]);
        exp.acceleration = std::stod(tokens[i]);
    }

    return exp;
}*/

std::pair<int, std::vector<std::string>> calculatedDataAtwood::oCSV(calculatedDataAtwood &exp)
{
    std::pair<int, std::vector<std::string>> tokens;

    tokens.first = 3;
    tokens.second.push_back("Average Time,Acceleration,Gravity\n");
    tokens.second.push_back(std::to_string(exp.averTime));
    tokens.second.push_back(std::to_string(exp.acceleration));
    tokens.second.push_back(std::to_string(exp.gravity));

    return tokens;
}
