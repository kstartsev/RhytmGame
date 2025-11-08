
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Context.hpp"

class Game
{
private:
  sf::RenderWindow &window;
  Context context;
  sf::Font main_font;

public:
  explicit Game(sf::RenderWindow &window);

  void run();
  void pause();

  void loss();
  void restart();
  void exit();
};
