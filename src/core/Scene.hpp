#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "../entities/Entity.hpp"
#include "../entities/Player.hpp"
#include "../entities/Obstacle.hpp"
#include "EventManager.hpp"

class Scene
{
private:
  EventManager &events;
  std::vector<Obstacle> entities;
  Player player;

  void jumpPlayer();

public:
  Scene(EventManager &events);
  ~Scene() = default;

  void addEntity(Obstacle entity);
  bool checkCollisions() const;
  void update(float dt);
  void draw(sf::RenderTarget &target) const;

};

// std::vector<std::unique_ptr<Entity>> entities;
