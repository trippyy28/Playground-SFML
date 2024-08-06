#pragma once
#include <SFML/Graphics.hpp>
#include "Healer.h"
#include "ResourceManager.h"

class Scene
{
public:
    Scene(ResourceManager &resourceManager);
    void handleEvent(const sf::Event &event);
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow &window);

private:
    Healer mHealer;
    ResourceManager &mResourceManager;
};
