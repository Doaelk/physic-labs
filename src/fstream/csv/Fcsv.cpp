
#include "fstream/csv/Fcsv.h"
#include "tokens/ExperimentToken.h"
#include "tokens/LabToken.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

pl::LabToken pl::Fcsv::read(const std::string& fileName)
{
    std::ifstream file(fileName);   

    if(!file.is_open())
    {
        std::cout << "File not opened fileName: " << fileName << std::endl;
        return; //FIX ME
    }


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
/*DataStruct(std::string fileName)
    {
        while (std::getline(file, line))
        {
            ++experimentsQuantity;
            experiments.push_back(ILab::iCSV(tokens));
        }

        file.close();
    }*/

