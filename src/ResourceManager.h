#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>

class ResourceManager
{
public:
    ResourceManager();
    sf::Texture &getTexture(const std::string &name);
    void loadTexture(const std::string &name, const std::string &filename);
    void printTextures() const;

private:
    std::map<std::string, sf::Texture> mTextures;
    sf::Texture mDefaultTexture;
};
