#include "Scene.hpp"

#include "../utils/Utils.hpp"
#include <iostream>

Scene::Scene(EventManager &events) : events(events), player(events, std::make_shared<sf::Texture>()) {}

void Scene::clear()
{
  obstacles.clear();
  player.reset();
}

void Scene::reset()
{
  for (auto &obstacle : obstacles)
  {
    obstacle.reset();
  }
  player.reset();
}

void Scene::addObstacle(std::shared_ptr<sf::Texture> texture_ptr, float pos, PositionState state, double pixels_per_second, short speed)
{
  obstacles.push_back(Obstacle(pos, texture_ptr, state, pixels_per_second, speed));
}

void Scene::setPlayerTexture(std::shared_ptr<sf::Texture> texture_ptr)
{
  player.setTexture(texture_ptr);
}

bool Scene::checkCollisions() const
{
  for (auto &obstacle : obstacles)
  {
    if (Utils::checkCollision(player.getHitbox(), obstacle.getHitbox()))
    {
      return true;
    }
  }
  return false;
}

void Scene::update(float dt)
{
  player.update(dt);
  for (auto &obstacle : obstacles)
  {
    obstacle.update(dt);
  }
}

void Scene::draw(sf::RenderTarget &target) const
{
  player.draw(target);
  for (auto &obstacle : obstacles)
  {
    obstacle.draw(target);
  }
}
