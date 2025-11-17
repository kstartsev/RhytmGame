#pragma once

#include <unordered_map>
#include <memory>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Scene.hpp"
#include "Context.hpp"
#include "../utils/Utils.hpp"

class FileManager
{
private:
  short level_speed;
  sf::Font main_font;
  std::ifstream level_file;
  const std::unordered_map<std::string, std::string> &filenames;
  std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;

public:
  explicit FileManager(const std::unordered_map<std::string, std::string> &filenames);
  ~FileManager() = default;

  bool openFiles();
  bool createContext(Context &context);
  bool createScene(Scene &scene, double pixels_per_second, double duration);
  sf::Font getFont() const;
};
