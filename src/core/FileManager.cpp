#include "FileManager.hpp"

#include <iostream>
#include <sstream>

using namespace Resources;

FileManager::FileManager(const std::unordered_map<std::string, std::string> &filenames) : filenames(filenames) {}

sf::Font FileManager::getFont() const
{
  return main_font;
}

bool FileManager::openFiles()
{
  /// load font
  if (!main_font.openFromFile(filenames.at(MAIN_FONT_KEY)))
  {
    std::cerr << "failed to load main_font.ttf" << std::endl;
    return false;
  }

  /// load level
  level_file.open(filenames.at(LEVEL_KEY));
  if (!level_file.is_open())
  {
    std::cerr << "failed to load level.txt" << std::endl;
    return false;
  }

  /// load textures
  auto player_texture = std::make_shared<sf::Texture>();
  if (!player_texture->loadFromFile(filenames.at(PLAYER_TEXTURE_KEY)))
  {
    std::cerr << "failed to load player.png" << std::endl;
    return false;
  }
  player_texture->setSmooth(true);
  textures[PLAYER_TEXTURE_KEY] = player_texture;

  auto obstacle_texture = std::make_shared<sf::Texture>();
  if (!obstacle_texture->loadFromFile(filenames.at(OBSTACLE_TEXTURE_KEY)))
  {
    std::cerr << "failed to load obstacle.png" << std::endl;
    return false;
  }
  obstacle_texture->setSmooth(true);
  textures[OBSTACLE_TEXTURE_KEY] = obstacle_texture;

  auto floor_texture = std::make_shared<sf::Texture>();
  if (!floor_texture->loadFromFile(filenames.at(FLOOR_TEXTURE_KEY)))
  {
    std::cerr << "failed to load floor.png" << std::endl;
    return false;
  }
  floor_texture->setSmooth(true);
  textures[FLOOR_TEXTURE_KEY] = floor_texture;

  auto bg_texture = std::make_shared<sf::Texture>();
  if (!bg_texture->loadFromFile(filenames.at(BACKGROUND_KEY)))
  {
    std::cerr << "failed to load bg.png" << std::endl;
    return false;
  }
  bg_texture->setSmooth(true);
  textures[BACKGROUND_KEY] = bg_texture;

  return true;
}

bool FileManager::createContext(Context &context)
{
  std::string parameters_line;
  if (!std::getline(level_file, parameters_line))
  {
    std::cerr << "Failed to read level parameters" << std::endl;
    return false;
  }

  std::istringstream parameters_stream(parameters_line);
  double duration;
  int bpm;

  if (!(parameters_stream >> duration >> bpm >> level_speed))
  {
    std::cerr << "Invalid level parameters" << std::endl;
    return false;
  }
  context = Context(duration, bpm, level_speed);
  return true;
}

bool FileManager::createScene(Scene &scene, double pixels_per_second, double duration)
{
  std::string parameters_line;
  /// player texture set
  auto player_texture = textures[PLAYER_TEXTURE_KEY];
  if (player_texture)
  {
    scene.setPlayerTexture(player_texture);
  }
  /// borders texture set
  auto floor_texture = textures[FLOOR_TEXTURE_KEY];
  if (floor_texture)
  {
    scene.setBordersTexture(floor_texture);
  }


  while (std::getline(level_file, parameters_line))
  {
    std::istringstream parameters_stream(parameters_line);
    bool is_any_loaded = false;
    float pos = 0;
    char state_char;
    float width = 0;
    float height = 0;

    if (parameters_stream >> pos >> state_char && (state_char == 'D' || state_char == 'U'))
    {
      PositionState state = (state_char == 'D') ? PositionState::Down : PositionState::Up;
      auto obstacle_texture = textures[OBSTACLE_TEXTURE_KEY];
      if (obstacle_texture)
      {
        scene.addObstacle(obstacle_texture, pos, state, pixels_per_second, level_speed);
      }

      is_any_loaded = true;
    }
    else
    {
      std::cerr << "Invalid obstacle parameters" << std::endl;
      return false;
    }
    if (pos > duration)
    {
      std::cerr << "Invalid obstacle position" << std::endl;
      return false;
    }
  }
  return true;
}
