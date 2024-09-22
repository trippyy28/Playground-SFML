#include "Game.h"
#include <iostream>

Game::Game()
    : mWindow(sf::VideoMode(800, 600), "SFML works!"),
      menu(800, 600)
{
    mWindow.setFramerateLimit(60);

    // Load textures manually before creating the Scene
    mResourceManager.loadTexture("Healer", "/users/trippyy28/Desktop/SFML Playground/src/Assets/Healer.png");
    mResourceManager.loadTexture("Ghost", "/users/trippyy28/Desktop/SFML Playground/src/Assets/ghost.png");
    mResourceManager.loadTexture("M_11", "/users/trippyy28/Desktop/SFML Playground/src/Assets/M_11.png");
    mResourceManager.loadTexture("Soldier", "/users/trippyy28/Desktop/SFML Playground/src/Assets/Soldier/Soldier.png");
    mResourceManager.loadTexture("Bullet", "/users/trippyy28/Desktop/SFML Playground/src/Assets/shoot.png");
    mResourceManager.loadMusic("BackgroundMusic", "/users/trippyy28/Desktop/SFML Playground/src/Assets/DJ Jeroenski - Back Once Again (Lee Mortimer Remix).mp3");
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
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            if (showMenu)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    menu.moveUp();
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    menu.moveDown();
                }
                else if (event.key.code == sf::Keyboard::Enter)
                {
                    switch (menu.getPressedItem())
                    {
                    case 0: // Start Game
                        showMenu = false;
                        break;
                    case 1: // Settings
                        // Handle settings
                        break;
                    case 2: // Exit
                        mWindow.close();
                        break;
                    }
                }
            }
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    mCurrentScene->update(deltaTime);
}

void Game::render()
{
    mWindow.clear();
    if (showMenu)
    {
        menu.draw(mWindow);
    }
    else
    {
        mCurrentScene->draw(mWindow);
    }
    mWindow.display();
}