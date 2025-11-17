#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Borders : public Entity
{
private:
  double pixels_per_second;
  sf::RectangleShape bottom;
  sf::RectangleShape top;

public:
  Borders(std::shared_ptr<sf::Texture> texture_ptr, double pixels_per_second);
  ~Borders() noexcept override = default;

  void reset() override;
  void draw(sf::RenderTarget &target) const override;
  void update(float dt) override;
  void setTexture(std::shared_ptr<sf::Texture> texture_ptr);
};
