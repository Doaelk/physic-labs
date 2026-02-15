#include "LabFactory.h"
#include "fstream/csv/Fcsv.h"
#include "labs/LabStruct.h"
#include "tokens/LabToken.h"
#include <memory>
#include <stdexcept>
#include <iostream>
#include <string>

int main()
{
    for(int i = 1; i <= 3; ++i)
    {
        pl::Fcsv reader;

        std::shared_ptr<pl::LabToken> token;
        try {
            token = reader.read("data/raw-data"+std::to_string(i)+".csv");
        } catch (std::runtime_error& e) {
            std::cout << e.what() << std::endl;
            return 1;
        }
        std::cout << "read successful\n";

        std::shared_ptr<LabStruct> lab = LabFactory::create(LabType::LAB2, token);
        std::cout << "create lab successful\n";

        lab->calculateLab();
        std::cout << "calculate lab successful\n";

        try {
            reader.write(lab->getToken(), "data/calc-data"+std::to_string(i)+".csv");
        } catch (std::runtime_error& e) {
            std::cout << e.what() << std::endl;
        }
    }
}
