#include "Player.hpp"

Player::Player(sf::Vector2f pos, sf::Texture texture, PositionState state) : Entity(pos), texture(texture), state(state)
{
    player_shape.setColor(sf::Color::White); /// позже загрузка текстуры
    if (state == PositionState::Down)
    {
        player_shape.setPosition({250.f, 650.f});
    }
    else
    {
        player_shape.setPosition({250.f, 150.f});
    }
}

void Player::jump()
{
    if (state == PositionState::Down)
    {
        player_shape.move({0.f, -500.f});
    }
    else
    {
        player_shape.move({0.f, 500.f});
    }
}

sf::FloatRect Player::getHitbox()
{
    return player_shape.getGlobalBounds();
}