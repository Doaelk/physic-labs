#pragma once

#include "fstream/FStream.h"
#include "tokens/LabToken.h"

#include <filesystem>
#include <memory>
#include <string>

namespace pl
{

class Fcsv : pl::FStream
{
public:
    std::shared_ptr<pl::LabToken> read(const std::string&) noexcept(false) override final;   
    void write(const pl::LabToken&, const std::filesystem::path&) noexcept(false) override final;   
};

}
