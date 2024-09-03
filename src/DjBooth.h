#pragma once
#include "Entity.h"

class DjBooth : public Entity
{
public:
    DjBooth(const sf::Texture &texture, sf::Vector2f position);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;
    ~DjBooth();
};