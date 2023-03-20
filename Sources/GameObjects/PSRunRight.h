#pragma once
#include"IPState.h"
#include "IPlayer.h"

class PSRunRight :public IPState {
public:
	PSRunRight(IPlayer* player);

	void Init();
	void Update(float deltatime);
	void Render(sf::RenderWindow* window);
	IPState::State getState() {
		return IPState::State::RUNRIGHT;
	}
private:
	IPlayer* m_Player;
	Animation* m_Animation;
	float m_currentTime;
};
