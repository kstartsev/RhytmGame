#include "Borders.hpp"
#include "../utils/Utils.hpp"

using namespace EntitiesParameters;

Borders::Borders(std::shared_ptr<sf::Texture> texture_ptr, double pixels_per_second) : Entity({0.f, 0.f}, texture_ptr)
{
  shift_per_second = static_cast<float>(pixels_per_second);
  top1.setSize({DefaultParameters::WINDOW_WIDTH, ROOF_BOTTOM});
  bottom1.setSize({DefaultParameters::WINDOW_WIDTH, ROOF_BOTTOM});
  bottom1.setPosition({0.f, FLOOR_TOP + ROOF_BOTTOM});
  bottom1.setScale({1.f, -1.f});

  top2.setSize({DefaultParameters::WINDOW_WIDTH, ROOF_BOTTOM});
  bottom2.setSize({DefaultParameters::WINDOW_WIDTH, ROOF_BOTTOM});
  top2.setPosition({DefaultParameters::WINDOW_WIDTH, 0.f});
  bottom2.setPosition({DefaultParameters::WINDOW_WIDTH, FLOOR_TOP + ROOF_BOTTOM});
  bottom2.setScale({1.f, -1.f});

  top1.setTexture(texture_ptr.get());
  bottom1.setTexture(texture_ptr.get());

  top2.setTexture(texture_ptr.get());
  bottom2.setTexture(texture_ptr.get());
}

void Borders::reset()
{
  top1.setPosition({0.f, 0.f});
  bottom1.setPosition({0.f, FLOOR_TOP + ROOF_BOTTOM});

  top2.setPosition({DefaultParameters::WINDOW_WIDTH, 0.f});
  bottom2.setPosition({DefaultParameters::WINDOW_WIDTH, FLOOR_TOP + ROOF_BOTTOM});

  position.x = 0.f;
}

void Borders::draw(sf::RenderTarget &target) const
{
  target.draw(top1);
  target.draw(bottom1);
  target.draw(top2);
  target.draw(bottom2);
}

void Borders::update(float dt)
{
  position.x -= dt * shift_per_second;
  top1.move({-dt * shift_per_second, 0.f});
  bottom1.move({-dt * shift_per_second, 0.f});

  top2.move({-dt * shift_per_second, 0.f});
  bottom2.move({-dt * shift_per_second, 0.f});

  if (position.x <= -DefaultParameters::WINDOW_WIDTH)
  {
    top1.setPosition({0.f, 0.f});
    bottom1.setPosition({0.f, FLOOR_TOP + ROOF_BOTTOM});

    top2.setPosition({DefaultParameters::WINDOW_WIDTH, 0.f});
    bottom2.setPosition({DefaultParameters::WINDOW_WIDTH, FLOOR_TOP + ROOF_BOTTOM});

    position.x = 0.f;
  }
}
