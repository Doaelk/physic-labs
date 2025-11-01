#include <cmath>
#include <cstdarg>

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

    return (lenght*calcData::sum(2, x, y)-calcData::sum(1, x)*calcData::sum(1, y))/(lenght*calcData::sum(2, x, x)-pow(calcData::sum(1, x), 2));
}

double calcData::coeffB(std::vector<double> &x, std::vector<double> &y)
{
    size_t lenght = x.size();

    return (calcData::sum(2, x, x)*calcData::sum(1, y)-calcData::sum(1, x)*calcData::sum(2, x, y))/(lenght*calcData::sum(2, x, x)-pow(calcData::sum(1, x), 2));
}
    
double calcData::sum(size_t count, ...)
{
    double sum = 0;
    va_list list;

    va_start(list, count);

    std::vector<std::vector<double>*> arg;
    for(size_t i = 0; i < count; ++i)
    {
        arg.push_back(va_arg(list, std::vector<double>*));
    }
    
    size_t lenght = arg[0]->size();
    double presum;
    
    for(size_t i = 0; i < lenght; ++i)
    {
        presum = (*arg[0])[i];
        for(size_t j = 1; j < count; ++j)
        {
            presum *= (*arg[j])[i];
        }
        sum += presum;
    }

    va_end(list);

    return sum;
}
