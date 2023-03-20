#pragma once
#include "GameStateBase.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/CollisionManager.h"

class GSPlay : public GameStateBase {
public:
	GSPlay();
	virtual ~GSPlay();

	void Exit();
	void Pause();
	void Resume();

	StateTypes getTypeState();

	void Init();
	void Update(float deltatime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_Background;
	Player m_player;
	Matrix* m_matrix;
	CollisionManager m_CollisionManager;
	GameButton* m_button_pause;

	void InitButton();
};