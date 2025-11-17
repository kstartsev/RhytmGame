#include "Borders.hpp"
#include "../utils/Utils.hpp"

using namespace EntitiesParameters;

Borders::Borders(std::shared_ptr<sf::Texture> texture_ptr, double pixels_per_second) : Entity({0.f, 0.f}, texture_ptr),
                                                                                       pixels_per_second(pixels_per_second)
{
  // top = sf::RectangleShape({DefaultParameters::WINDOW_WIDTH, ROOF_BOTTOM});
  // bottom = sf::RectangleShape({DefaultParameters::WINDOW_WIDTH, FLOOR_BOTTOM - FLOOR_TOP});
  top.setSize({DefaultParameters::WINDOW_WIDTH, ROOF_BOTTOM});
  bottom.setSize({DefaultParameters::WINDOW_WIDTH, ROOF_BOTTOM});
  bottom.setPosition({FLOOR_TOP, 0.f});
  render_states.texture = texture_ptr.get();
}

void Borders::reset() {}

void Borders::draw(sf::RenderTarget &target) const
{
  target.draw(bottom, render_states);
  target.draw(top,render_states);
}

void Borders::update(float dt) {}

void Borders::setTexture(std::shared_ptr<sf::Texture> texture_ptr)
{
  texture_ptr->setRepeated(true);
  this->texture_ptr = texture_ptr;
  render_states.texture = texture_ptr.get();
}
