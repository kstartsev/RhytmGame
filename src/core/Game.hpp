
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Context.hpp"
#include "Scene.hpp"
#include "EventManager.hpp"
#include "FileManager.hpp"

class Game
{
private:
  sf::RenderWindow &window;
  FileManager assets;
  Context context;
  Scene scene;
  EventManager events;
  // sf::Font main_font;


public:
  explicit Game(sf::RenderWindow &window, const std::unordered_map<std::string, std::string>& filenames);

  void load();
  void run();
  void restart();
  void exit();

  void pause();
  void loss();
  void win();
};
