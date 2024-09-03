// Scene.h
#pragma once
#include <SFML/Graphics.hpp>
#include "Healer.h"
#include "FloatingShapes.h"
#include "DjBooth.h"
#include "ResourceManager.h"
#include <iostream>
#include <string>

class Scene
{
public:
    Scene(ResourceManager &resourceManager);

    void draw(sf::RenderWindow &window);
    void update(sf::Time deltaTime);
    void handleEvent(const sf::Event &event);
    void collisionDetection();

private:
    ResourceManager &mResourceManager;
    Healer mHealer;
    FloatingShapes mFloatingShapes;
    DjBooth mDjBooth;
};