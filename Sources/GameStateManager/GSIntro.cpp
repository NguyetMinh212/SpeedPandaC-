#include "GSIntro.h"

GSIntro::GSIntro()
{
	m_intro = new sf::RectangleShape();
	m_logo = new sf::RectangleShape();
	m_shadow = new sf::RectangleShape();

	m_logoTime = 2.f;
	m_introTime = 3.f;
	m_currentTime = 0.f;
}

GSIntro::~GSIntro()
{
	if (m_logo != nullptr)
		delete m_logo;
	if (m_intro != nullptr)
		delete m_intro;
	if (m_shadow != nullptr)
		delete m_shadow;
}

void GSIntro::Exit()
{
}

void GSIntro::Pause()
{
}

void GSIntro::Resume()
{
}

StateTypes GSIntro::getTypeState()
{
	return StateTypes::INTRO;
}

void GSIntro::Init()
{
	//logo
	m_logo->setTexture(DATA->getTexture("logo"));
	m_logo->setSize(sf::Vector2f(screenHeight, screenHeight) * 0.75f);
	m_logo->setOrigin(m_logo->getSize() / 2.f);
	m_logo->setPosition(screenWidth / 2, screenHeight / 2);

	//intro
	m_intro->setTexture(DATA->getTexture("intro"));
	m_intro->setSize(sf::Vector2f(screenWidth, screenHeight));
	m_intro->setFillColor(sf::Color::Transparent);

	//shadow
	m_shadow->setFillColor(sf::Color(0, 0, 0, 0));
	m_shadow->setSize(sf::Vector2f(screenWidth, screenHeight));
}

void GSIntro::Update(float deltatime)
{
	DATA->UpdateMusic("backmusic");
	m_currentTime += deltatime;
	if (m_currentTime >= m_logoTime + m_introTime) {
		GSM->ChangeState(StateTypes::MENU);
		return;
	}
	if (m_currentTime < 0.75f) {
		m_logo->setFillColor(sf::Color(255, 255, 255, 255));
		m_intro->setFillColor(sf::Color::Transparent);
		m_shadow->setFillColor(sf::Color::Transparent);
	}
	else if (m_currentTime >= 0.75f && m_currentTime < 2.f) {
		float alpha = 255 * (m_currentTime - 0.75f) / 1.5f;
		m_shadow->setFillColor(sf::Color(0, 0, 0, (int)alpha));
	}
	else if (m_currentTime >= 2.f && m_currentTime < 3.f) {
		m_intro->setFillColor(sf::Color(255, 255, 255, 255));
		m_logo->setFillColor(sf::Color::Transparent);
		m_shadow->setFillColor(sf::Color::Transparent);
		if (m_currentTime >= 2.5f) {
			DATA->playMusic("backmusic");
			//DATA->getMusic("backmusic")->setLoop(true);
			//DATA->getMusic("backmusic")->setVolume(30);
		}
	}
	else {
		float alpha = 255 * (m_currentTime - 2.f - 1.f) / 2.f;
		m_shadow->setFillColor(sf::Color(0, 0, 0, (int)alpha));
	}
	
}

void GSIntro::Render(sf::RenderWindow* window)
{
	window->draw(*m_intro);
	window->draw(*m_logo);
	window->draw(*m_shadow);
}
