#pragma once

#include "tokens/LabToken.h"

#include <filesystem>
#include <memory>
#include <string>

namespace pl 
{

class FStream
{
public:
    virtual std::shared_ptr<pl::LabToken> read(const std::string&) noexcept(false);
    virtual void write(const pl::LabToken&, const std::filesystem::path&) noexcept(false);
};

}
