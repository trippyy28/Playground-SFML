#include "Scene.h"
#include <iostream>
Scene::Scene(ResourceManager &resourceManager)
    : mResourceManager(resourceManager),
      mHealer(resourceManager.getTexture("Healer"), sf::Vector2u(3, 4), 0.2f, 150.0f, sf::Vector2f(100.0f, 100.0f)),
      mFloatingShapes(resourceManager.getTexture("Ghost"), sf::Vector2f(400.0f, 400.0f)),
      mDjBooth(resourceManager.getTexture("DjBooth"), sf::Vector2f(50.0f, 50.0f))
{

    std::cout << "Scene initialized with Healer texture" << std::endl;
}

void Scene::handleEvent(const sf::Event &event)
{
    // Handle input events for the scene
}
void Scene::collisionDetection()
{
    // Check for collisions between entities
    if (mHealer.getSprite().getGlobalBounds().intersects(mFloatingShapes.getGlobalBounds()))
    {

        mHealer.whenCollided();
    }
}
void Scene::update(sf::Time deltaTime)
{
    mHealer.update(deltaTime.asSeconds());
    mFloatingShapes.update(deltaTime.asSeconds());
    collisionDetection();
}

void Scene::draw(sf::RenderWindow &window)
{
    mHealer.draw(window);
    mFloatingShapes.draw(window);
    mDjBooth.draw(window);
}