#pragma once

#include "Entity.hpp"
#include <SFML/Graphics.hpp>

class Player : Entity
{
private:
  sf::Texture texture;
  sf::RectangleShape shape;

public:
  Player();
  void draw(sf::RenderTarget &target) const override;
  void update(float dt) override;
  void jump();
  sf::FloatRect getHitbox() const;
};

/**
 * спрайт
 * текстура
 * передвижение только по y
 * управление
 * хитбокс
 */
