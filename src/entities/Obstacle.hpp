#pragma once

#include "Entity.hpp"
#include <SFML/Graphics.hpp>

class Obstacle : Entity
{
private:
  sf::Texture texture;
  sf::VertexArray shape;
  sf::Transform transform;
  sf::FloatRect hitbox;
  double pixels_per_second;

public:
  Obstacle(float pos, PositionState state, double pixels_per_second, float width = 100.f, float height = 100.f);
  void draw(sf::RenderTarget &target) const override;
  void update(float dt) override;
  sf::CircleShape &returnForDraw();
  void move(float pixels);
  sf::FloatRect getHitbox() const;
};

/**
 * форма(или спрайт)
 * отрисовка
 * передвижение только по x
 * коллизии/хитбокс
 */
