#include "DjBooth.h"

DjBooth::DjBooth(const sf::Texture &texture, sf::Vector2f position)
    : Entity(texture, position)
{
}

DjBooth::~DjBooth() = default;

void DjBooth::update(float deltaTime)
{
}

void DjBooth::draw(sf::RenderWindow &window)
{
    Entity::draw(window);
}