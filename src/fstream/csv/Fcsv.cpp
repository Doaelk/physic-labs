
#include "fstream/csv/Fcsv.h"
#include "labs/LabStruct.h"
#include "tokens/ExperimentToken.h"
#include "tokens/LabToken.h"

#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>

//FIXME
pl::LabToken pl::Fcsv::read(const std::string& fileName) noexcept(false)
{
    std::ifstream file(fileName);   

    if(!file.is_open())
        throw std::runtime_error("Cannot open file: " + fileName);


    pl::LabToken out;
    std::string line;

    while(std::getline(file, line))
    {
        if(line.empty() || line[0] == '#') continue;

        std::istringstream ss(line);
        std::string cell;
        pl::ExperimentToken tokens;

        while(std::getline(ss, cell, ','))
        {
            tokens.addData(cell);
        }
        out.addRow(tokens);
    }

    return out;
}

void pl::Fcsv::write(const LabStruct& lab, const std::filesystem::path& filePath) noexcept(false)
{
    std::filesystem::create_directories(filePath.parent_path());
    
    std::ofstream file(filePath);

    if(!file.is_open())
        throw std::runtime_error("Cannot open file: " + filePath.string());

    pl::LabToken labToken = lab.getToken();
    
    for(int i = 0; i < labToken.size(); ++i) 
    {
        for(int j = 0; j < labToken[i].size(); ++j)
            file << labToken[i][j] << ",";
        file << "\n";
    }
}
