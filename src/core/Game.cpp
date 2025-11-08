#include <vector>
#include <SFML/System.hpp>

#include <iostream>

#include "../entities/Obstacle.hpp"
#include "../entities/Player.hpp"
#include "../utils/Utils.hpp"

#include "Game.hpp"

Game::Game(sf::RenderWindow &window) : window(window)
{
  if (!main_font.openFromFile("../src/level/assets/fonts/main_font.ttf"))
  {
    std::cerr << "failed to load main_font.ttf" << std::endl;
  }
  context = Context(120, 60, 1);
}

void Game::run()
{

  Player player;

  std::vector<Obstacle> spikes;
  // spikes.push_back(Obstacle(Utils::beatsToPixels(3.f) + 350.f, PositionState::Down, context.getPixelsPerSecond()));
  // spikes.push_back(Obstacle(Utils::beatsToPixels(6.f) + 350.f, PositionState::Up, context.getPixelsPerSecond()));
  spikes.push_back(Obstacle(Utils::beatsToPixels(8.f) + 350.f, PositionState::Down, context.getPixelsPerSecond()));



  context.startTimers();
  while (window.isOpen())
  {
    while (const std::optional event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
        window.close();
      if (event->is<sf::Event::KeyPressed>())
      {
        const auto *key_event = event->getIf<sf::Event::KeyPressed>();
        if (key_event->scancode == sf::Keyboard::Scancode::Space)
        {
          player.jump();
          std::cout << context.getCurrentBeats() << std::endl;
        }
        if (key_event->scancode == sf::Keyboard::Scancode::Escape)
        {
          pause();
        }
      }
    }

    for(auto& spike: spikes) spike.update(context.getDeltaTime());
    window.clear(sf::Color::Black);
    for(auto& spike: spikes) spike.draw(window);
    player.draw(window);
    window.display();
  }
}

void Game::pause() // нужно еще рестарт
{
  context.stopTimers();
  sf::Text pause_text{main_font};
  pause_text.setString("PAUSED\n'R' to restart\n'Q' to exit");
  pause_text.setCharacterSize(80);
  pause_text.setFillColor(sf::Color::White);

  bool is_paused = true;

  while (window.isOpen() && is_paused)
  {
    while (const std::optional event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
        window.close();
      if (event->is<sf::Event::KeyPressed>())
      {
        const auto *key_event = event->getIf<sf::Event::KeyPressed>();
        if (key_event->scancode == sf::Keyboard::Scancode::Escape)
        {
          is_paused = false;
        }
        if (key_event->scancode == sf::Keyboard::Scancode::Q)
        {
          window.close();
        }
      }
    }
    window.clear(sf::Color::Black);
    window.draw(pause_text);
    window.display();
  }
  context.startTimers();
}
