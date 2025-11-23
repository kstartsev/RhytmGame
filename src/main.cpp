#include "core/Game.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
  sf::ContextSettings settings;
  settings.antiAliasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode({1920, 1200}), "WINter Arc",
                          sf::Style::Default, sf::State::Windowed, settings);
  window.setVerticalSyncEnabled(true);
  window.setKeyRepeatEnabled(false);
  window.setView(window.getDefaultView());
  Game game(window);
  game.run();
  return 0;
}
