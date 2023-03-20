#pragma once
#include "GameStateBase.h"

class GSSettings : public GameStateBase {
public:
	GSSettings();
	virtual ~GSSettings();

	void Exit();
	void Pause();
	void Resume();

	StateTypes getTypeState();

	void Init();
	void Update(float deltatime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_Background;
	sf::RectangleShape* m_frame;
	GameButton* m_button_sound;
	GameButton* m_button_music;
	GameButton* m_button_home;

	void initBoard();
	void initButtonSound();
	void initButtonMusic();
	void initButtonHome();

	void updateButtonSound(float deltatime);
	void updateButtonMusic(float deltatime);
};
