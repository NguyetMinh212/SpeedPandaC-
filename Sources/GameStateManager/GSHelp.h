#pragma once
#include "GameStateBase.h"

class GSHelp : public GameStateBase {
public:
	GSHelp();
	virtual ~GSHelp();

	void Exit();
	void Pause();
	void Resume();

	StateTypes getTypeState();

	void Init();
	void Update(float deltatime);
	void Render(sf::RenderWindow* window);
private:
	GameButton* m_button_back;
	sf::Sprite m_Background;
	sf::RectangleShape* m_frame;

	void initBoard();
	void initButton();
};

