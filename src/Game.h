#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Scene.h"
#include "ResourceManager.h"

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow mWindow;
    sf::Music mMusic;
    std::unique_ptr<Scene> mCurrentScene; // Use unique_ptr for Scene
                                          // Manage different scenes
    ResourceManager mResourceManager;     // Manage resources like textures and sounds
};