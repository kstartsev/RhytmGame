#include "Player.hpp"
#include "../utils/Utils.hpp"
#include <iostream>
#include <cmath>

using namespace EntitiesParameters;

Player::Player(EventManager &events, std::shared_ptr<sf::Texture> texture_ptr) : Collidable(DEFAULT_PLAYER_POS, texture_ptr, PositionState::Down), events(events)
{
  sprite.setSize(DEFAULT_PLAYER_SIZE);
  sprite.setPosition(position);
  state = PositionState::Down;
  sprite.setTexture(texture_ptr.get());
}

void Player::setSpeed(short speed)
{
  level_speed = speed;
}

void Player::setTexture(std::shared_ptr<sf::Texture> texture_ptr)
{
  sprite.setTexture(texture_ptr.get());
  sprite.setTextureRect(sf::IntRect({0, 0}, {100, 100}));
}

void Player::draw(sf::RenderTarget &target) const { target.draw(sprite); }

void Player::jump()
{
  if (state == PositionState::Down)
  {
    sprite.move(PLAYER_UP_SHIFT);
    state = PositionState::Up;
    sprite.setScale({1.f, -1.f});
  }
  else
  {
    sprite.move(PLAYER_DOWN_SHIFT);
    state = PositionState::Down;
    sprite.setScale({1.f, 1.f});
  }
  is_jump = false;
}

void Player::reset()
{
  if (state == PositionState::Up)
  {
    sprite.move(PLAYER_DOWN_SHIFT);
    state = PositionState::Down;
    sprite.setScale({1.f, 1.f});
  }
  animation_time = 0;
  current_frame = 0;
}

void Player::update(float dt)
{
  if (!is_jump && events.isSpacePressed())
  {
    is_jump = true;
    jump_frame = 0;
    jump_time = 0;
    is_before_jump = true;
  }
  if (!is_jump)
  {
    animation_time += dt * level_speed;
    if (animation_time >= TIME_FOR_ANIMATION_FRAME)
    {
      animation_time = 0;
      current_frame = (current_frame + 1) % 10;
      sprite.setTextureRect(sf::IntRect({100 * current_frame, 0}, {100, 100}));
    }
    return;
  }
  jump_time += dt;

  if (jump_time >= TIME_FOR_JUMP_FRAME)
  {
    jump_time = 0;

    if (is_before_jump)
    {
      jump_frame++;

      if (jump_frame >= JUMP_FRAMES_COUNT - 1)
      {
        jump();
        is_before_jump = false;
      }
    }
    else
    {
      jump_frame--;

      if (jump_frame <= 0)
      {
        jump_frame = 0;
        is_jump = false;
      }
    }
    sprite.setTextureRect(sf::IntRect({100 * jump_frame, 100}, {100, 100}));
  }
}

sf::FloatRect Player::getHitbox() const
{
  return sprite.getGlobalBounds();
}
