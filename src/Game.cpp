#include "Game.h"
#include <iostream>

Game::Game()
    : mWindow(sf::VideoMode(800, 600), "SFML works!")
{
    mWindow.setFramerateLimit(60);

    // Load textures manually before creating the Scene
    mResourceManager.loadTexture("Healer", "/users/trippyy28/Desktop/SFML Playground/src/Assets/Healer.png");
    mResourceManager.loadTexture("Ghost", "/users/trippyy28/Desktop/SFML Playground/src/Assets/ghost.png");
    mResourceManager.loadTexture("M_11", "/users/trippyy28/Desktop/SFML Playground/src/Assets/M_11.png");

    mCurrentScene = std::make_unique<Scene>(mResourceManager);
}

void Game::run()
{
    sf::Clock clock;
    while (mWindow.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            mWindow.close();
        }
        mCurrentScene->handleEvent(event);
    }
}

void Game::update(sf::Time deltaTime)
{
    mCurrentScene->update(deltaTime);
}

void Game::render()
{
    mWindow.clear();
    mCurrentScene->draw(mWindow);
    mWindow.display();
}