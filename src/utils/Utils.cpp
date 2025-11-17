#include "Utils.hpp"

float Utils::beatsToPixels(double beats, short speed)
{
  return (beats / DefaultParameters::BEATS_PER_SCREEN) * DefaultParameters::WINDOW_WIDTH * speed;
}

bool Utils::checkCollision(const sf::FloatRect &a, const sf::FloatRect &b)
{
  return a.position.x < b.position.x + b.size.x &&
         a.position.x + a.size.x > b.position.x &&
         a.position.y < b.position.y + b.size.y &&
         a.position.y + a.size.y > b.position.y;
}

sf::Text Utils::createText(sf::Font font, std::string text, int size, sf::Color color)
{
  sf::Text result{font};
  result.setString(text);
  result.setCharacterSize(size);
  result.setFillColor(color);
  return result;
}

const std::unordered_map<std::string, std::string> &Resources::getDefaultFilenames()
{
  static const std::unordered_map<std::string, std::string> filenames =
      {
          {Resources::LEVEL_KEY, "../src/level/level.txt"},
          {Resources::MAIN_FONT_KEY, "../src/level/assets/fonts/main_font.ttf"},
          {Resources::PLAYER_TEXTURE_KEY, "../src/level/assets/textures/player.png"},
          {Resources::OBSTACLE_TEXTURE_KEY, "../src/level/assets/textures/obstacle.png"},
          {Resources::FLOOR_TEXTURE_KEY, "../src/level/assets/textures/floor.png"},
          {Resources::ROOF_TEXTURE_KEY, "../src/level/assets/textures/roof.png"},
          {Resources::BACKGROUND_KEY, "../src/level/assets/textures/bg.png"}};
  return filenames;
}
