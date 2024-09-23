#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Entity.h"
#include "AnimationB.h"
class Bullets : public Entity
{
public:
    Bullets(const sf::Texture &texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f mSpeed, sf::Vector2f position);
    ~Bullets();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;
    bool isOffScreen() const;
    void whenCollided();
    sf::Sprite getSprite();
    sf::FloatRect getGlobalBounds() const;

private:
    sf::Vector2f mSpeed;
    AnimationB mAnimation;
    unsigned int mRow;
};