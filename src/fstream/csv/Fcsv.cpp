
#include "fstream/csv/Fcsv.h"
#include "tokens/ExperimentToken.h"
#include "tokens/LabToken.h"

#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>

pl::LabToken pl::Fcsv::read(const std::string& fileName) noexcept(false)
{
    std::ifstream file(fileName);   

    if(!file.is_open())
        throw std::runtime_error("Cannot open file: " + fileName);


    pl::LabToken out;
    std::string keyLine;
    std::string line;

    do{
        
        if(std::getline(file, keyLine)) {
            if(line.empty() || line[0 == '#']) continue;
            else break;
        }
        else {
            throw std::runtime_error("Cannot get key line");
        }
    } while (true);

    std::vector<std::string> keys;
    std::istringstream ss(keyLine);
    std::string cell;

    while(std::getline(ss, cell, ','))
        keys.push_back(cell);

    while(std::getline(file, line))
    {
        if(line.empty() || line[0] == '#') continue;

        pl::ExperimentToken expToken;

        int i = 0;
        while(std::getline(ss, cell, ','))
        {
            expToken.setExpirementData(keys[i], cell);
            ++i;
        }
        out.addRow(expToken);
    }

    return out;
}

void pl::Fcsv::write(const pl::LabToken& labToken, const std::filesystem::path& filePath) noexcept(false)
{
    std::filesystem::create_directories(filePath.parent_path());
    
    std::ofstream file(filePath);

    if(!file.is_open())
        throw std::runtime_error("Cannot open file: " + filePath.string());

    for(const auto line : *labToken[0])
        file << line.second << ",";
    file << "\n";

    for(int i = 0; i < labToken.size(); ++i) 
    {
        for(const auto line : *labToken[i])
            file << line.second << ",";
        file << "\n";
    }
}
