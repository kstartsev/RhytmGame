#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "../entities/Entity.hpp"
#include "../entities/Player.hpp"
#include "../entities/Obstacle.hpp"
#include "EventManager.hpp"
#include <memory>

class Scene
{
private:
  EventManager &events;
  std::vector<Obstacle> obstacles;
  Player player;
  float time_passed;

public:
  Scene(EventManager &events);
  ~Scene() = default;
  void clear();
  void reset();

  void addObstacle(std::shared_ptr<sf::Texture> texture_ptr, float pos, PositionState state, double pixels_per_second, short speed);
  void setPlayerTexture(std::shared_ptr<sf::Texture> texture_ptr);
  bool checkCollisions() const;
  void update(float dt);
  void draw(sf::RenderTarget &target) const;
};
