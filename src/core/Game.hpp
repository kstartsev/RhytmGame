#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game
{
private:
    sf::RenderWindow &window;
public:
    explicit Game(sf::RenderWindow &window);
    void run();
}