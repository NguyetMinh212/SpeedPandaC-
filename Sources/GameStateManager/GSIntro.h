#pragma once
#include "GameStateBase.h"

class GSIntro : public GameStateBase {
public:
	GSIntro();
	virtual ~GSIntro();

	void Exit();
	void Pause();
	void Resume();

	StateTypes getTypeState();

	void Init() ;
	void Update(float deltatime);
	void Render(sf::RenderWindow* window);
private:
	sf::RectangleShape* m_logo;
	sf::RectangleShape* m_intro;
	sf::RectangleShape* m_shadow;

	float m_logoTime;
	float m_introTime;
	float m_currentTime;
};