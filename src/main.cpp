#include "core/Game.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
  const std::unordered_map<std::string, std::string> filenames =
      {
          {LEVEL_KEY, "../src/level/level.txt"},
          {MAIN_FONT_KEY, "../src/level/assets/fonts/main_font.ttf"},
          {PLAYER_TEXTURE_KEY, "../src/level/assets/textures/player.png"},
          {OBSTACLE_TEXTURE_KEY, "../src/level/assets/textures/obstacle.png"},
          {FLOOR_TEXTURE_KEY, "../src/level/assets/textures/floor.png"},
          {BACKGROUND_KEY, "../src/level/assets/textures/bg.png"}};

  sf::ContextSettings settings;
  settings.antiAliasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode({1920, 1200}), "RhytmGame",
                          sf::Style::Default, sf::State::Windowed, settings);
  window.setVerticalSyncEnabled(true);
  window.setKeyRepeatEnabled(false);
  window.setView(window.getDefaultView());
  Game game(window, filenames);
  game.run();
  return 0;
}
