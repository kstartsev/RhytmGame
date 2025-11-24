#include "FileManager.hpp"

#include <iostream>
#include <sstream>

using namespace Resources;

FileManager::FileManager(const std::unordered_map<std::string, std::string> files_paths) : files_paths(files_paths) {}

const sf::Font &FileManager::getFont() const
{
  return main_font;
}

bool FileManager::openFiles()
{
  /// load font
  if (!main_font.openFromFile(files_paths.at(MAIN_FONT_KEY)))
  {
    std::cerr << "failed to load main_font.ttf" << std::endl;
    return false;
  }

  /// load level
  level_file.open(files_paths.at(LEVEL_KEY));
  if (!level_file.is_open())
  {
    std::cerr << "failed to load level.txt" << std::endl;
    return false;
  }

  /// load textures
  auto player_texture = std::make_shared<sf::Texture>();
  if (!player_texture->loadFromFile(files_paths.at(PLAYER_TEXTURE_KEY)))
  {
    std::cerr << "failed to load player.png" << std::endl;
    return false;
  }
  player_texture->setSmooth(true);
  textures[PLAYER_TEXTURE_KEY] = player_texture;

  auto obstacle_texture = std::make_shared<sf::Texture>();
  if (!obstacle_texture->loadFromFile(files_paths.at(OBSTACLE_TEXTURE_KEY)))
  {
    std::cerr << "failed to load obstacle.png" << std::endl;
    return false;
  }
  obstacle_texture->setSmooth(true);
  textures[OBSTACLE_TEXTURE_KEY] = obstacle_texture;

  auto floor_texture = std::make_shared<sf::Texture>();
  if (!floor_texture->loadFromFile(files_paths.at(FLOOR_TEXTURE_KEY)))
  {
    std::cerr << "failed to load floor.png" << std::endl;
    return false;
  }
  floor_texture->setSmooth(true);
  textures[FLOOR_TEXTURE_KEY] = floor_texture;

  auto bg_texture = std::make_shared<sf::Texture>();
  if (!bg_texture->loadFromFile(files_paths.at(BACKGROUND_KEY)))
  {
    std::cerr << "failed to load bg.png" << std::endl;
    return false;
  }
  bg_texture->setSmooth(true);
  textures[BACKGROUND_KEY] = bg_texture;

  auto shroom_texture = std::make_shared<sf::Texture>();
  if (!shroom_texture->loadFromFile(files_paths.at(SHROOM_TEXTURE_KEY)))
  {
    std::cerr << "failed to load mushroom.png" << std::endl;
    return false;
  }
  shroom_texture->setSmooth(true);
  textures[SHROOM_TEXTURE_KEY] = shroom_texture;

  /// load audio
  if (!level_music->openFromFile(files_paths.at(LEVEL_MUSIC_KEY)))
  {
    std::cerr << "failed to load level_music.mp3" << std::endl;
    return false;
  }

  return true;
}

bool FileManager::buildGame(Context &context, Scene &scene, AudioManager &audio)
{
  openFiles();
  audio.setMusic(level_music);
  std::string parameters_line;

  if (!std::getline(level_file, parameters_line))
  {
    std::cerr << "Failed to read level parameters" << std::endl;
    return false;
  }

  std::istringstream parameters_stream(parameters_line);
  double duration;
  int bpm;
  short level_speed;

  if (!(parameters_stream >> duration >> bpm >> level_speed))
  {
    std::cerr << "Invalid level parameters" << std::endl;
    return false;
  }
  context = Context(duration, bpm, level_speed);

  double pixels_per_second = context.getPixelsPerSecond();
  scene.setPlayerSpeed(level_speed);
  /// player texture set
  auto player_texture = textures[PLAYER_TEXTURE_KEY];
  if (player_texture)
  {
    scene.setPlayerTexture(player_texture);
  }
  /// bg texture set
  auto bg_texture = textures[BACKGROUND_KEY];
  if (bg_texture)
  {
    scene.addDecoration(std::make_unique<Background>(bg_texture, pixels_per_second, level_speed));
  }
  /// borders texture set
  auto floor_texture = textures[FLOOR_TEXTURE_KEY];
  if (floor_texture)
  {
    scene.addDecoration(std::make_unique<Borders>(floor_texture, pixels_per_second));
  }
  scene.addDecoration(std::make_unique<PercentBar>(getFont(), "", duration));

  while (std::getline(level_file, parameters_line))
  {
    std::istringstream parameters_stream(parameters_line);
    bool is_any_loaded = false;
    float pos = 0;
    char state_char;
    char mush_char;
    float width = 0;
    float height = 0;

    if (parameters_stream >> pos >> state_char && (state_char == 'D' || state_char == 'U'))
    {
      if (parameters_stream >> mush_char)
      {
        if (mush_char != 'M')
        {
          std::cerr << "Invalid obstacle parameters" << std::endl;
          return false;
        }
        PositionState state = (state_char == 'D') ? PositionState::Down : PositionState::Up;
        auto shroom_texture = textures[SHROOM_TEXTURE_KEY];
        if (shroom_texture)
        {
          scene.addCollidable(std::make_unique<Shroom>(pos - 1, shroom_texture, state, pixels_per_second, level_speed));
          is_any_loaded = true;
        }
      }
      else
      {
        PositionState state = (state_char == 'D') ? PositionState::Down : PositionState::Up;
        auto obstacle_texture = textures[OBSTACLE_TEXTURE_KEY];
        if (obstacle_texture)
        {
          scene.addCollidable(std::make_unique<Obstacle>(pos - 1, obstacle_texture, state, pixels_per_second, level_speed));
        }

        is_any_loaded = true;
      }
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
