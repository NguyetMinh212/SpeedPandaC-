#include "GSEnd.h"

GSEnd::GSEnd()
{
	m_frame = new sf::RectangleShape();
	m_button_level = new GameButton();
}

GSEnd::~GSEnd()
{
	if (m_frame != nullptr)
		delete m_frame;
	if (m_button_level != nullptr)
		delete m_button_level;
}

StateTypes GSEnd::getTypeState()
{
	return StateTypes::END;
}

void GSEnd::initBoard()
{
	// frame
	m_frame->setSize(sf::Vector2f(870.f, 684.f));
	m_frame->setTexture(DATA->getTexture("Frame/Wingame"));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(screenWidth / 2.f, screenHeight / 2.f);
}

void GSEnd::initButton()
{
	m_button_level->Init(sf::Vector2f(120.f, 120.f), "ButtonAccept");
	m_button_level->setPosition(m_frame->getPosition() + sf::Vector2f(0.f, m_frame->getSize().y / 3.f+20.f));
	m_button_level->setOnClick([]() {
		while (GSM->currentState()->getTypeState() != StateTypes::SELECT_LEVEL) {
			GSM->PopState();
		}
		});
}

void GSEnd::updateUser()
{
	if (DATA->isWinGame()) {
		if (USER->getlevel() == DATA->getMapLevel()) {
			USER->setLevel(USER->getlevel() + 1);
		}
	}
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
{
	//Background
	sf::Texture* texture = DATA->getTexture("bgameplay1");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);
	m_Background.setScale(1.f, 1.f);

	this->initBoard();
	this->initButton();
	this->updateUser();
}

void GSEnd::Update(float deltatime)
{
	DATA->UpdateMusic("backmusic");
	m_button_level->Update(deltatime);
}

void GSEnd::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(*m_frame);
	m_button_level->Render(window);
}

