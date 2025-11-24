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
    obstacle->reset();
  }
  player.reset();
  for (auto &entity : decorations)
  {
    entity->reset();
  }
  score = 0;
}

void Scene::setPlayerSpeed(short speed)
{
  player.setSpeed(speed);
}

void Scene::addCollidable(std::unique_ptr<Collidable> collidable)
{
  obstacles.push_back(std::move(collidable));
}

void Scene::addDecoration(std::unique_ptr<Entity> entity)
{
  decorations.push_back(std::move(entity));
}

void Scene::setPlayerTexture(std::shared_ptr<sf::Texture> texture_ptr)
{
  player.setTexture(texture_ptr);
}

bool Scene::checkCollisions(double beat)
{
  for (auto &obstacle : obstacles)
  {
    if (Utils::checkCollision(player.getHitbox(), obstacle->getHitbox()))
    {
      if (obstacle->isFatal())
      {
        return true;
      }
      else
      {
        score++;
        return false;
      }
    }
    if (obstacle->getPos() > beat + 1)
      break;
  }
  return false;
}

void Scene::update(float dt)
{
  for (auto &obstacle : obstacles)
  {
    obstacle->update(dt);
  }

  player.update(dt);

  for (auto &entity : decorations)
  {
    entity->update(dt);
  }
}

void Scene::draw(sf::RenderTarget &target) const
{
  for (auto &entity : decorations)
  {
    entity->draw(target);
  }

  player.draw(target);

  for (auto &obstacle : obstacles)
  {
    obstacle->draw(target);
  }
}

int Scene::getScore() const
{
  return score;
}
