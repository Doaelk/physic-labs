#pragma once

#include <vector>

class Calc
{
public:
    static double average(const std::vector<double> &data);
    static double roundTo(const double base, const int n);
    static double coeffA(const std::vector<double> &x, const std::vector<double> &y);
    static double coeffB(const std::vector<double> &x, const std::vector<double> &y);
    static double multiplySum(const std::vector<std::vector<double>> &&list);
    static double randomMiss(const std::vector<double>&);
    static double dy(const std::vector<double>& exp, const std::vector<double>& theor);
    static double dy(const std::vector<double>& exp, const double theor);
    static double deltaCoeffA(const std::vector<double>& x, const double dy);
    static double deltaCoeffB(const std::vector<double>& x, const double dy);

};
