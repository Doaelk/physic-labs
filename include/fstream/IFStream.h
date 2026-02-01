#pragma once

#include "tokens/LabToken.h"

#include <string>

namespace pl 
{

class IFStream
{
public:
    virtual pl::LabToken read(const std::string&) noexcept(false);
    virtual pl::LabToken write(const std::string&) noexcept(false);
};

}
