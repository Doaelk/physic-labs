#pragma once 

#include "graphics/render/IRender.h"
#include "tokens/lab/LabToken.h"
#include <utility>
 
namespace pl
{

class Graphic
{
private:
    IRender render;

public:
    Graphic(IRender&& render) : render(std::move(render))  {}

    void setRenderType(IRender&& render);

    void drawGraphic();

    void addData(LabToken&&);

    Graphic(Graphic&&) = default;
    Graphic(const Graphic&) = default;

    ~Graphic() = default;
};

};
