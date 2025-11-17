#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Borders : public Entity
{
private:
  float shift_per_second;
  sf::RectangleShape bottom1;
  sf::RectangleShape top1;
  sf::RectangleShape bottom2;
  sf::RectangleShape top2;

public:
  Borders(std::shared_ptr<sf::Texture> texture_ptr, double pixels_per_second, short speed);
  ~Borders() noexcept override = default;

  void reset() override;
  void draw(sf::RenderTarget &target) const override;
  void update(float dt) override;
  // void setTexture(std::shared_ptr<sf::Texture> texture_ptr);
};
