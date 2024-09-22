#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

class Menu
{
public:
    Menu(float width, float height);
    ~Menu() = default;

    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    std::vector<sf::Text> menuItems;
    sf::Font font;
    void update();
};
