#pragma once

#include <vector>
#include <string>

struct PendulumLab
{
    double shkaloebonen;
    double length;
    double mathTime;
    std::vector<double> time;

    static PendulumLab iCSV(std::vector<std::string> &tokens);
    static std::pair<int, std::vector<std::string>> oCSV(PendulumLab &exp);
};
