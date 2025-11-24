#pragma once

#include "Entity.hpp"
#include "../core/EventManager.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class Player : Collidable
{
private:
  short level_speed = 0;
  EventManager &events;
  sf::RectangleShape sprite;
  float animation_time = 0;
  float jump_time = 0;
  bool is_jump = false;
  bool is_before_jump = true;
  short jump_frame = 0;
  short current_frame = 0;

public:
  Player(EventManager &events, std::shared_ptr<sf::Texture> texture_ptr);
  ~Player() = default;
  void setSpeed(short speed);
  void setTexture(std::shared_ptr<sf::Texture> texture_ptr);

  void reset() override;
  void draw(sf::RenderTarget &target) const override;
  void update(float dt) override;
  void jump();
  sf::FloatRect getHitbox() const override;
  double getPos() const override;
  bool isFatal() override;
};

/**
 * спрайт
 * текстура
 * передвижение только по y
 * управление
 * хитбокс
 */
