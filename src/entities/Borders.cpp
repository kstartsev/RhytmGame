#include "Borders.hpp"
#include "../utils/Utils.hpp"

using namespace EntitiesParameters;

Borders::Borders(std::shared_ptr<sf::Texture> texture_ptr, double pixels_per_second) : Entity({0.f, 0.f}, texture_ptr),
                                                                                       pixels_per_second(pixels_per_second)
{
  top.setSize({DefaultParameters::WINDOW_WIDTH, ROOF_BOTTOM});
  bottom.setSize({DefaultParameters::WINDOW_WIDTH, ROOF_BOTTOM});
  bottom.setPosition({0.f, FLOOR_TOP});

  top.setTexture(texture_ptr.get());
  bottom.setTexture(texture_ptr.get());
}

void Borders::reset() {}

void Borders::draw(sf::RenderTarget &target) const
{
  target.draw(top);
  target.draw(bottom);
}

void Borders::update(float dt) {}
