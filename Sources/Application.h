#pragma once
#include "GameManager/ResourceManager.h"
#include "GameStateManager/GameStateMachine.h"
class Application {
public:
	void Run();
	~Application();
private:
	void Init();
	void Update(float deltatime);
	void Render();
private:
	sf::RenderWindow* m_window;
	sf::Sprite m_Sprite;
};