#pragma once

#include "labs/LabStruct.h"
#include "tokens/LabToken.h"

#include <filesystem>
#include <string>

namespace pl 
{

class IFStream
{
public:
    virtual pl::LabToken read(const std::string&) noexcept(false);
    virtual void write(const LabStruct&, const std::filesystem::path&) noexcept(false);
};

}
