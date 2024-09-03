// FloatingShapes.h
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Entity.h"

class FloatingShapes : public Entity
{
public:
    FloatingShapes(const sf::Texture &texture, sf::Vector2f position);

    void draw(sf::RenderWindow &window) override;
    void update(float deltaTime) override;
    sf::FloatRect getGlobalBounds() const; // Add this method

private:
    std::vector<std::shared_ptr<sf::Shape>> shapes;
    sf::Vector2f rectangleSpeed = sf::Vector2f(1.0f, 1.0f);
    sf::Vector2f circleSpeed = sf::Vector2f(1.0f, 1.0f);
    std::vector<int> colors = {255, 220, 200};
};