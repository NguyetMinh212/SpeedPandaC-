#pragma once
#include"../GameManager/ResourceManager.h"

class IPState {
public:
	enum State {
		IDLE,
		RUNUP,
		RUNDOWN,
		RUNLEFT,
		RUNRIGHT,
		SNULL,
	};
	virtual void Init() = 0;
	virtual void Update(float deltatime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;

	virtual IPState::State getState() = 0;
};