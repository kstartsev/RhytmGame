#include <vector>
#include <iostream>
#include <SFML/System.hpp>

#include "../entities/Obstacle.hpp"
#include "../entities/Player.hpp"
#include "../utils/Utils.hpp"

#include "Game.hpp"

#define NORMAL_SPEED 1
#define FAST_SPEED 2
#define VERYFAST_SPEED 3

Game::Game(sf::RenderWindow &window) : window(window), events(window), scene(events)
{
  if (!main_font.openFromFile("../src/level/assets/fonts/main_font.ttf"))
  {
    std::cerr << "failed to load main_font.ttf" << std::endl;
  }
  context = Context(120, 60, 1);
}

void Game::run()
{
  scene.addEntity(Obstacle(1.f, PositionState::Down, context.getPixelsPerSecond()));
  scene.addEntity(Obstacle(1.2f, PositionState::Down, context.getPixelsPerSecond()));
  scene.addEntity(Obstacle(1.4f, PositionState::Down, context.getPixelsPerSecond()));
  scene.addEntity(Obstacle(2.f, PositionState::Up, context.getPixelsPerSecond()));
  scene.addEntity(Obstacle(2.5f, PositionState::Down, context.getPixelsPerSecond()));
  scene.addEntity(Obstacle(3.f, PositionState::Up, context.getPixelsPerSecond()));

  context.startTimers();
  while (window.isOpen())
  {
    events.pollEvents();
    if (events.isWindowClosed())
      exit();
    for (auto key : events.getPressedKeys())
    {
      if (key == Key::escape)
        pause();
    }
    context.updateDeltaTime();
    scene.update(context.getDeltaTime());
    if (scene.checkCollisions())
      loss();

    window.clear(sf::Color::Black);
    scene.draw(window);
    window.display();
  }
}

void Game::pause() // нужно еще рестарт
{
  context.stopTimers();
  sf::Text pause_text{main_font};
  pause_text.setString("PAUSED\n'ESC to continue'\n'R' to restart\n'Q' to exit");
  pause_text.setCharacterSize(80);
  pause_text.setFillColor(sf::Color::White);

  bool is_paused = true;

  while (window.isOpen() && is_paused)
  {
    events.pollEvents();
    if (events.isWindowClosed())
      exit();
    for (auto key : events.getPressedKeys())
    {
      switch (key)
      {
      case Key::escape:
        is_paused = false;
        break;
      case Key::q:
        exit();
        break;
      case Key::r:
        restart();
        break;

      default:
        break;
      }
    }
    window.clear(sf::Color::Black);
    window.draw(pause_text);
    window.display();
  }
  context.startTimers();
}

void Game::loss() // нужно еще рестарт
{
  context.stopTimers();
  sf::Text loss_text = Utils::createText(main_font, "GAME OVER\n'R' to restart\n'Q' to exit", 200);

  while (window.isOpen())
  {
    events.pollEvents();
    if (events.isWindowClosed())
      exit();
    for (auto key : events.getPressedKeys())
    {
      switch (key)
      {
      case Key::q:
        exit();
        break;
      case Key::r:
        restart();
        break;
      default:
        break;
      }
    }
    window.clear(sf::Color::Black);
    window.draw(loss_text);
    window.display();
  }
  context.startTimers();
}

void Game::exit()
{
  window.close();
}

void Game::restart()
{
}
