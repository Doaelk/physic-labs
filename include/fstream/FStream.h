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
    virtual std::shared_ptr<pl::LabToken> read(const std::string&) noexcept(false) = 0;
    virtual void write(const std::shared_ptr<pl::LabToken>, const std::filesystem::path&) noexcept(false) = 0;
};

}
