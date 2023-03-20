#pragma once
#include "GameStateBase.h"

class GSMenu : public GameStateBase {
public:
	GSMenu();
	virtual ~GSMenu();

	void Exit();
	void Pause();
	void Resume();

	StateTypes getTypeState();

	void Init();
	void Update(float deltatime);
	void Render(sf::RenderWindow* window);
private:
	std::list<GameButton*> m_listBtn;
	sf::Sprite m_Background;
};