#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH 1920
#define BEATS_PER_SCREEN 4

class Utils
{
public:
  static float beatsToPixels(double beats, short speed)
  {
    return (beats / BEATS_PER_SCREEN) * SCREEN_WIDTH * speed;
  }

  static bool checkCollision(const sf::FloatRect &a, const sf::FloatRect &b)
  {
    return a.position.x < b.position.x + b.size.x &&
           a.position.x + a.size.x > b.position.x &&
           a.position.y < b.position.y + b.size.y &&
           a.position.y + a.size.y > b.position.y;
  }

  static sf::Text createText(sf::Font font, std::string text, int size = 80, sf::Color color = sf::Color::White)
  {
    sf::Text result{font};
    result.setString(text);
    result.setCharacterSize(size);
    result.setFillColor(color);
    return result;
  }
};
