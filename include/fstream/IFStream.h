#pragma once

#include "LabStruct.h"
#include <string>

namespace pl 
{

class IFStream
{
public:
    virtual LabStruct read(std::string) const;
    virtual LabStruct write(std::string) const;
};

}
