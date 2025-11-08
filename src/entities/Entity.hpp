#pragma once

#include <SFML/Graphics.hpp>

enum class PositionState
{
  Up,
  Down
};

class Entity
{
protected:
  PositionState state = PositionState::Down;
  sf::Vector2f position = {0, 0};

public:
  Entity(sf::Vector2f pos, PositionState state) : position(pos), state(state) {};
  virtual ~Entity() = default;
  virtual void draw(sf::RenderTarget &target) const = 0;
  virtual void update(float dt) = 0;
};
