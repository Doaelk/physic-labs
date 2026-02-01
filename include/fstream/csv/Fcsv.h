#pragma once

#include "fstream/IFStream.h"
#include "labs/LabStruct.h"
#include "tokens/LabToken.h"

#include <filesystem>
#include <string>

namespace pl
{

class Fcsv : pl::IFStream
{
    pl::LabToken read(const std::string&) noexcept(false) override final;   
    void write(const LabStruct&, const std::filesystem::path&) noexcept(false) override final;   
};

}
