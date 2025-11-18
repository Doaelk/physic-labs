#pragma once

#include <vector>

class calcData
{
public:
    static double average(const std::vector<double> &data);
    static double roundTo(const double base, const int n);
    static double coeffA(const std::vector<double> &x, const std::vector<double> &y);
    static double coeffB(const std::vector<double> &x, const std::vector<double> &y);
    static double multiplySum(const std::vector<std::vector<double>> &&list);
};
