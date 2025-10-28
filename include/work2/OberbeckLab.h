#pragma once

#include <vector>
#include <string>

struct OberbeckLab
{
    double radius;
    double height;
    double rMass;
    double addMass;
    std::vector<double> time;

    static OberbeckLab iCSV(std::vector<std::string> &tokens);
    static std::pair<int, std::vector<std::string>> oCSV(OberbeckLab &exp);
};
