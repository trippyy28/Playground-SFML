#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Healer.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);
    sf::Vector2u windowSize = window.getSize();

    std::vector<int> colors = {255, 220, 200};

    std::vector<std::shared_ptr<sf::Shape>> shapes;

    sf::Vector2f rectangleSpeed(1.0f, 1.0f);
    sf::Vector2f circleSpeed(-1.0f, -1.0f);
    sf::Music music;

    if (!music.openFromFile("/users/trippyy28/Desktop/SFML Playground/src/Assets/Take Me Away (Haji & Emanuel Vox).mp3"))
    {
        std::cerr << "Error loading music" << std::endl;
        return 1;
    }
    music.play();

    // Create a rectangle shape
    auto rectangle = std::make_shared<sf::RectangleShape>(sf::Vector2f(50, 50));
    rectangle->setFillColor(sf::Color(colors[0], colors[1], colors[2]));
    rectangle->setPosition((windowSize.x / 2) - (rectangle->getSize().x / 2), (windowSize.y / 2) - (rectangle->getSize().y / 2));
    shapes.push_back(rectangle);

    // Create a circle shape
    auto circle = std::make_shared<sf::CircleShape>(25); // Radius of 25
    circle->setFillColor(sf::Color(colors[0], colors[1], colors[2]));
    circle->setPosition((windowSize.x / 4) - (circle->getRadius()), (windowSize.y / 4) - (circle->getRadius()));
    shapes.push_back(circle);

    sf::Texture texture;
    if (!texture.loadFromFile("/users/trippyy28/Desktop/SFML Playground/src/Assets/ghost.png"))
    {
        std::cerr << "Error loading texture" << std::endl;
        return 1;
    }

    sf::Texture texture2;
    if (!texture2.loadFromFile("/users/trippyy28/Desktop/SFML Playground/src/Assets/M_11.png"))
    {
        std::cerr << "Error loading texture" << std::endl;
        return 1;
    }

    sf::Texture texture3;
    if (!texture3.loadFromFile("/users/trippyy28/Desktop/SFML Playground/src/Assets/Healer.png"))
    {
        std::cerr << "Error loading texture" << std::endl;
        return 1;
    }

    Healer healer(&texture3, sf::Vector2u(3, 4), 0.2f, 150.0f); // Increased speed for better movement

    rectangle->setTexture(&texture);

    sf::Clock clock;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Update colors
        for (size_t i = 0; i < colors.size(); i++)
        {
            colors[i] = (colors[i] + 1) % 256;
        }

        // Move the shapes
        for (auto &shape : shapes)
        {
            if (auto rectangleShape = std::dynamic_pointer_cast<sf::RectangleShape>(shape))
            {
                rectangleShape->move(rectangleSpeed * deltaTime * 100.0f);
                if (rectangleShape->getGlobalBounds().left <= 0 || rectangleShape->getGlobalBounds().left + rectangleShape->getGlobalBounds().width >= windowSize.x)
                {
                    rectangleSpeed.x = -rectangleSpeed.x;
                }
                if (rectangleShape->getGlobalBounds().top <= 0 || rectangleShape->getGlobalBounds().top + rectangleShape->getGlobalBounds().height >= windowSize.y)
                {
                    rectangleSpeed.y = -rectangleSpeed.y;
                }
            }
            else if (auto circleShape = std::dynamic_pointer_cast<sf::CircleShape>(shape))
            {
                circleShape->move(circleSpeed * deltaTime * 100.0f);
                if (circleShape->getGlobalBounds().left <= 0 || circleShape->getGlobalBounds().left + circleShape->getGlobalBounds().width >= windowSize.x)
                {
                    circleSpeed.x = -circleSpeed.x;
                }
                if (circleShape->getGlobalBounds().top <= 0 || circleShape->getGlobalBounds().top + circleShape->getGlobalBounds().height >= windowSize.y)
                {
                    circleSpeed.y = -circleSpeed.y;
                }
            }

            shape->setFillColor(sf::Color(colors[0], colors[1], colors[2]));
        }
        std::cout << "Healer deltaTime is " << deltaTime << std::endl;
        // character.Update(deltaTime);
        healer.Update(deltaTime);
        window.clear();
        for (const auto &shape : shapes)
        {
            window.draw(*shape);
        }
        // character.Draw(window);
        healer.Draw(window);
        window.display();
    }

    return 0;
}
