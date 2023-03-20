#pragma once
#include"IPState.h"
#include "IPlayer.h"

class PSIdle:public IPState {
public:
	PSIdle(IPlayer* player);

	void Init();
	void Update(float deltatime);
	void Render(sf::RenderWindow* window);
	IPState::State getState() {
		return IPState::State::IDLE;
	}
private:
	IPlayer* m_Player;
	Animation* m_Animation;
};