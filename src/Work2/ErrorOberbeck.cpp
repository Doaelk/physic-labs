#include "ErrorOberbeck.h"
#include "constants.h"
#include "calc.h"
#include <cmath>

//#define TESTACC

void ErrorOberbeck::calcTime(std::vector<double> time)
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

void ErrorOberbeck::calcAcceleration(double t, double h)
{
    deltaAcceleration = sqrt(pow((2*systemHeightError)/pow(t, 2), 2) + pow((4*h*deltaTime)/pow(t, 3), 2));
}

void ErrorOberbeck::calcAngleAcceleration(double a, double r)
{
    deltaAngleAcceleration = sqrt(pow(deltaAcceleration/r, 2) + pow((systemHeightError*a)/pow(r, 2), 2));
}

void ErrorOberbeck::calcForceMoment(double m, double r, double a)
{
    deltaForceMoment = sqrt(pow(systemHeightError*m*(physics::g-a), 2) + pow(systemMassError*r*(physics::g-a), 2) + pow(deltaAcceleration*r*m, 2));
}

void ErrorOberbeck::calcInertiaMoment(double k, double b)
{
    deltaInertiaMoment = sqrt(pow(deltaAngleAcceleration*k/pow(b, 2), 2) + pow(deltaForceMoment/b, 2));
}

void ErrorOberbeck::calcFrictionForce(double K, double b, double J)
{
    deltaFrictionForce = sqrt(pow(deltaForceMoment, 2)+pow(b*deltaInertiaG, 2)+pow(J*deltaAngleAcceleration, 2));
}

void ErrorOberbeck::calcInertiaG(double K1, double K2, double b1, double b2, double J)
{
    deltaInertiaG = J*sqrt(2*(pow(deltaForceMoment/(K2-K1), 2)+pow(deltaAngleAcceleration/(b2-b1), 2)));
}

std::pair<int, std::vector<std::string>> ErrorOberbeck::oCSV(ErrorOberbeck &exp)
{
    std::pair<int, std::vector<std::string>> tokens;

    tokens.first = 7;
    tokens.second.push_back("Delta Time,Delta Acceleration,Delta Angle Acceleration,Delta Force Moment,Delta Inertia Moment,Delta Graph Inertia,Friction Force\n");
    tokens.second.push_back(std::to_string(exp.deltaTime));
    tokens.second.push_back(std::to_string(exp.deltaAcceleration));
    tokens.second.push_back(std::to_string(exp.deltaAngleAcceleration));
    tokens.second.push_back(std::to_string(exp.deltaForceMoment));
    tokens.second.push_back(std::to_string(exp.deltaInertiaMoment));
    tokens.second.push_back(std::to_string(exp.deltaInertiaG));
    tokens.second.push_back(std::to_string(exp.deltaFrictionForce));

    return tokens;
}
