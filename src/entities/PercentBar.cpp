#include "PercentBar.hpp"

#include "../utils/Utils.hpp"
#include <cmath>

using namespace EntitiesParameters;

PercentBar::PercentBar(const sf::Font &font, std::string line, double duration) : Entity({0, 0}, nullptr),
                                                                                  text(font),
                                                                                  duration(duration)
{
  // Прямая инициализация текста
  text.setFont(font); // Критически важно!
  text.setString(line);
  text.setCharacterSize(25);
  text.setFillColor(sf::Color::Black);

  // Остальной код остается без изменений
  text.setOrigin({text.getGlobalBounds().size.x, 0.f});
  text.setPosition({X_BAR_POS, INNER_OUTER_DIFF});

  inner_bar.setSize({BAR_WIDTH - INNER_OUTER_DIFF, BAR_HEIGHT});
  outer_bar.setSize({BAR_WIDTH + INNER_OUTER_DIFF, BAR_HEIGHT + INNER_OUTER_DIFF});

  inner_bar.setOrigin({0.f, BAR_HEIGHT / 2});
  outer_bar.setOrigin({(BAR_WIDTH + INNER_OUTER_DIFF) / 2, (BAR_HEIGHT + INNER_OUTER_DIFF) / 2});

  inner_bar.setPosition({X_BAR_POS - (BAR_WIDTH + INNER_OUTER_DIFF) / 2, Y_BAR_POS});
  outer_bar.setPosition({X_BAR_POS, Y_BAR_POS});

  inner_bar.setFillColor(sf::Color::White);
  outer_bar.setFillColor(sf::Color::Black);
  outer_bar.setOutlineColor(sf::Color::White);
  outer_bar.setOutlineThickness(INNER_OUTER_DIFF / 2);

  inner_bar.setScale({0.f, 1.f});
}

void PercentBar::reset()
{
  time = 0;
  inner_bar.setScale({0.f, 1.f});
  text.setString(std::to_string(0) + "%");
}

void PercentBar::update(float dt)
{
  time += dt;
  float ratio = time / duration;
  inner_bar.setScale({ratio, 1.f});
  text.setString(std::to_string(static_cast<int>(std::floor(ratio * 100))) + "%");
  text.setOrigin({text.getLocalBounds().size.x / 2, 0.f});
}

void PercentBar::draw(sf::RenderTarget &target) const
{
  target.draw(outer_bar);
  target.draw(inner_bar);
  target.draw(text);
}
