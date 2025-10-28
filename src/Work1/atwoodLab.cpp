#include "atwoodLab.h"
#include "calc.h"

atwoodLab atwoodLab::iCSV(std::vector<std::string> &tokens)
{
    atwoodLab exp;
    exp.radius = std::stod(tokens[0]);
    exp.heightAcc = std::stod(tokens[1]);
    exp.heightLine = std::stod(tokens[2]);
    exp.mass = std::stod(tokens[3]);
    exp.addMass = std::stod(tokens[4]);

    for(size_t i = 5; i < tokens.size(); ++i)
        exp.time.push_back(std::stod(tokens[i]));

    return exp;
}

std::pair<int, std::vector<std::string>> atwoodLab::oCSV(atwoodLab &exp)
{
    std::pair<int, std::vector<std::string>> tokens;

    tokens.first = 5+exp.time.size();
    tokens.second.push_back("radius,heightAcc,heightLine,mass,addMass,time\n");
    tokens.second.push_back(std::to_string(exp.radius));
    tokens.second.push_back(std::to_string(exp.heightAcc));
    tokens.second.push_back(std::to_string(exp.heightLine));
    tokens.second.push_back(std::to_string(exp.mass));
    tokens.second.push_back(std::to_string(exp.addMass));
    
    for(size_t i = 0; i < exp.time.size(); ++i)
    {
        tokens.second.push_back(std::to_string(exp.time[i]));
    }

    return tokens;
}
