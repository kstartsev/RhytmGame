#include "Game.hpp"

Game::Game(sf::RenderWindow &window) : window(window) {}

void Game::run()
{
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
    }
}