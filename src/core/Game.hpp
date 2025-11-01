/**
 * @file Game.hpp
 * @brief Header file for the Game class.
 */

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/**
 * @class Game
 * @brief Class for work with all game engine.
 */
class Game
{
private:
    sf::RenderWindow &window; ///< Game window.
public:
    /**
     * @brief Game class constructor
     * @param window Game window.
     */
    explicit Game(sf::RenderWindow &window);

    /**
     * @brief Runs game
     * 
     * Initializes all entities, map etc.
     */
    void run();
};
