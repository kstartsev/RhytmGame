#include "Scene.hpp"

#include "../utils/Utils.hpp"

Scene::Scene(EventManager &events) : events(events), player(events)
{
}

void Scene::addEntity(Obstacle obstacle)
{
  entities.push_back(obstacle);
}

bool Scene::checkCollisions() const
{
  for (auto &entity : entities)
  {
    if (Utils::checkCollision(player.getHitbox(), entity.getHitbox()))
    {
      return true;
    }
  }
  return false;
}

void Scene::update(float dt)
{
  player.update(dt);
  for (auto &entity : entities)
  {
    entity.update(dt);
  }
}

void Scene::draw(sf::RenderTarget &target) const
{
  player.draw(target);
  for (auto &entity : entities)
  {
    entity.draw(target);
  }
}

void Scene::jumpPlayer()
{
  player.jump();
}
