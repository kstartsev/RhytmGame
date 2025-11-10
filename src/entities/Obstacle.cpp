#include "Obstacle.hpp"
#include "../utils/Utils.hpp"

#include <iostream>

#define SPIKE_YPOS_DOWN 750.f
#define SPIKE_YPOS_UP 150.f
#define PLAYER_XOFFSET 350.f

Obstacle::Obstacle(float beat, PositionState state, double pixels_per_second, float width, float height) : beat_pos(beat), Entity({Utils::beatsToPixels(beat) + PLAYER_XOFFSET, state == PositionState::Down ? SPIKE_YPOS_DOWN : SPIKE_YPOS_UP}, state), sprite(sf::PrimitiveType::Triangles, 3), pixels_per_second(pixels_per_second)
{
  sprite[0].position = {position.x - width / 2, position.y};
  sprite[1].position = {position.x + width / 2, position.y};
  sprite[2].position = {position.x, position.y + (state == PositionState::Down ? -height : height)};

  // позже загрузка текстуры
  sprite[0].color = sf::Color::Red;
  sprite[1].color = sf::Color::Red;
  sprite[2].color = sf::Color::Red;

  if (state == PositionState::Down)
  {
    hitbox = sf::FloatRect({position.x - width / 2, position.y - height}, {width, height});
  }
  else
  {
    hitbox = sf::FloatRect({position.x - width / 2, position.y}, {width, height});
  }
}

void Obstacle::draw(sf::RenderTarget &target) const { target.draw(sprite, transform); }

void Obstacle::move(float pixels)
{
  position.x += pixels;
  transform.translate({pixels, 0.f});
  hitbox.position.x += pixels;
}

sf::FloatRect Obstacle::getHitbox() const
{
  return hitbox;
}

void Obstacle::update(float dt)
{
  move(-dt * pixels_per_second);
}
