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
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            shootBullet(event.mouseButton.x, event.mouseButton.y);
        }
    }
}
void Scene::shootBullet(int mouseX, int mouseY)
{
    // Get the Healer's position
    sf::Vector2f healerPos = mHealer.getSprite().getPosition();

    // Calculate the direction vector from Healer to mouse position
    sf::Vector2f direction = sf::Vector2f(mouseX, mouseY) - healerPos;

    // Normalize the direction vector
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0)
        direction /= length;

    // Set bullet speed
    float bulletSpeed = 500.0f; // Adjust as needed
    sf::Vector2f bulletVelocity = direction * bulletSpeed;

    // Create a new bullet and add it to the vector
    Bullets bullet(
        mResourceManager.getTexture("Bullet"),
        sf::Vector2u(3, 1), // Assuming 3 frames in one row
        0.2f,               // Animation switch time
        bulletVelocity,
        healerPos // Start at the Healer's position
    );

    mBullets.push_back(bullet);
}
void Scene::collisionDetection()
{
    // Check for collisions between entities
    if (mHealer.getSprite().getGlobalBounds().intersects(mFloatingShapes.getGlobalBounds()))
    {

        mHealer.whenCollided();
    }
}

void Scene::playMusic(const std::string &name)
{
    sf::Music &music = mResourceManager.getMusic(name);
    if (music.getStatus() != sf::Music::Playing)
    {
        music.play();
    }
}
void Scene::update(sf::Time deltaTime)
{
    mHealer.update(deltaTime.asSeconds());
    // Update bullets
    for (auto it = mBullets.begin(); it != mBullets.end();)
    {
        it->update(deltaTime.asSeconds());

        // Remove bullet if it goes off-screen
        if (it->isOffScreen())
        {
            it = mBullets.erase(it);
        }
        else
        {
            ++it;
        }
    }
    mFloatingShapes.update(deltaTime.asSeconds());
    // playMusic("BackgroundMusic");
    collisionDetection();
}

void Scene::draw(sf::RenderWindow &window)
{
    mHealer.draw(window);
    mFloatingShapes.draw(window);
    mDjBooth.draw(window);
    // Draw bullets
    for (auto &bullet : mBullets)
    {
        bullet.draw(window);
    }
}