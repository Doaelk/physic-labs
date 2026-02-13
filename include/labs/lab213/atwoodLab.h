#pragma once

#include <vector>
#include <string>

struct atwoodLab
{
    double radius;
    double heightAcc;
    double heightLine;
    double mass;
    double addMass;
    std::vector<double> time;

    static atwoodLab iCSV(std::vector<std::string> &tokens);
    static std::pair<int, std::vector<std::string>> oCSV(atwoodLab &exp);
};
