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
  std::shared_ptr<sf::Texture> texture_ptr;
  sf::RenderStates render_states;
  sf::Vector2f position = {0, 0};

public:
  Entity(sf::Vector2f pos, std::shared_ptr<sf::Texture> texture_ptr) : position(pos), texture_ptr(texture_ptr) {};
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
  Collidable(sf::Vector2f pos, std::shared_ptr<sf::Texture> texture_ptr, PositionState state) : Entity(pos, texture_ptr), state(state) {};
  virtual ~Collidable() = default;
  virtual sf::FloatRect getHitbox() const = 0;
};
