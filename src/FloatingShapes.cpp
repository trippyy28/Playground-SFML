// FloatingShapes.cpp
#include "FloatingShapes.h"

FloatingShapes::FloatingShapes(const sf::Texture &texture, sf::Vector2f position) : Entity(texture, position)
{

    auto rectangleShape = std::make_shared<sf::RectangleShape>(sf::Vector2f(100.0f, 100.0f));
    rectangleShape->setTexture(&texture);
    rectangleShape->setPosition(position);
    shapes.push_back(rectangleShape);

    auto circleShape = std::make_shared<sf::CircleShape>(50.0f);
    circleShape->setPosition(position + sf::Vector2f(200.0f, 0.0f));
    shapes.push_back(circleShape);
}

void FloatingShapes::draw(sf::RenderWindow &window)
{
    for (const auto &shape : shapes)
    {
        window.draw(*shape);
    }
}
sf::FloatRect FloatingShapes::getGlobalBounds() const
{
    if (shapes.empty())
        return sf::FloatRect();

    sf::FloatRect bounds = shapes.front()->getGlobalBounds();
    for (const auto &shape : shapes)
    {
        sf::FloatRect shapeBounds = shape->getGlobalBounds();
        float left = std::min(bounds.left, shapeBounds.left);
        float top = std::min(bounds.top, shapeBounds.top);
        float right = std::max(bounds.left + bounds.width, shapeBounds.left + shapeBounds.width);
        float bottom = std::max(bounds.top + bounds.height, shapeBounds.top + shapeBounds.height);

        bounds.left = left;
        bounds.top = top;
        bounds.width = right - left;
        bounds.height = bottom - top;
    }
    return bounds;
}
void FloatingShapes::update(float deltaTime)
{
    for (const auto &shape : shapes)
    {
        if (auto rectangleShape = std::dynamic_pointer_cast<sf::RectangleShape>(shape))
        {
            rectangleShape->move(rectangleSpeed * deltaTime * 100.0f);
            if (rectangleShape->getGlobalBounds().left <= 0 || rectangleShape->getGlobalBounds().left + rectangleShape->getGlobalBounds().width >= 800)
            {
                rectangleSpeed.x = -rectangleSpeed.x;
            }
            if (rectangleShape->getGlobalBounds().top <= 0 || rectangleShape->getGlobalBounds().top + rectangleShape->getGlobalBounds().height >= 600)
            {
                rectangleSpeed.y = -rectangleSpeed.y;
            }
        }
        else if (auto circleShape = std::dynamic_pointer_cast<sf::CircleShape>(shape))
        {
            circleShape->move(circleSpeed * deltaTime * 100.0f);
            if (circleShape->getGlobalBounds().left <= 0 || circleShape->getGlobalBounds().left + circleShape->getGlobalBounds().width >= 800)
            {
                circleSpeed.x = -circleSpeed.x;
            }
            if (circleShape->getGlobalBounds().top <= 0 || circleShape->getGlobalBounds().top + circleShape->getGlobalBounds().height >= 600)
            {
                circleSpeed.y = -circleSpeed.y;
            }
        }
        for (auto &color : colors)
        {
            color = (color + 1) % 256;
        }
        shape->setFillColor(sf::Color(colors[0], colors[1], colors[2]));
    }
}