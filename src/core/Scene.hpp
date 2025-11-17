#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "../entities/Entity.hpp"
#include "../entities/Player.hpp"
#include "../entities/Obstacle.hpp"
#include "../entities/Borders.hpp"
#include "EventManager.hpp"
#include <memory>

class Scene
{
private:
  EventManager &events;
  std::vector<Obstacle> obstacles;
  std::vector<std::unique_ptr<Entity>> decorations;
  Player player;
  float time_passed;

public:
  Scene(EventManager &events);
  ~Scene() = default;
  void clear();
  void reset();

  void addObstacle(std::shared_ptr<sf::Texture> texture_ptr, float pos, PositionState state, double pixels_per_second, short speed);
  void addBorders(std::shared_ptr<sf::Texture> texture_ptr, double pixels_per_second);
  void setPlayerTexture(std::shared_ptr<sf::Texture> texture_ptr);
  // void setBordersTexture(std::shared_ptr<sf::Texture> texture_ptr);
  bool checkCollisions() const;
  void update(float dt);
  void draw(sf::RenderTarget &target) const;
};
