#include "OberbeckLab.h"

OberbeckLab OberbeckLab::iCSV(std::vector<std::string> &tokens)
{
    OberbeckLab exp;
    exp.radius = std::stod(tokens[0]);
    exp.height = std::stod(tokens[1]);
    exp.rMass = std::stod(tokens[2]);
    exp.addMass = std::stod(tokens[3]);

    for(size_t i = 4; i < tokens.size(); ++i)
        exp.time.push_back(std::stod(tokens[i]));

    return exp;
}

std::pair<int, std::vector<std::string>> OberbeckLab::oCSV(OberbeckLab &exp)
{
    std::pair<int, std::vector<std::string>> tokens;

    tokens.first = 4+exp.time.size();
    tokens.second.push_back("radius,height,rMass,addMass,time\n");
    tokens.second.push_back(std::to_string(exp.radius));
    tokens.second.push_back(std::to_string(exp.height));
    tokens.second.push_back(std::to_string(exp.rMass));
    tokens.second.push_back(std::to_string(exp.addMass));
    
    for(size_t i = 0; i < exp.time.size(); ++i)
    {
        tokens.second.push_back(std::to_string(exp.time[i]));
    }

    return tokens;
}
