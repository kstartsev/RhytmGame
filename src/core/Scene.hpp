#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "../entities/Entity.hpp"
#include "../entities/Player.hpp"
#include "../entities/Obstacle.hpp"



class Scene
{
private:
  std::vector<std::unique_ptr<Entity>> entities;
  Player player;

public:
  Scene();
  ~Scene() = default;

  void update(float dt);
  void draw();
  bool isCollission(const sf::FloatRect& player_hitbox, const sf::FloatRect& obstacle_hitbox) const;
};

// std::vector<std::unique_ptr<Entity>> entities;
