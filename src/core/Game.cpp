#include "Game.hpp"

Game::Game(sf::RenderWindow &window) : window(window) {}

void Game::run()
{
    sf::RectangleShape rectangle({100.f, 100.f});
    rectangle.setFillColor(sf::Color::White);
    ///rectangle.setOrigin({50.f, 50.f});
    rectangle.setPosition({250.f, 150.f});

    sf::RectangleShape rectangle2({100.f, 100.f});
    rectangle2.setFillColor(sf::Color::White);
    rectangle2.setPosition({250.f, 650.f});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::Black);

        window.draw(rectangle);
        window.draw(rectangle2);
        window.display();
    }
}