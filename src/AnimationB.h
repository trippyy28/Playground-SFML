#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class AnimationB
{
public:
    AnimationB(const sf::Texture &texture, sf::Vector2u imageCount, float switchTime);
    ~AnimationB();

    void update(float deltaTime, unsigned int row, unsigned int column);
    sf::Vector2u getImageCount() const
    {
        return imageCount;
    }

public:
    sf::IntRect uvRect;

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;
};