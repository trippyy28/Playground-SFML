#include "Healer.h"

Healer::Healer(const sf::Texture &texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position)
    : Entity(texture, position), mAnimation(texture, imageCount, switchTime), mSpeed(speed)
{
    mRow = 0;
    mSprite.setTextureRect(mAnimation.uvRect);
    mSprite.setScale(5.0f, 5.0f);
}

Healer::~Healer() = default;

void Healer::update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement.x -= mSpeed * deltaTime;
        mRow = 3; // Set row to left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += mSpeed * deltaTime;
        mRow = 1; // Set row to right
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        movement.y -= mSpeed * deltaTime;
        mRow = 0; // Set row to up
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        movement.y += mSpeed * deltaTime;
        mRow = 2; // Set row to down
    }

    // Boundary checks
    if (mSprite.getPosition().x + movement.x < 0)
    {
        movement.x = -mSprite.getPosition().x;
    }
    if (mSprite.getPosition().x + movement.x > 800 - mSprite.getGlobalBounds().width)
    {
        movement.x = 800 - mSprite.getGlobalBounds().width - mSprite.getPosition().x;
    }
    if (mSprite.getPosition().y + movement.y < 0)
    {
        movement.y = -mSprite.getPosition().y;
    }
    if (mSprite.getPosition().y + movement.y > 600 - mSprite.getGlobalBounds().height)
    {
        movement.y = 600 - mSprite.getGlobalBounds().height - mSprite.getPosition().y;
    }

    if (movement.x != 0.0f || movement.y != 0.0f)
    {
        mAnimation.update(deltaTime, mRow, 0); // Update animation with deltaTime and row
        mSprite.setTextureRect(mAnimation.uvRect);
        mSprite.move(movement);
    }
    else
    {
        // mAnimation.update(0, mRow, 0); // Update animation with deltaTime and row
        mSprite.setTextureRect(mAnimation.uvRect);
    }
}

sf::Sprite Healer::getSprite()
{
    return mSprite;
}

void Healer::whenCollided()
{
    mSprite.setPosition(100.0f, 100.0f);
    // std::cout << "Healer collided with FloatingShapes" << std::endl;
}

void Healer::draw(sf::RenderWindow &window)
{
    Entity::draw(window);
}