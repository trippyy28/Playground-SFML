#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);
    sf::Vector2u windowSize = window.getSize();

    std::vector<int> colors = {255, 220, 200};

    std::vector<std::shared_ptr<sf::Shape>> shapes;

    sf::Vector2f rectangleSpeed(1.0f, 1.0f);
    sf::Vector2f circleSpeed(-1.0f, -1.0f);

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
    if (!texture.loadFromFile("/users/trippyy28/Desktop/SFML Playground/src/ghost.png"))
    {
        std::cerr << "Error loading texture" << std::endl;
        return 1;
    }

    rectangle->setTexture(&texture);

    while (window.isOpen())
    {
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
                rectangleShape->move(rectangleSpeed);
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
                circleShape->move(circleSpeed);
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

        window.clear();
        for (const auto &shape : shapes)
        {
            window.draw(*shape);
        }
        window.display();
    }

    return 0;
}
