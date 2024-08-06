#include "AnimationB.h"

AnimationB::AnimationB(sf::Texture *texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;
    currentImage.y = 0;

    uvRect.width = 48 / float(this->imageCount.x);
    uvRect.height = 64 / float(this->imageCount.y);
}

AnimationB::~AnimationB()
{
}

void AnimationB::update(float deltaTime, unsigned int row, unsigned int column)
{
    currentImage.y = row;
    totalTime += deltaTime;

    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;

        if (currentImage.x >= imageCount.x)
        {
            currentImage.x = 0;
        }
    }

    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
}
