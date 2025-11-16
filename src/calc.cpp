#include <cmath>

#include "calc.h"

double calcData::average(std::vector<double> &data)
{
    double sum = 0;

    for(size_t i = 0; i < data.size(); ++i) { sum += data[i];
    }

    return sum/data.size();
}

double calcData::roundTo(double base, int n)
{
    return round(base*pow(10,n))/pow(10,n);
}

double calcData::coeffA(std::vector<double> &x, std::vector<double> &y)
{
    size_t lenght = x.size();

    return (lenght*calcData::multiplySum({x, y})-calcData::multiplySum({x})*calcData::multiplySum({y}))/(lenght*calcData::multiplySum({x, x})-pow(calcData::multiplySum({x}), 2));
}

double calcData::coeffB(std::vector<double> &x, std::vector<double> &y)
{
    size_t lenght = x.size();

    return (calcData::multiplySum({x, x})*calcData::multiplySum({y})-calcData::multiplySum({x})*calcData::multiplySum({x, y}))/(lenght*calcData::multiplySum({x, x})-pow(calcData::multiplySum({x}), 2));
}

double calcData::multiplySum(std::vector<std::vector<double>> &&list)
{
    double sum = 0;

    size_t lenght = list.size();
    size_t count = list[0].size();

    double presum;
    for(size_t i = 0; i < lenght; ++i)
    {
        presum = list[0][i];
        for(size_t j = 1; j < count; ++j)
        {
            presum *= list[j][i];
        }
        sum += presum;
    }

    return sum;
}
