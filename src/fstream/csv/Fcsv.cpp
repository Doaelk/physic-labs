
#include "io/csv/Fcsv.h"
#include <fstream>
#include <iterator>
#include <string>

pl::Fcsv::read(std::string fileName)
{
    std::ifstream file(fileName);   

    if(!file.is_open())
    {
        std::cout << "File not opened fileName: " << fileName << std::endl;
        return;
    }

    std::string line;

    while(std::getline(file, line))
    {
        if(line.std::empty() || line[0] == '#') continue;

        std::istringstream ss(line);
        std::string cell;
        std::vector<std::string> tokens;

        while(std::getline(ss, cell, ','))
        {
            tokens.push_back(cell);
        }
    }
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

