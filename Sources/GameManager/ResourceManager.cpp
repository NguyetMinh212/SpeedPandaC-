#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
    m_Path = "../Data/";
    m_TexturePath = m_Path + "Textures/";
    m_SoundPath = m_Path + "Sound/";
    m_map_level = 1;
    m_is_win = true;
    m_is_allow_sound = true;
    m_is_allow_music = true;
    playing = true;
}

ResourceManager::~ResourceManager()
{
    for (auto it : m_MapTexture)
    {
        if (it.second != nullptr) delete it.second;
    }
    m_MapTexture.clear();

    for (auto it : m_MapSound)
    {
        if (it.second != nullptr) delete it.second;
    }
    m_MapSound.clear();

    for (auto it : m_MapMusic)
    {
        if (it.second != nullptr) delete it.second;
    }
    m_MapMusic.clear();
   
}

void ResourceManager::addTexture(std::string name)
{
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(m_TexturePath + name+".png");
    auto it = m_MapTexture.find(name);
    if (it != m_MapTexture.end())
    {
        return;
    }
    m_MapTexture.insert(std::pair<std::string, sf::Texture*>(name, texture));
}

void ResourceManager::removeTexture(std::string name)
{
    auto it = m_MapTexture.find(name);
    if (it == m_MapTexture.end())
    {
        return;
    }
    if (it->second != nullptr) delete it->second;
    m_MapTexture.erase(it);
}

sf::Texture* ResourceManager::getTexture(std::string name)
{
    auto it = m_MapTexture.find(name);
    if (it != m_MapTexture.end())
    {
        return it->second;
    }
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(m_TexturePath + name + ".png");
    m_MapTexture.insert(std::pair<std::string, sf::Texture*>(name, texture));
    return texture;
}

void ResourceManager::addSound(std::string name)
{
    sf::Sound* sound = new sf::Sound();
    sf::SoundBuffer* buffer = new sf::SoundBuffer();
    buffer->loadFromFile(m_SoundPath + name + ".wav");
    sound->setBuffer(*buffer);
    auto it = m_MapSound.find(name);
    if (it != m_MapSound.end())
    {
        return;
    }
    m_MapSound.insert(std::pair<std::string, sf::Sound*>(name, sound));
}

void ResourceManager::removeSound(std::string name)
{
    auto it = m_MapSound.find(name);
    if (it == m_MapSound.end())
    {
        return;
    }
    if (it->second != nullptr) delete it->second;
    m_MapSound.erase(it);
}

sf::Sound* ResourceManager::getSound(std::string name)
{
    auto it = m_MapSound.find(name);
    if (it != m_MapSound.end())
    {
        return it->second;
    }
    sf::Sound* sound = new sf::Sound();
    sf::SoundBuffer* buffer = new sf::SoundBuffer();
    buffer->loadFromFile(m_SoundPath + name + ".wav");
    sound->setBuffer(*buffer);
    m_MapSound.insert(std::pair<std::string, sf::Sound*>(name, sound));
    return sound;
}

void ResourceManager::addMusic(std::string name)
{
    sf::Music* music = new sf::Music();
    music->openFromFile(m_SoundPath + name + ".wav");
    auto it = m_MapMusic.find(name);
    if (it != m_MapMusic.end())
    {
        return;
    }
    m_MapMusic.insert(std::pair<std::string, sf::Music*>(name, music));
}

void ResourceManager::removeMusic(std::string name)
{
    auto it = m_MapMusic.find(name);
    if (it == m_MapMusic.end())
    {
        return;
    }
    if (it->second != nullptr) delete it->second;
    m_MapMusic.erase(it);
}

sf::Music* ResourceManager::getMusic(std::string name)
{
    auto it = m_MapMusic.find(name);
    if (it != m_MapMusic.end())
    {
        return it->second;
    }
    sf::Music* music = new sf::Music();
    music->openFromFile(m_SoundPath + name + ".wav");
    m_MapMusic.insert(std::pair<std::string, sf::Music*>(name, music));
    return music;
}


void ResourceManager::setMapLevel(int level)
{
    m_map_level = level;
}

int ResourceManager::getMapLevel()
{
    return m_map_level;
}

void ResourceManager::setResultGame(bool is_win)
{
    m_is_win = is_win;
}

bool ResourceManager::isWinGame()
{
    return m_is_win;
}

void ResourceManager::playSound(std::string name)
{
    if (m_is_allow_sound) {
        DATA->getSound(name)->play();
    }
}

void ResourceManager::playMusic(std::string name)
{
    if (m_is_allow_music) {
        sf::Music* music = this->getMusic(name);
        if (music->getStatus() == sf::Music::Stopped || music->getStatus() == sf::Music::Paused) {
            music->setVolume(50);
            music->setLoop(true);
            music->play();
        }
       
    }
}

void ResourceManager::pauseMusic(std::string name)
{
    auto it = m_MapMusic.find(name);
    if (it != m_MapMusic.end()) {
        it->second->pause();
    }
}

void ResourceManager::stopMusic(std::string name)
{
    auto it = m_MapMusic.find(name);
    if (it != m_MapMusic.end()) {
        it->second->stop();
    }
}

void ResourceManager::UpdateMusic(std::string name)
{
    if (DATA->isAllowMusic() == false)
    {
        playing = false;
        DATA->stopMusic(name);
    }
    else {
        auto it = m_MapMusic.find(name);
        if (!playing)
        {
            DATA->playMusic(name);
            playing = true;
        }
    }
}

bool ResourceManager::isAllowSound()
{
   return m_is_allow_sound;
}

void ResourceManager::setAllowSound(bool allow)
{
    m_is_allow_sound = allow;
}

bool ResourceManager::isAllowMusic()
{
    return m_is_allow_music;
}

void ResourceManager::setAllowMusic(bool allow)
{
    m_is_allow_music = allow;
}
