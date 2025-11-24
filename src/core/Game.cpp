#include <vector>
#include <unordered_map>
#include <iostream>
#include <SFML/System.hpp>

#include "../entities/Obstacle.hpp"
#include "../entities/Player.hpp"
#include "../utils/Utils.hpp"

#include "Game.hpp"

Game::Game(sf::RenderWindow &window) :
    window(window),
    assets(Resources::getFilepaths()),  // Первый
    events(window),
    scene(events),                      // После assets
    context(),
    audio()
{}

void Game::run()
{
  load();
  audio.playMusic();
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
    if (scene.checkCollisions(context.getCurrentBeats()))
      loss();

    window.clear(sf::Color::Black);
    scene.draw(window);
    window.display();
  }
}

void Game::pause() // нужно еще рестарт
{
  context.stopTimers();
  audio.pauseMusic();
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
  audio.playMusic();
  context.startTimers();
}

void Game::loss() // нужно еще рестарт
{
  context.stopTimers();
  audio.pauseMusic();
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
  audio.playMusic();
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
  audio.resetMusic();
  context.startTimers();
}

void Game::load()
{
  if (!assets.buildGame(context, scene, audio))
    exit();
  context.startTimers();
  audio.playMusic();
}

void Game::win()
{
  context.stopTimers();
  audio.pauseMusic();
  sf::Text win_text = Utils::createText(assets.getFont(), "LEVEL COMPLETED\nscore: " + std::to_string(scene.getScore()) + "\n\n'R' to restart\n'Q' to exit", 150);

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
}
