#include "Entity.hpp"
#include <SFML/Graphics.hpp>

enum class PositionState
{
    Up,
    Down
};

class Player : Entity
{
private:
    PositionState state;
    sf::Texture texture;
    sf::RectangleShape player_shape({100.f, 100.f});

public:
    Player(sf::Vector2f pos, sf::Texture texture, PositionState state) {};
    void update() override;
    void jump();
    sf::FloatRect getHitbox() const;
};

/**
 * спрайт
 * текстура
 * передвижение только по y
 * управление
 * хитбокс
 */