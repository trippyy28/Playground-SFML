// ResourceManager.cpp
#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
    std::cout << "Loading textures..." << std::endl;
    loadTexture("Healer", "/users/trippyy28/Desktop/SFML Playground/src/Assets/Healer.png");
    loadTexture("Ghost", "/users/trippyy28/Desktop/SFML Playground/src/Assets/ghost.png");
    loadTexture("M_11", "/users/trippyy28/Desktop/SFML Playground/src/Assets/M_11.png");
    loadTexture("DjBooth", "/users/trippyy28/Desktop/SFML Playground/src/Assets/DjBooth.png");
    loadTexture("Bullet", "/users/trippyy28/Desktop/SFML Playground/src/Assets/shoot.png");
    loadMusic("BackgroundMusic", "/users/trippyy28/Desktop/SFML Playground/src/Assets/DJ Jeroenski - Back Once Again (Lee Mortimer Remix).mp3");
    std::cout << "Finished loading textures." << std::endl;
}

void ResourceManager::loadTexture(const std::string &name, const std::string &filename)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filename))
    {
        throw std::runtime_error("Failed to load texture from " + filename);
    }
    mTextures[name] = std::move(texture);
    std::cout << "Loaded texture: " << name << std::endl;
}
void ResourceManager::loadMusic(const std::string &name, const std::string &filename)
{
    auto music = std::make_unique<sf::Music>();
    if (!music->openFromFile(filename))
    {
        throw std::runtime_error("Failed to load music from " + filename);
    }
    mMusic[name] = std::move(music);
    std::cout << "Loaded music: " << name << std::endl;
}
sf::Music &ResourceManager::getMusic(const std::string &name)
{
    auto it = mMusic.find(name);
    if (it != mMusic.end())
    {
        return *(it->second);
    }
    else
    {
        throw std::runtime_error("Music not found: " + name);
    }
}

sf::Texture &ResourceManager::getTexture(const std::string &name)
{
    auto it = mTextures.find(name);
    if (it != mTextures.end())
    {
        std::cout << "Successfully retrieved texture: " << name << std::endl;

        return it->second;
    }
    else
    {
        std::cerr << "Error: Texture " << name << " not found!" << std::endl;
        static sf::Texture defaultTexture;
        if (!defaultTexture.loadFromFile("/users/trippyy28/Desktop/SFML Playground/src/Assets/Healer.png"))
        {
            std::cerr << "Error: Default texture not found!" << std::endl;
        }
        return defaultTexture;
    }
    // printTextures();
}

void ResourceManager::printTextures() const
{

    for (auto &texture : mTextures)
    {
        std::cout << "Texture: " << texture.first << std::endl;
    }
}
