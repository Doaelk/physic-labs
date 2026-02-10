#pragma once 

#include <utility>
#include <vector>
#include <SFML/Window.hpp>
 
namespace pl
{

class Graphic
{
private:
    const sf::Window window;
    const std::vector<float> alongX;
    const std::vector<float> alongY;
    const std::vector<std::pair<float, float>> data;

public:
    Graphic(std::vector<float>& x, std::vector<float>& y, 
            std::vector<std::pair<float, float>>& data, sf::Window& win) 
    : window(std::move(win)), alongX(x), alongY(y),  data(data)  {}

    void drawWindow();

    Graphic(Graphic&&);
    Graphic(const Graphic&);

    ~Graphic() = default;
};

};
