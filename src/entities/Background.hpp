#include "Entity.hpp"

class Background : public Entity
{
private:
  float shift_per_second;
  sf::RectangleShape sprite1;
  sf::RectangleShape sprite2;

public:
  Background(std::shared_ptr<sf::Texture> texture_ptr, double pixels_per_second, short speed);
  ~Background() noexcept override = default;

  void reset() override;
  void draw(sf::RenderTarget &target) const override;
  void update(float dt) override;
};
