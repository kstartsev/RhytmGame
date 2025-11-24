#pragma once

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class Shroom : public Collidable
{
private:
  sf::RectangleShape sprite;
  double pixels_per_second;
  double beat_pos;
  bool is_collected = false;

public:
  Shroom(float beat, std::shared_ptr<sf::Texture> texture_ptr, PositionState state, double pixels_per_second, short speed);
  ~Shroom() noexcept override = default;
  void reset() override;
  void draw(sf::RenderTarget &target) const override;
  void update(float dt) override;
  sf::FloatRect getHitbox() const override;
  double getPos() const override;
  bool isFatal() override;
};
