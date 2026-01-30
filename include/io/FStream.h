#pragma once

#include <string>

namespace pl 
{

class FStream
{
public:
    virtual void read(std::string) const;
    virtual void write(std::string) const;
};

}
