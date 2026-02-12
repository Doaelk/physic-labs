#pragma once

#include "graphics/Graphic.h"
#include "graphics/render/IRender.h"
#include "tokens/lab/LabToken.h"
#include <vector>
namespace pl 
{

class Decart : Graphic
{
private:

    struct Data
    {
        std::vector<float> x;
        std::vector<float> y;
    };

    std::vector<Data> data;
    float xStep, yStep;


public:
    Decart(IRender&&);
    Decart(LabToken&, IRender&&);
};

}
