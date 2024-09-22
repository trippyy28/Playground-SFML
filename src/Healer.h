#pragma once
#include "Entity.h"
#include "AnimationB.h"
#include <iostream>
class Healer : public Entity
{
public:
    Healer(const sf::Texture &texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position);
    ~Healer();

    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;

    void whenCollided();
    sf::Sprite getSprite(); // Get sprite for collision detection

private:
    AnimationB mAnimation;
    unsigned int mRow;
    float mSpeed;
};
