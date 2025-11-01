#include <SFML/Graphics.hpp>

class Entity
{
private:
    sf::Vector2f position = {0, 0};

public:
    virtual Entity(sf::Vector2f pos) : position(pos) {};
    virtual ~Entity() = default;
    virtual void update();
};
