#pragma once

#include "LabStruct.h"
#include "fstream/IFStream.h"
#include <string>

namespace pl
{

class Fcsv : pl::IFStream
{
    LabStruct read(std::string) const;   
    LabStruct write(std::string) const;   
};

}
