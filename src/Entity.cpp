#include "Entity.h"

Entity::Entity(const sf::Texture &texture, sf::Vector2f position)
{
    mSprite.setTexture(texture);
    mSprite.setPosition(position);
}

void Entity::draw(sf::RenderWindow &window)
{
    window.draw(mSprite);
}
