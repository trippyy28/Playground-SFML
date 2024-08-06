#include <SFML/Graphics.hpp>
#include "AnimationB.h"

class Healer
{
public:
    Healer(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);
    ~Healer();
    sf::IntRect uvRect;
    void Update(float deltaTime);
    void Draw(sf::RenderWindow &window);

private:
    sf::RectangleShape body;
    AnimationB animationB;
    unsigned int column;
    unsigned int row;
    float speed;
};
