#include "Player.hpp"
#include "../utils/Utils.hpp"
#include <iostream>

using namespace EntitiesParameters;

Player::Player(EventManager &events, std::shared_ptr<sf::Texture> texture_ptr) : Collidable(DEFAULT_PLAYER_POS, texture_ptr, PositionState::Down), events(events)
{
  sprite.setSize(DEFAULT_PLAYER_SIZE);
  sprite.setTexture(texture_ptr.get());
  sprite.setTextureRect(sf::IntRect({0, 0}, {100, 100}));
  sprite.setPosition(position);
  state = PositionState::Down;
}

void Player::setTexture(std::shared_ptr<sf::Texture> texture_ptr)
{
  this->texture_ptr = texture_ptr;
  render_states.texture = texture_ptr.get();
}

void Player::draw(sf::RenderTarget &target) const { target.draw(sprite, render_states); }

void Player::jump()
{
  if (state == PositionState::Down)
  {
    sprite.move(PLAYER_UP_SHIFT);
    state = PositionState::Up;
  }
  else
  {
    sprite.move(PLAYER_DOWN_SHIFT);
    state = PositionState::Down;
  }
}

void Player::reset()
{
  if (state == PositionState::Up)
  {
    sprite.move(PLAYER_DOWN_SHIFT);
    state = PositionState::Down;
  }
}

void Player::update(float dt)
{
  if (events.isSpacePressed())
    jump();
}

sf::FloatRect Player::getHitbox() const
{
  return sprite.getGlobalBounds();
}
