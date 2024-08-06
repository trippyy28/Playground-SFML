#include "Healer.h"

Healer::Healer(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed)
    : animationB(texture, imageCount, switchTime)
{
    this->speed = speed;

    body.setSize(sf::Vector2f(60.0f, 60.0f));
    body.setPosition(100.0f, 10.0f);
    body.setTexture(texture);
    row = 0;
    column = 0;
}

Healer::~Healer()
{
}

void Healer::Update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);
    bool hasMoved = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        hasMoved = true;
        movement.x -= speed * deltaTime;
        row = 3; // Set row to left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        hasMoved = true;
        movement.x += speed * deltaTime;
        row = 1; // Set row to right
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        hasMoved = true;
        movement.y -= speed * deltaTime;
        row = 0; // Set row to up
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        hasMoved = true;
        movement.y += speed * deltaTime;
        row = 2; // Set row to down
    }

    // Boundary checks
    if (body.getPosition().x <= 0)
    {
        body.setPosition(0, body.getPosition().y);
    }
    if (body.getPosition().x >= 800 - body.getSize().x)
    {
        body.setPosition(800 - body.getSize().x, body.getPosition().y);
    }
    if (body.getPosition().y <= 0)
    {
        body.setPosition(body.getPosition().x, 0);
    }
    if (body.getPosition().y >= 600 - body.getSize().y)
    {
        body.setPosition(body.getPosition().x, 600 - body.getSize().y);
    }

    if (hasMoved)
    {
        animationB.update(deltaTime, row, column); // Update animation with deltaTime and row
        body.setTextureRect(animationB.uvRect);
        body.move(movement);
    }
    else
    {
        animationB.update(0, row, 0); // Update animation with deltaTime and row
        body.setTextureRect(animationB.uvRect);
    }
}

void Healer::Draw(sf::RenderWindow &window)
{
    window.draw(body);
}