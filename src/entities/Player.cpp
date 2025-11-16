#include "Player.hpp"
#include <iostream>

#define DEFAULT_PLAYER_POS {250.f, 650.f}

Player::Player(EventManager &events, std::shared_ptr<sf::Texture> texture_ptr) : Collidable(DEFAULT_PLAYER_POS, *texture_ptr, PositionState::Down), events(events), texture_ptr(texture_ptr)
{
  sprite.setSize({100.f, 100.f});
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
    sprite.move({0.f, -500.f});
    state = PositionState::Up;
  }
  else
  {
    sprite.move({0.f, 500.f});
    state = PositionState::Down;
  }
}

void Player::reset()
{
  if (state == PositionState::Up)
  {
    sprite.move({0.f, 500.f});
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
