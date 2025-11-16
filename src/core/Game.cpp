#include <vector>
#include <unordered_map>
#include <iostream>
#include <SFML/System.hpp>

#include "../entities/Obstacle.hpp"
#include "../entities/Player.hpp"
#include "../utils/Utils.hpp"

#include "Game.hpp"

#define NORMAL_SPEED 1
#define FAST_SPEED 2
#define VERYFAST_SPEED 3

Game::Game(sf::RenderWindow &window, const std::unordered_map<std::string, std::string> &filenames) : window(window), events(window), assets(filenames), scene(events)
{
}

void Game::run()
{
  load();
  while (window.isOpen())
  {

    events.pollEvents();
    if (events.isWindowClosed())
      exit();
    if (context.isFinish())
      win();
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
  sf::Text pause_text = Utils::createText(assets.getFont(), "PAUSE\n'ESC' to continue\n'R' to restart\n'Q' to exit", 150);

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
        return;

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
  sf::Text loss_text = Utils::createText(assets.getFont(), "GAME OVER\n'R' to restart\n'Q' to exit", 150);

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
        return;

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
  context.stopTimers();
  context.reset();
  scene.reset();
  context.startTimers();
}

void Game::load()
{
  if (!assets.openFiles())
    exit();
  if (!assets.createContext(context))
    exit();
  if (!assets.createScene(scene, context.getPixelsPerSecond(), context.getAudioDuration()))
    exit();
  context.startTimers();
}

void Game::win()
{
  context.stopTimers();
  sf::Text win_text = Utils::createText(assets.getFont(), "LEVEL COMPLETED\n'R' to restart\n'Q' to exit", 150);

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
        return;

      default:
        break;
      }
    }
    window.clear(sf::Color::Black);
    window.draw(win_text);
    window.display();
  }
  context.startTimers();
}
