#pragma once

#include "Entity.hpp"
#include "../core/EventManager.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class Player : Collidable
{
private:
  EventManager &events;
  sf::RectangleShape sprite;

public:
  Player(EventManager &events, std::shared_ptr<sf::Texture> texture_ptr);
  ~Player() = default;
  void setTexture(std::shared_ptr<sf::Texture> texture_ptr);

  void reset() override;
  void draw(sf::RenderTarget &target) const override;
  void update(float dt) override;
  void jump();
  sf::FloatRect getHitbox() const override;
};

/**
 * спрайт
 * текстура
 * передвижение только по y
 * управление
 * хитбокс
 */
