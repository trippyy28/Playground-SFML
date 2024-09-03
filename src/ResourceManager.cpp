// ResourceManager.cpp
#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
    std::cout << "Loading textures..." << std::endl;
    loadTexture("Healer", "/users/trippyy28/Desktop/SFML Playground/src/Assets/Healer.png");
    loadTexture("Ghost", "/users/trippyy28/Desktop/SFML Playground/src/Assets/ghost.png");
    loadTexture("M_11", "/users/trippyy28/Desktop/SFML Playground/src/Assets/M_11.png");
    loadTexture("DjBooth", "/users/trippyy28/Desktop/SFML Playground/src/Assets/DjBooth.png");
    std::cout << "Finished loading textures." << std::endl;
}

void ResourceManager::loadTexture(const std::string &name, const std::string &filename)
{
    sf::Texture texture;
    if (texture.loadFromFile(filename))
    {
        mTextures[name] = texture;
        std::cout << "Loaded texture: " << name << " from " << filename << std::endl;
    }
    else
    {
        std::cerr << "Error: Could not load texture from " << filename << std::endl;
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
    printTextures();
}

void ResourceManager::printTextures() const
{

    for (auto &texture : mTextures)
    {
        std::cout << "Texture: " << texture.first << std::endl;
    }
}
