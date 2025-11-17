#include "Background.hpp"
#include "../utils/Utils.hpp"

using namespace EntitiesParameters;

Background::Background(std::shared_ptr<sf::Texture> texture_ptr, double pixels_per_second, short speed) : Entity({0.f, 0.f}, texture_ptr)
{
  shift_per_second = static_cast<float>(pixels_per_second * speed * 0.1f);
  sprite1.setSize({BACKGROUND_WIDTH, BACKGROUND_HEIGHT});
  sprite1.setPosition({0.f, ROOF_BOTTOM});
  sprite1.setTexture(texture_ptr.get());
  sprite2.setSize({BACKGROUND_WIDTH, BACKGROUND_HEIGHT});
  sprite2.setPosition({DefaultParameters::WINDOW_WIDTH, ROOF_BOTTOM});
  sprite2.setTexture(texture_ptr.get());
  // sprite1.setTextureRect(sf::IntRect({0.f, ROOF_BOTTOM}, {BACKGROUND_WIDTH, BACKGROUND_HEIGHT}));
}

void Background::reset()
{
  sprite1.setPosition({0.f, ROOF_BOTTOM});
  sprite2.setPosition({DefaultParameters::WINDOW_WIDTH, ROOF_BOTTOM});
  position.x = 0.f;
}

void Background::update(float dt)
{
  position.x -= dt * shift_per_second;
  sprite1.move({-dt * shift_per_second, 0.f});
  sprite2.move({-dt * shift_per_second, 0.f});
  if (position.x <= -DefaultParameters::WINDOW_WIDTH)
  {
    sprite1.setPosition({0.f, ROOF_BOTTOM});
    sprite2.setPosition({DefaultParameters::WINDOW_WIDTH, ROOF_BOTTOM});
    position.x = 0.f;
  }
}

void Background::draw(sf::RenderTarget &target) const
{
  target.draw(sprite1);
  target.draw(sprite2);
}
