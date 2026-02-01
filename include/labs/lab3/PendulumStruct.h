#pragma once

#include <vector>
#include <string>

struct PendulumStruct
{
    double shkaloebonen;
    double length;
    double mathTime;
    std::vector<double> time;

    static PendulumStruct iCSV(std::vector<std::string> &tokens);
    static std::pair<int, std::vector<std::string>> oCSV(PendulumStruct &exp);
};
