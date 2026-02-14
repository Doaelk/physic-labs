#include "LabFactory.h"
#include "fstream/csv/Fcsv.h"
#include "labs/LabStruct.h"
#include "tokens/LabToken.h"
#include <memory>

int main()
{
    pl::Fcsv reader;
    std::shared_ptr<pl::LabToken> token = reader.read("raw-data.csv");
    std::shared_ptr<LabStruct> lab = LabFactory::create(LabType::LAB2, token);
    lab->calculateLab();
}
