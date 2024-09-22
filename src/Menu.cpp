#include "Menu.h"

Menu::Menu(float width, float height) : selectedItemIndex(0)
{
    if (!font.loadFromFile("/users/trippyy28/Desktop/SFML Playground/src/Assets/font.ttf"))
    {
        // Handle error
    }

    sf::Text startGame("Start Game", font, 24);
    startGame.setPosition(sf::Vector2f(width / 2, height / (3 + 1) * 1));
    menuItems.push_back(startGame);

    sf::Text settings("Settings", font, 24);
    settings.setPosition(sf::Vector2f(width / 2, height / (3 + 1) * 2));
    menuItems.push_back(settings);

    sf::Text exit("Exit", font, 24);
    exit.setPosition(sf::Vector2f(width / 2, height / (3 + 1) * 3));
    menuItems.push_back(exit);

    update();
}

void Menu::draw(sf::RenderWindow &window)
{
    for (const auto &item : menuItems)
    {
        window.draw(item);
    }
}

void Menu::moveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        selectedItemIndex--;
        update();
    }
}

void Menu::moveDown()
{
    if (selectedItemIndex + 1 < menuItems.size())
    {
        selectedItemIndex++;
        update();
    }
}

void Menu::update()
{
    for (int i = 0; i < menuItems.size(); i++)
    {
        if (i == selectedItemIndex)
        {
            menuItems[i].setFillColor(sf::Color::Red);
        }
        else
        {
            menuItems[i].setFillColor(sf::Color::White);
        }
    }
}
