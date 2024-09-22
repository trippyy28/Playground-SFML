#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>
#include <iostream>

class ResourceManager
{
public:
    ResourceManager();
    sf::Texture &getTexture(const std::string &name);
    sf::Music &getMusic(const std::string &name);
    void loadTexture(const std::string &name, const std::string &filename);
    void loadMusic(const std::string &name, const std::string &filename);
    void printTextures() const;

private:
    std::map<std::string, sf::Texture> mTextures;
    std::map<std::string, std::unique_ptr<sf::Music>> mMusic;
    sf::Texture mDefaultTexture;
};
