#pragma once

#include "fstream/FStream.h"
#include "tokens/LabToken.h"

#include <filesystem>
#include <string>

namespace pl
{

class Fcsv : pl::FStream
{
    pl::LabToken read(const std::string&) noexcept(false) override final;   
    void write(const pl::LabToken&, const std::filesystem::path&) noexcept(false) override final;   
};

}
