#pragma once

#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

class Utils
{
public:
  static float beatsToPixels(double beats, short speed);

  static bool checkCollision(const sf::FloatRect &a, const sf::FloatRect &b);

  static sf::Text createText(const sf::Font &font, const std::string &text, int size = 80, sf::Color color = sf::Color::White);
};

namespace Resources
{
  const std::string MAIN_FONT_KEY = "main_font";
  const std::string LEVEL_KEY = "level";
  const std::string PLAYER_TEXTURE_KEY = "player";
  const std::string OBSTACLE_TEXTURE_KEY = "obstacle";
  const std::string SHROOM_TEXTURE_KEY = "shroom";
  const std::string FLOOR_TEXTURE_KEY = "floor";
  const std::string ROOF_TEXTURE_KEY = "roof";
  const std::string BACKGROUND_KEY = "bg";
  const std::string UI_BACKGROUND_KEY = "uibg";
  const std::string LEVEL_MUSIC_KEY = "level_music";


  const std::string LEVEL_DATA_PATH = "../src/level";
  const std::string PREFERENCES_PATH = LEVEL_DATA_PATH + "/preferences.txt";
  const std::string ASSETS_PATH = LEVEL_DATA_PATH + "/assets";

  const std::unordered_map<std::string, std::string> getFilepaths();
};

namespace DefaultParameters
{
  constexpr int WINDOW_WIDTH = 1920;
  constexpr int WINDOW_HEIGHT = 1200;
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
  constexpr sf::Vector2f PLAYER_UP_SHIFT{0.f, -400.f};
  constexpr sf::Vector2f PLAYER_DOWN_SHIFT{0.f, 400.f};
  constexpr float TIME_FOR_ANIMATION_FRAME = 0.05f;
  constexpr float TIME_FOR_JUMP_FRAME = 0.03f;
  constexpr short JUMP_FRAMES_COUNT = 5;

  // floor/roof
  constexpr float ROOF_BOTTOM = 150.f;
  constexpr float ROOF_TOP = 0.f;
  constexpr float FLOOR_BOTTOM = 1200.f;
  constexpr float FLOOR_TOP = 750.f;

  // background
  constexpr float BACKGROUND_WIDTH = 1920.f;
  constexpr float BACKGROUND_HEIGHT = 600.f;

  // ui
  //  const std::string PAUSE_TEXT = "Game paused";
  //  const std::string WIN_TEXT = "Level complited";
  //  const std::string LOSS_TEXT = "Game over";

  // const std::string ESC_TEXT = "'ESC' to continue";
  // const std::string Q_TEXT = "'R' to restart";
  // const std::string R_TEXT = "'Q' to exit";

  // percent bar
  constexpr float X_BAR_POS = 745.f;
  constexpr float Y_BAR_POS = 50.f;
  constexpr float BAR_WIDTH = 200.f;
  constexpr float BAR_HEIGHT = 10.f;
  constexpr float INNER_OUTER_DIFF = 5.f;

  // shroom
  constexpr sf::Vector2f SHROOM_SIZE{80.f, 80.f};
  constexpr sf::Vector2f SHROOM_ORIGIN{40.f, 0.f};
  constexpr float SHROOM_YPOS_DOWN = 670.f;
  constexpr float SHROOM_YPOS_UP = 230.f;
  constexpr sf::FloatRect NULL_HITBOX = sf::FloatRect({0,0},{0,0});
};
