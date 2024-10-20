// Scene.h
#pragma once
#include <SFML/Graphics.hpp>
#include "Healer.h"
#include "FloatingShapes.h"
#include "DjBooth.h"
#include "ResourceManager.h"
#include "Bullets.h"
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
    void playMusic(const std::string &name);

private:
    ResourceManager &mResourceManager;
    Healer mHealer;
    FloatingShapes mFloatingShapes;
    // make the bullets vector
    std::vector<Bullets> mBullets;
    sf::Font mFont;
    sf::Text mScoreText;
    DjBooth mDjBooth;
    void shootBullet(int mouseX, int mouseY);
    int mScore = 0;
};