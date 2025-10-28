#pragma once
//#define TEST

#include <vector>
#include <sstream>
#include <fstream>
#include <filesystem>

template <typename ExperimentType>
class dataStruct
{
public:
    std::vector<ExperimentType> experiments;
    size_t experimentsQuantity=0;

    dataStruct(){};

    dataStruct(std::string fileName)   
    {
        std::ifstream file(fileName);

        if(!file.is_open())
        {
            std::cout << "File not opened fileName: " << fileName << std::endl;
        }

        std::string line;
        #ifdef TEST
        std::cout << "TEST1\n";
        #endif

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
            experiments.push_back(ExperimentType::iCSV(tokens));
        }
        
        file.close();
        #ifdef TEST
        std::cout << "TEST2\n";
        #endif
    }   

    void addExperiment(ExperimentType& e)
    {
        experiments.push_back(e);
    }

    bool setExperiment(size_t index, ExperimentType& e)
    {
        if(index > experiments.size())
            return false; 

        experiments[index] = e;
        return true;
    }

    bool addValueToExperiment(size_t index, double value)
    {
        if(index > experiments.size())
            return false;
        
        experiments[index].addValue(value);
        return true;
    }

    void readCSV(std::string fileName)
    {
        std::ifstream file(fileName);
        if(!file.is_open())
        {
            std::cout << "File not opened\n";
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

            experiments.push_back(ExperimentType::iCSV(tokens));
        }

        file.close();
    }

    void writeCSV(std::filesystem::path filePath)
    {
        std::filesystem::create_directories(filePath.parent_path());

        std::ofstream file(filePath);

        if(!file.is_open())
        {
            std::cout << "File not opened\n";
            return;
        }

        for (size_t line = 0; line < experiments.size(); ++line)
        {
            auto [quantityCol, tokens] = ExperimentType::oCSV(experiments[line]);

            file << tokens[0];

            for (size_t i = 1; i < tokens.size(); i += quantityCol)
            {
                for(size_t j = 0; j < quantityCol; ++j)
                {
                    file << tokens[i+j] << ",";
                }
                file << "\n";
            }

        }

        file.close();
    }
};
