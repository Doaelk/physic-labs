#include "CalculatedDataOberbeck.h"
#include "constants.h"
#include <cmath>

#include <iostream>

void CalculatedDataOberbeck::calcAverageTime(std::vector<double> time)
{
    averageTime = 0;

    size_t quantityTime = time.size();
    for(size_t i = 0; i < quantityTime; ++i)
    {
        averageTime += time[i];
    }
    averageTime /= quantityTime;
}


void CalculatedDataOberbeck::calcAcceleration(double h)
{
    acceleration = 2*h/pow(averageTime, 2);
}


void CalculatedDataOberbeck::calcAngleAcceleration(double r)
{
    angleAcceleration = acceleration/r;
}


void CalculatedDataOberbeck::calcForceMoment(double m, double r)
{
    forceMoment = r*m*(physics::g-acceleration);
}

void CalculatedDataOberbeck::calcInertiaMoment()
{
    inertiaMoment = forceMoment/angleAcceleration;
}

void CalculatedDataOberbeck::calcFrictionForce()
{
    frictionForce = forceMoment-(inertiaG*angleAcceleration);

    /*std::cout << std::endl;
    std::cout << forceMoment << " :f\n";
    std::cout << inertiaMoment << " :i\n";
    std::cout << angleAcceleration << " :a\n";
    std::cout << frictionForce << " :ff\n";
    std::cout << std::endl;*/
}

void CalculatedDataOberbeck::calcInertiaG(double force, double angle)
{
    inertiaG = (forceMoment-force)/(angleAcceleration-angle);
}




std::pair<int, std::vector<std::string>> CalculatedDataOberbeck::oCSV(CalculatedDataOberbeck &exp)
{
    std::pair<int, std::vector<std::string>> tokens;

    tokens.first = 7;
    tokens.second.push_back("Average Time,Acceleration,Angle Acceleration,Force Moment,Inertia Moment,Graph Inertia,Friction Force\n");
    tokens.second.push_back(std::to_string(exp.averageTime));
    tokens.second.push_back(std::to_string(exp.acceleration));
    tokens.second.push_back(std::to_string(exp.angleAcceleration));
    tokens.second.push_back(std::to_string(exp.forceMoment));
    tokens.second.push_back(std::to_string(exp.inertiaMoment));
    tokens.second.push_back(std::to_string(exp.inertiaG));
    tokens.second.push_back(std::to_string(exp.frictionForce));

    return tokens;
}
