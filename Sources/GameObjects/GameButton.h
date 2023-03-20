#pragma once
//#include "SFML/Graphics.hpp"
#include "../GameManager/WindowConnector.h"
#include "../GameManager/ResourceManager.h"
#include "../Application.h"
class GameButton : public sf::RectangleShape {
public:
	GameButton();
	~GameButton();

	void Init(sf::Vector2f size ,std::string name);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	void HandleTouchEvent();
	bool IsHandle();

	void setOnClick(void (*Func)());
private:
	sf::Vector2f m_size;
	void(*m_btnClickFunc)();
	bool m_isHandling;
	float m_current_time_click;
	int check;
	float time;
};