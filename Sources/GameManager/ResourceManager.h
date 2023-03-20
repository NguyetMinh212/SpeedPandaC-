#pragma once
#include<map>
#include<string>
#include"../GameObjects/GameButton.h"
#include "../GameConfig.h"
#include"../GameObjects/Animation.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "SFML/Audio.hpp"

#define DATA ResourceManager::GetInstance()

class ResourceManager : public CSingleton<ResourceManager> {
public:
	ResourceManager();
	~ResourceManager();

	void addTexture(std::string name);
	void removeTexture(std::string name);
	sf::Texture* getTexture(std::string name);

	void addSound(std::string name);
	void removeSound(std::string name);
	sf::Sound* getSound(std::string name);

	void addMusic(std::string name);
	void removeMusic(std::string name);
	sf::Music* getMusic(std::string name);

	void setMapLevel(int level);
	int getMapLevel();

	void setResultGame(bool is_win);
	bool isWinGame();

	void playSound(std::string name);
	void playMusic(std::string name);
	void pauseMusic(std::string name);
	void stopMusic(std::string name);
	void UpdateMusic(std::string name);

	bool isAllowSound();
	void setAllowSound(bool allow);

	bool isAllowMusic();
	void setAllowMusic(bool allow);

private:
	std::map<std::string, sf::Texture*> m_MapTexture;
	std::map<std::string, sf::Sound*> m_MapSound;
	std::map<std::string, sf::Music*> m_MapMusic;
	std::string m_Path;
	std::string m_TexturePath;
	std::string m_SoundPath;

	bool m_is_allow_sound;
	bool m_is_allow_music;

	int m_map_level;
	bool m_is_win;
	bool playing;
};