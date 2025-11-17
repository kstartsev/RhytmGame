#pragma once

#include "Entity.hpp"
#include "../utils/Utils.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

using namespace EntitiesParameters;

class Obstacle : Collidable
{
private:
  sf::VertexArray sprite;
  double pixels_per_second;
  double beat_pos;
  float start_x_pos;
  float width;
  float height;

public:
  Obstacle(float beat, std::shared_ptr<sf::Texture> texture_ptr, PositionState state, double pixels_per_second, short speed, float width = DEFAULT_SPIKE_WIDTH, float height = DEFAULT_SPIKE_HEIGHT);
  void reset() override;
  void draw(sf::RenderTarget &target) const override;
  void update(float dt) override;
  sf::FloatRect getHitbox() const override;
  void move(float pixels);
};
