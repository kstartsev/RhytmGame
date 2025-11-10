#pragma once

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum class Key
{
  escape,
  r,
  q,
  space
};

class EventManager
{
private:
  sf::RenderWindow &window;
  std::vector<Key> pressed_keys;
  bool is_closed = false;
  bool is_space = false;

public:
  explicit EventManager(sf::RenderWindow &window) : window(window) {};
  ~EventManager() = default;
  void pollEvents();
  bool isWindowClosed() const;
  bool isSpacePressed() const;
  const std::vector<Key> &getPressedKeys() const;
};
