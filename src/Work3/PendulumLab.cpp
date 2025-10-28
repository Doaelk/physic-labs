#include "PendulumLab.h"

PendulumLab PendulumLab::iCSV(std::vector<std::string> &tokens)
{
    PendulumLab exp;

    exp.shkaloebonen = std::stod(tokens[0]);
    exp.length = std::stod(tokens[1]);
    exp.mathTime = std::stod(tokens[2]);

    for(size_t i = 3; i < tokens.size(); ++i)
        exp.time.push_back(std::stod(tokens[i]));

    return exp;
}

std::pair<int, std::vector<std::string>> PendulumLab::oCSV(PendulumLab &exp)
{
    std::pair<int, std::vector<std::string>> tokens;

    tokens.first = 3+exp.time.size();
    tokens.second.push_back("shkaloebonen,length,mathTime,PhysTime\n");
    tokens.second.push_back(std::to_string(exp.shkaloebonen));
    tokens.second.push_back(std::to_string(exp.length));
    tokens.second.push_back(std::to_string(exp.mathTime));
    
    for(size_t i = 0; i < exp.time.size(); ++i)
    {
        tokens.second.push_back(std::to_string(exp.time[i]));
    }

    return tokens;
}
