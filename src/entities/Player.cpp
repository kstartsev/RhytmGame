#include "Player.hpp"

Player::Player() : Entity({250.f, 650.f}, PositionState::Down)
{
  shape.setSize({100.f, 100.f});
  shape.setFillColor(sf::Color::White); /// позже загрузка текстуры
  shape.setPosition(position);
  state = PositionState::Down;
}

void Player::draw(sf::RenderTarget &target) const { target.draw(shape); }

void Player::jump()
{
  if (state == PositionState::Down)
  {
    shape.move({0.f, -500.f});
    state = PositionState::Up;
  }
  else
  {
    shape.move({0.f, 500.f});
    state = PositionState::Down;
  }
}

void Player::update(float dt) {}

sf::FloatRect Player::getHitbox() const { return shape.getGlobalBounds(); }
