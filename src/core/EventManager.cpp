#include "EventManager.hpp"

void EventManager::pollEvents()
{
  pressed_keys.clear();
  is_space = false;
  while (const std::optional event = window.pollEvent())
  {
    if (event->is<sf::Event::Closed>())
    {
      is_closed = true;
      return;
    }

    if (event->is<sf::Event::KeyPressed>())
    {
      const auto *key_event = event->getIf<sf::Event::KeyPressed>();
      switch (key_event->scancode)
      {
      case sf::Keyboard::Scancode::Escape:
        pressed_keys.push_back(Key::escape);
        break;
      case sf::Keyboard::Scancode::Space:
        pressed_keys.push_back(Key::space);
        is_space = true;
        break;
      case sf::Keyboard::Scancode::R:
        pressed_keys.push_back(Key::r);
        break;
      case sf::Keyboard::Scancode::Q:
        pressed_keys.push_back(Key::q);
        break;

      default:
        break;
      }
    }
  }
}

bool EventManager::isWindowClosed() const
{
  return is_closed;
}

bool EventManager::isSpacePressed() const
{
  return is_space;
}

const std::vector<Key> &EventManager::getPressedKeys() const
{
  return pressed_keys;
}
