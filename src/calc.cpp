#include <cmath>
#include "calc.h"

double calcData::average(std::vector<double> data)
{
    double sum = 0;

    for(size_t i = 0; i < data.size(); ++i)
    {
        sum += data[i];
    }

    return sum/data.size();
}

double calcData::roundTo(double base, int n)
{
    return round(base*pow(10,n))/pow(10,n);
}   
