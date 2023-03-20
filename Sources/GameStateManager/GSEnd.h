#pragma once
#include "GameStateBase.h"

class GSEnd : public GameStateBase {
public:
	GSEnd();
	virtual ~GSEnd();

	StateTypes getTypeState();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltatime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_Background;
	sf::RectangleShape* m_frame;
	GameButton* m_button_level;
	void initBoard();
	void initButton();
	void updateUser();
};
