#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Scene.h"
#include "ResourceManager.h"
#include "Menu.h"
class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    int colors[3] = {99, 155, 255};

    sf::Color mBackgroundColor;
    sf::RenderWindow mWindow;
    std::unique_ptr<Scene> mCurrentScene; // Use unique_ptr for Scene                                // Manage different scenes
    ResourceManager mResourceManager;     // Manage resources like textures and sounds
    Menu menu;
    bool showMenu = true;
};