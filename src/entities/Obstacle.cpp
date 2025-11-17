#include "Obstacle.hpp"

#include <iostream>

using namespace EntitiesParameters;

Obstacle::Obstacle(float beat, std::shared_ptr<sf::Texture> texture_ptr, PositionState state, double pixels_per_second, short speed, float width, float height) : beat_pos(beat),
                                                                                                                                                                  Collidable({Utils::beatsToPixels(beat, speed) + PLAYER_XOFFSET, state == PositionState::Down ? SPIKE_YPOS_DOWN : SPIKE_YPOS_UP}, texture_ptr, state),
                                                                                                                                                                  sprite(sf::PrimitiveType::Triangles, SPIKE_VERTEXES_NUMBER), pixels_per_second(pixels_per_second),
                                                                                                                                                                  width(width),
                                                                                                                                                                  height(height)
{
  sprite[0].position = {position.x - width / 2, position.y};
  sprite[1].position = {position.x + width / 2, position.y};
  sprite[2].position = {position.x, position.y + (state == PositionState::Down ? -height : height)};

  sprite[0].texCoords = {0.f, height};
  sprite[1].texCoords = {width, height};
  sprite[2].texCoords = {width / 2, 0.f};

  if (state == PositionState::Down)
  {
    hitbox = sf::FloatRect({position.x - width / 2, position.y - height}, {width, height});
  }
  else
  {
    hitbox = sf::FloatRect({position.x - width / 2, position.y}, {width, height});
  }
  start_x_pos = position.x;
  render_states.texture = texture_ptr.get();
}

void Obstacle::reset()
{
  position.x = start_x_pos;
  render_states.transform = sf::Transform();
  hitbox.position.x = start_x_pos - width / 2;
}

void Obstacle::draw(sf::RenderTarget &target) const
{
  target.draw(sprite, render_states);
}

void Obstacle::move(float pixels)
{
  position.x += pixels;
  render_states.transform.translate({pixels, 0.f});
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
