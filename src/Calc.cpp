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

double Calc::randomMiss(const std::vector<double> &data)
{
    int count = data.size();
    double average = Calc::average(data);

    double sum = 0;
    for(double t : data)
    {
        sum += pow(t-average, 2);
    }

    return sqrt(sum / (count*(count-1)));
}

double Calc::dy(const std::vector<double>& exp, const std::vector<double>& theor)
{
    int n = 0;
    if(exp.size() > theor.size())
        n = theor.size();
    else
        n = exp.size();

    std::vector<double> diff;

    for(int i = 0; i < n; ++i)
        diff.push_back(exp[i]-theor[i]);
    
    return Calc::multiplySum({ diff, diff })/(n-2);
}

double Calc::dy(const std::vector<double>& exp, const double theor)
{
    std::vector<double> t(exp.size());
    for(int i = 0; i < exp.size(); ++i)
        t.push_back(theor);

    return Calc::dy(exp, t);
}

double Calc::dy(const double exp, const std::vector<double>& theor)
{
    std::vector<double> t(theor.size());
    for(int i = 0; i < theor.size(); ++i)
        t.push_back(exp);

    return Calc::dy(t, theor);
}

double Calc::dy(const double exp, const double theor)
{
    return Calc::dy(std::vector({exp}), std::vector({theor}));
}

double Calc::deltaCoeffA(const std::vector<double>& x, const double dy)
{
    int n = x.size();

    return n*dy/( n*Calc::multiplySum({ x, x })-pow(Calc::multiplySum({ x }), 2) );
}

double Calc::deltaCoeffB(const std::vector<double>& x, const double dy)
{
    int n = x.size();

    return dy*Calc::multiplySum({ x })/( n*Calc::multiplySum({ x, x })-pow(Calc::multiplySum({ x }), 2) );
}
