#pragma once
#include "GameStateBase.h"
class GSQuitGame : public GameStateBase {
public:
	GSQuitGame();
	virtual ~GSQuitGame();

	StateTypes getTypeState();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltatime);
	void Render(sf::RenderWindow* window);

private:
	GameButton* m_button_accept;
	GameButton* m_button_cancel;
	sf::Sprite m_Background;
	sf::RectangleShape* m_frame;

	void initBoard();
	void initButton();
};