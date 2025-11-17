#pragma once

#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

class Utils
{
public:
  static float beatsToPixels(double beats, short speed);

  static bool checkCollision(const sf::FloatRect &a, const sf::FloatRect &b);

  static sf::Text createText(sf::Font font, std::string text, int size = 80, sf::Color color = sf::Color::White);
};

namespace Resources
{
  const std::string MAIN_FONT_KEY = "main_font";
  const std::string LEVEL_KEY = "level";
  const std::string PLAYER_TEXTURE_KEY = "player";
  const std::string OBSTACLE_TEXTURE_KEY = "obstacle";
  const std::string FLOOR_TEXTURE_KEY = "floor";
  const std::string ROOF_TEXTURE_KEY = "roof";
  const std::string BACKGROUND_KEY = "bg";

  const std::unordered_map<std::string, std::string> &getDefaultFilenames();
};

namespace DefaultParameters
{
  constexpr int WINDOW_WIDTH = 1920;
  constexpr int BEATS_PER_SCREEN = 4;
};

namespace EntitiesParameters
{
  // spike
  constexpr float SPIKE_YPOS_DOWN = 750.f;
  constexpr float SPIKE_YPOS_UP = 150.f;
  constexpr float PLAYER_XOFFSET = 350.f;
  constexpr float DEFAULT_SPIKE_WIDTH = 100.f;
  constexpr float DEFAULT_SPIKE_HEIGHT = 100.f;
  constexpr short SPIKE_VERTEXES_NUMBER = 3;

  // player
  constexpr sf::Vector2f DEFAULT_PLAYER_POS{250.f, 650.f};
  constexpr sf::Vector2f DEFAULT_PLAYER_SIZE{100.f, 100.f};
  constexpr sf::Vector2f PLAYER_UP_SHIFT{0.f, -500.f};
  constexpr sf::Vector2f PLAYER_DOWN_SHIFT{0.f, 500.f};

  // floor/roof
  constexpr float ROOF_BOTTOM = 250.f;
  constexpr float ROOF_TOP = 0.f;
  constexpr float FLOOR_BOTTOM = 1200.f;
  constexpr float FLOOR_TOP = 750.f;

};
