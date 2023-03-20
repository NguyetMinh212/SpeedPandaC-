#include "GameButton.h"

GameButton::GameButton()
{
	m_isHandling = false;
	m_current_time_click = 0.f;
	check = 0;
	time = 0.f;
}

GameButton::~GameButton()
{
}

void GameButton::Init(sf::Vector2f size ,std::string name)
{
	m_size = size;
	this->setSize(m_size);
	this->setOrigin(m_size / 2.f);
	this->setTexture(DATA->getTexture("Button/" + name));
}

void GameButton::Update(float deltaTime)
{
	time += deltaTime;
	if (this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
		if (time <= 0.2f)
		{
			if (check == 0)
			{
				DATA->playSound("mixkit-arcade-game-jump-coin-216");
			}
			this->setSize(m_size * 1.1f);
			this->setOrigin(this->getSize() / 2.f);
		}
		
	}
	else {
		check = 0;
		time = 0.f;
		this->setSize(m_size);
		this->setOrigin(m_size / 2.f);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		//HandleTouchEvent();
		m_isHandling = false;
		if (this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())))
		{
			m_current_time_click += deltaTime;
			if (m_current_time_click >= ClickTime) {
				DATA->playSound("mixkit-select-click-1109");
				m_btnClickFunc();
				m_isHandling = true;
				m_current_time_click = 0.f;
			}
		} else{
			m_current_time_click = 0.f;
		}
	}
}

void GameButton::Render(sf::RenderWindow* window)
{
	window->draw(*this);
}

void GameButton::HandleTouchEvent()
{
	m_isHandling = false;
	if (this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())))
	{
		m_btnClickFunc();
		m_isHandling = true;
	}
}

bool GameButton::IsHandle()
{
	return m_isHandling;
}

void GameButton::setOnClick(void(*Func)())
{
	m_btnClickFunc = Func;
}
