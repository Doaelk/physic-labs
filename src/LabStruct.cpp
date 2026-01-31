#include "LabStruct.h"
#include "labs/IExperiment.h"

IExperiment* LabStruct::operator[] (const int index) 
{ return experiments[index].get(); }

int LabStruct::getQuantityExperiments() 
{ return experiments.size(); }

void LabStruct::addExperiment(std::unique_ptr<IExperiment> e)
{ experiments.push_back(std::move(e)); }


/*DataStruct(std::string fileName)
    {
        std::ifstream file(fileName);

        if(!file.is_open())
        {
            std::cout << "File not opened fileName: " << fileName << std::endl;
            return;
        }

        std::string line;

        while (std::getline(file, line))
        {
            if(line.empty() || line[0] == '#') continue;

            std::istringstream ss(line);
            std::string cell;
            std::vector<std::string> tokens;

            while(std::getline(ss, cell, ','))
            {
                tokens.push_back(cell);
            }
            ++experimentsQuantity;
            experiments.push_back(ILab::iCSV(tokens));
        }

        file.close();
    }*/

