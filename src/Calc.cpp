#include <cmath>

#include "Calc.h"

double CalcData::average(const std::vector<double> &data)
{
    double sum = 0;

    for(size_t i = 0; i < data.size(); ++i) { sum += data[i];
    }

    return sum/data.size();
}

double CalcData::roundTo(const double base, const int n)
{
    return round(base*pow(10,n))/pow(10,n);
}

double CalcData::coeffA(const std::vector<double> &x, const std::vector<double> &y)
{
    size_t lenght = x.size();

    return (lenght*CalcData::multiplySum({x, y})-CalcData::multiplySum({x})*CalcData::multiplySum({y}))/(lenght*CalcData::multiplySum({x, x})-pow(CalcData::multiplySum({x}), 2));
}

double CalcData::coeffB(const std::vector<double> &x, const std::vector<double> &y)
{
    size_t lenght = x.size();

    return (CalcData::multiplySum({x, x})*CalcData::multiplySum({y})-CalcData::multiplySum({x})*CalcData::multiplySum({x, y}))/(lenght*CalcData::multiplySum({x, x})-pow(CalcData::multiplySum({x}), 2));
}

double CalcData::multiplySum(const std::vector<std::vector<double>> &&list)
{
    double sum = 0;

    size_t lenght = list.size();
    size_t count = list[0].size();

    double presum;
    for(size_t i = 0; i < count; ++i)
    {
        presum = list[0][i];
        for(size_t j = 1; j < lenght; ++j)
        {
            presum *= list[j][i];
        }
        sum += presum;
    }

    return sum;
}
