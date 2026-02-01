#pragma once

#include "fstream/IFStream.h"
#include "tokens/LabToken.h"

#include <string>

namespace pl
{

class Fcsv : pl::IFStream
{
    pl::LabToken read(const std::string&) noexcept(false);   
    pl::LabToken write(const std::string&) noexcept(false);   
};

}
