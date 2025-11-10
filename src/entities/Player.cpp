#include "Player.hpp"
#include <iostream>

Player::Player(EventManager &events) : Entity({250.f, 650.f}, PositionState::Down), events(events)
{
  sprite.setSize({100.f, 100.f});
  sprite.setFillColor(sf::Color::White); /// позже загрузка текстуры
  sprite.setPosition(position);
  state = PositionState::Down;
}

void Player::draw(sf::RenderTarget &target) const { target.draw(sprite); }

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

void Player::update(float dt)
{
  if (events.isSpacePressed())
    jump();
}

sf::FloatRect Player::getHitbox() const
{
  return sprite.getGlobalBounds();
}
