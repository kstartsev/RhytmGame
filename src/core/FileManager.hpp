#pragma once

#include <unordered_map>
#include <memory>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Scene.hpp"
#include "Context.hpp"
#include "AudioManager.hpp"
#include "../utils/Utils.hpp"

class FileManager
{
private:
  sf::Font main_font;
  std::ifstream level_file;
  const std::unordered_map<std::string, std::string> files_paths;
  std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;
  std::shared_ptr<sf::Music> level_music = std::make_shared<sf::Music>();

public:
  explicit FileManager(const std::unordered_map<std::string, std::string> files_paths);
  ~FileManager() = default;

  bool openFiles();
  bool buildGame(Context &context, Scene &scene, AudioManager &audio);
  const sf::Font &getFont() const;
};
