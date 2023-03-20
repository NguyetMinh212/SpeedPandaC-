#pragma once
#include"IPState.h"
#include "IPlayer.h"

class PSRunUp :public IPState {
public:
	PSRunUp(IPlayer* player);

	void Init();
	void Update(float deltatime);
	void Render(sf::RenderWindow* window);

	IPState::State getState() {
		return IPState::State::RUNUP;
	}
private:

	IPlayer* m_Player;
	Animation* m_Animation;
	float m_currentTime;
};