#pragma once
#include"IPlayer.h"
#include "PSIdle.h"
#include "PSRunUp.h"
#include "PSRunDown.h"
#include "PSRunLeft.h"
#include "PSRunRight.h"

class Player :public IPlayer
{
public:
	Player();
	~Player();
	void changeNextStage(IPState::State nextState);

	void Init();
	void Update(float deltatime);
	void Render(sf::RenderWindow* window);

	HitBox* getHitBox();

	IPState::State getCurrentState();
	void setPath(int path);
	int getPath();
	void setRow(int r) ;
	int getRow();
	void setColumn(int c);
	int getColumn();

private:
	int m_path;
	int m_row, m_column;
	void performStateChange();
	HitBox* m_HitBox;
	IPState::State m_nextState;

	IPState* m_currentState;
	IPState* m_idleState;
	IPState* m_runupState;
	IPState* m_rundownState;
	IPState* m_runleftState;
	IPState* m_runrightState;

};