#include "Obstacle.hpp"
#include "../utils/Utils.hpp"

#define SPIKE_YPOS_DOWN 750.f
#define SPIKE_YPOS_UP 150.f

Obstacle::Obstacle(float pos, PositionState state, double pixels_per_second, float width, float height) : Entity({pos, state == PositionState::Down ? SPIKE_YPOS_DOWN : SPIKE_YPOS_UP}, state), shape(sf::PrimitiveType::Triangles, 3), pixels_per_second(pixels_per_second)
{
  shape[0].position = {position.x - width / 2, position.y};
  shape[1].position = {position.x + width / 2, position.y};
  shape[2].position = {position.x, position.y + (state == PositionState::Down ? -height : height)};

  // позже загрузка текстуры
  shape[0].color = sf::Color::Red;
  shape[1].color = sf::Color::Red;
  shape[2].color = sf::Color::Red;

  hitbox = sf::FloatRect({static_cast<float>(position.x - width / 2.0), position.y}, {width, state == PositionState::Down ? -height : height});
}

void Obstacle::draw(sf::RenderTarget &target) const { target.draw(shape, transform); }

void Obstacle::move(float pixels)
{
  position.x -= pixels;
  transform.translate({pixels, 0.f});
  hitbox.position.x -= pixels;
}

sf::FloatRect Obstacle::getHitbox() const
{
  return hitbox;
}

void Obstacle::update(float dt)
{
  move(-dt * pixels_per_second);
}
