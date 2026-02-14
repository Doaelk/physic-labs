#include "fstream/csv/Fcsv.h"
#include "tokens/ExperimentToken.h"
#include "tokens/LabToken.h"

#include <filesystem>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <sstream>

std::shared_ptr<pl::LabToken> pl::Fcsv::read(const std::string& fileName) noexcept(false)
{
    std::ifstream file(fileName);   

    if(!file.is_open())
        throw std::runtime_error("Cannot open file: " + fileName);


    pl::LabToken out;
    std::string line;

    std::vector<std::string> keys;

    while (std::getline(file, line)) {
        if(line.empty() || line[0] == '#') continue;

        std::istringstream ss(line);
        std::string cell;

        while(std::getline(ss, cell, ','))
            keys.push_back(cell);
        break;
    }

    while(std::getline(file, line))
    {
        if(line.empty() || line[0] == '#') continue;

        pl::ExperimentToken expToken;
        std::istringstream ss(line);
        std::string cell;

        int i = 0;
        while(std::getline(ss, cell, ','))
        {
            expToken.setExperimentData(keys[i], cell);
            ++i;
        }
        out.addRow(expToken);
    }

    return std::make_shared<LabToken>(out);
}

void pl::Fcsv::write(const std::shared_ptr<pl::LabToken> labToken, const std::filesystem::path& filePath) noexcept(false)
{
    std::filesystem::create_directories(filePath.parent_path());
    
    std::ofstream file(filePath);

    if(!file.is_open())
        throw std::runtime_error("Cannot open file: " + filePath.string());

    for(const auto& line : *(*labToken)[0])
        file << line.first << ",";
    file << "\n";

    for(int i = 0; i < labToken->size(); ++i) 
    {
        for(const auto& line : *(*labToken)[i])
            file << line.second << ",";
        file << "\n";
    }
}
