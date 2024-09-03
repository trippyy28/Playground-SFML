#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity(const sf::Texture &texture, sf::Vector2f position);
    virtual ~Entity() = default;

    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow &window);

protected:
    sf::Sprite mSprite;
};
