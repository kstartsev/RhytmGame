#pragma once

#include "Entity.hpp"

class PercentBar : public Entity
{
private:
  sf::Text text;
  sf::RectangleShape inner_bar;
  sf::RectangleShape outer_bar;
  double duration = 0;
  double time = 0;

public:
  PercentBar(const sf::Font &font, std::string line, double duration);
  ~PercentBar() noexcept override = default;

  void reset() override;
  void update(float dt) override;
  void draw(sf::RenderTarget &target) const override;
};
