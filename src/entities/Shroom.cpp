#include "Shroom.hpp"
#include "../utils/Utils.hpp"
#include <iostream>
using namespace EntitiesParameters;

Shroom::Shroom(float beat, std::shared_ptr<sf::Texture> texture_ptr, PositionState state, double pixels_per_second, short speed) : beat_pos(beat), Collidable({Utils::beatsToPixels(beat, speed) + PLAYER_XOFFSET, state == PositionState::Down ? SPIKE_YPOS_DOWN : SPIKE_YPOS_UP}, texture_ptr, state), pixels_per_second(pixels_per_second), sprite()
{
  sprite.setSize(SHROOM_SIZE);
  sprite.setOrigin(SHROOM_ORIGIN);
  sprite.setTexture(texture_ptr.get());
  sprite.setTextureRect(sf::IntRect({0, 0}, {80, 80}));
  if (state == PositionState::Down)
  {
    sprite.setPosition({position.x, SHROOM_YPOS_DOWN});
    position.y = SHROOM_YPOS_DOWN;
  }
  else
  {
    sprite.setPosition({position.x, SHROOM_YPOS_UP});
    position.y = SHROOM_YPOS_UP;
    sprite.setScale({1.f, -1.f});
  }
  hitbox = sprite.getGlobalBounds();
}

void Shroom::reset()
{
  sprite.setPosition(position);
  if (state == PositionState::Down)
  {
    sprite.setScale({1.f, 1.f});
  }
  else
  {
    sprite.setScale({1.f, -1.f});
  }
  hitbox = sprite.getGlobalBounds();
  is_collected = false;
}

void Shroom::draw(sf::RenderTarget &target) const
{
  target.draw(sprite);
}

void Shroom::update(float dt)
{
  sprite.move({-dt * static_cast<float>(pixels_per_second), 0.f});
  hitbox.position.x -= dt * pixels_per_second;
}

sf::FloatRect Shroom::getHitbox() const
{
  if(is_collected) return NULL_HITBOX;
  return hitbox;
}

double Shroom::getPos() const
{
  return beat_pos;
}

bool Shroom::isFatal()
{
  sprite.setScale({0.f, 0.f});
  is_collected = true;
  return false;
}
