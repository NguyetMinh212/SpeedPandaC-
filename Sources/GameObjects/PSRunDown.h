#pragma once
#include"IPState.h"
#include "IPlayer.h"

class PSRunDown :public IPState {
public:
	PSRunDown(IPlayer* player);

	void Init();
	void Update(float deltatime);
	void Render(sf::RenderWindow* window);
	IPState::State getState() {
		return IPState::State::RUNDOWN;
	}
private:
	IPlayer* m_Player;
	Animation* m_Animation;
	float m_currentTime;
}; 
