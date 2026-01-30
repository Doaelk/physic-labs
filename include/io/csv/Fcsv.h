#pragma once

#include "io/FStream.h"
#include <string>

namespace pl
{

class Fcsv : pl::FStream
{
    void read(std::string) const;   
    void write(std::string) const;   
};

}
