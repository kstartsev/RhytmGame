#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

enum class PositionState
{
  Up,
  Down
};

class Entity
{
protected:
  sf::Texture texture;
  sf::RenderStates render_states;
  sf::Vector2f position = {0, 0};

public:
  Entity(sf::Vector2f pos, sf::Texture texture) : position(pos), texture(texture) {};
  virtual ~Entity() = default;
  virtual void draw(sf::RenderTarget &target) const = 0;
  virtual void update(float dt) = 0;
  virtual void reset() = 0;
};

class Collidable : public Entity
{
protected:
  PositionState state = PositionState::Down;
  sf::FloatRect hitbox;

public:
  Collidable(sf::Vector2f pos, sf::Texture texture, PositionState state) : Entity(pos, texture), state(state) {};
  virtual ~Collidable() = default;
  virtual sf::FloatRect getHitbox() const = 0;
};
