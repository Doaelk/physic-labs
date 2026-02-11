#pragma once 

#include "graphics/render/IRender.h"
#include <utility>
#include <vector>
 
namespace pl
{

class Graphic
{
private:
    IRender render;
    const std::vector<float> alongX;
    const std::vector<float> alongY;
    const std::vector<std::pair<float, float>> data;

public:
    Graphic(std::vector<float>&& x, std::vector<float>&& y, 
            std::vector<std::pair<float, float>>&& data, IRender&& render) 
    : render(std::move(render)), alongX(std::move(x)), alongY(std::move(y)),  data(std::move(data))  {}

    void setRenderType(IRender&& render);

    void drawGraphic();

    Graphic(Graphic&&);
    Graphic(const Graphic&);

    ~Graphic() = default;
};

};
