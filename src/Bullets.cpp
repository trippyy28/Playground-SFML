#include "Bullets.h"

Bullets::Bullets(const sf::Texture &texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f mSpeed, sf::Vector2f position)
    : Entity(texture, position), mAnimation(texture, imageCount, switchTime), mSpeed(mSpeed)
{
    mRow = 0;
    mSprite.setTexture(texture);
    mSprite.setPosition(position);
    mSprite.setTextureRect(mAnimation.uvRect);
    mSprite.setScale(5.0f, 5.0f);

    // Add the bullet to the vector
}

Bullets::~Bullets() = default;

void Bullets::update(float deltaTime)
{
    mAnimation.update(deltaTime, 0, 0);
    mSprite.move(mSpeed * deltaTime);
    mSprite.setTextureRect(mAnimation.uvRect);
}
sf::Sprite Bullets::getSprite()
{
    return mSprite;
}

bool Bullets::isOffScreen() const
{
    sf::Vector2f position = mSprite.getPosition();
    return (position.x < 0 || position.x > 800 || position.y < 0 || position.y > 600);
}
void Bullets::draw(sf::RenderWindow &window)
{
    Entity::draw(window);
}