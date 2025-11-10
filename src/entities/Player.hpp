#pragma once

#include "Entity.hpp"
#include "../core/EventManager.hpp"
#include <SFML/Graphics.hpp>

class Player : Entity
{
private:
  EventManager &events;
  sf::Texture texture;
  sf::RectangleShape sprite;

public:
  Player(EventManager &events);
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
