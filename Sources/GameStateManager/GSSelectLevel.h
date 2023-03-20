#pragma once
#include "GameStateBase.h"

class GSSelectLevel: public GameStateBase {
public:
	GSSelectLevel();
	virtual ~GSSelectLevel();
	
	StateTypes getTypeState(); 

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltatime);
	void Render(sf::RenderWindow* window);

private:
	std::vector<GameButton*> m_listBtn;
	sf::Sprite m_Background;
	sf::RectangleShape* m_frame;

	GameButton* m_button_back;

	int m_count_map;

	void initBoard();
	void initButtonBack();
	void initListButton();

	void updateListButton(float deltatime);
};