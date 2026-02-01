#include <cmath>

#include "Calc.h"

double Calc::average(const std::vector<double> &data)
{
    double sum = 0;

    for(size_t i = 0; i < data.size(); ++i) { sum += data[i];
    }

    return sum/data.size();
}

double Calc::roundTo(const double base, const int n)
{
    return round(base*pow(10,n))/pow(10,n);
}

double Calc::coeffA(const std::vector<double> &x, const std::vector<double> &y)
{
    size_t lenght = x.size();

    return (lenght*Calc::multiplySum({x, y})-Calc::multiplySum({x})*Calc::multiplySum({y}))/(lenght*Calc::multiplySum({x, x})-pow(Calc::multiplySum({x}), 2));
}

double Calc::coeffB(const std::vector<double> &x, const std::vector<double> &y)
{
    size_t lenght = x.size();

    return (Calc::multiplySum({x, x})*Calc::multiplySum({y})-Calc::multiplySum({x})*Calc::multiplySum({x, y}))/(lenght*Calc::multiplySum({x, x})-pow(Calc::multiplySum({x}), 2));
}

double Calc::multiplySum(const std::vector<std::vector<double>> &&list)
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
