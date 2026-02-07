#pragma once

#include "tokens/LabToken.h"

#include <filesystem>
#include <string>

namespace pl 
{

class FStream
{
public:
    virtual pl::LabToken read(const std::string&) noexcept(false);
    virtual void write(const pl::LabToken&, const std::filesystem::path&) noexcept(false);
};

}
