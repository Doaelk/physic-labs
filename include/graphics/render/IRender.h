#pragma once

#include <string>
namespace pl 
{

class IRender
{
public:
    void dot(float x, float y);
    void line(float x1, float y1, float x2, float y2);
    void circle(float x, float y, float radius);
    void rectangle(float x1, float y1, float x2, float y2);
    void text(float x, float y, std::string);
};

}
