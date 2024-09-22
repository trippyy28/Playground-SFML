#include "AnimationB.h"

AnimationB::AnimationB(const sf::Texture &texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;
    currentImage.y = 0;

    // Get the size of the entire texture
    textureSize = texture.getSize();

    // Calculate the size of each frame (width and height)
    uvRect.width = textureSize.x / imageCount.x;
    uvRect.height = textureSize.y / imageCount.y;
}

AnimationB::~AnimationB()
{
}

void AnimationB::update(float deltaTime, unsigned int row, unsigned int column)
{
    currentImage.y = row; // Set the current row for the animation
    totalTime += deltaTime;

    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++; // Move to the next frame

        if (currentImage.x >= imageCount.x) // If we've gone through all frames, reset
        {
            currentImage.x = 0;
        }
    }

    // Update the uvRect to show the current frame of the sprite sheet
    uvRect.left = currentImage.x * uvRect.width; // Move horizontally in texture
    uvRect.top = currentImage.y * uvRect.height; // Move vertically in texture
}
