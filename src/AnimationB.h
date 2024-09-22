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
    sf::IntRect uvRect; // This defines the part of the texture to show

private:
    sf::Vector2u imageCount;   // Number of images in x and y
    sf::Vector2u currentImage; // Current image/frame being shown

    float totalTime;  // Accumulated time to switch frames
    float switchTime; // Time per frame switch

    // Store texture size to calculate frame sizes dynamically
    sf::Vector2u textureSize;
};
