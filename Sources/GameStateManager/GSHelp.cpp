#include "GSHelp.h"

GSHelp::GSHelp()
{
	m_frame = new sf::RectangleShape();
	m_button_back = new GameButton();
}

GSHelp::~GSHelp()
{
	if (m_frame != nullptr)
		delete m_frame;
	if (m_button_back != nullptr)
		delete m_button_back;
}

void GSHelp::Exit()
{
}

void GSHelp::Pause()
{
}

void GSHelp::Resume()
{
}

StateTypes GSHelp::getTypeState()
{
	return StateTypes::HELP;
}

void GSHelp::initBoard()
{
	m_frame->setSize(sf::Vector2f(870.f, 700.f));
	m_frame->setTexture(DATA->getTexture("Frame/About"));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(screenWidth / 2.f + screenWidth / 20.f + 30.f, screenHeight / 2.f);
}

void GSHelp::initButton()
{
	m_button_back->Init(sf::Vector2f(260.f, 110.f), "ButtonBack1");
	m_button_back->setPosition(m_frame->getPosition() + sf::Vector2f(0.f, m_frame->getSize().y / 3.f + 50.f));
	m_button_back->setOnClick([]() { GSM->PopState(); });
}

void GSHelp::Init()
{
	//Background
	sf::Texture* texture = DATA->getTexture("background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);
	m_Background.setScale(1.f, 1.f);

	this->initBoard();
	this->initButton();
}

void GSHelp::Update(float deltatime)
{
	DATA->UpdateMusic("backmusic");
	m_button_back->Update(deltatime);
}

void GSHelp::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(*m_frame);
	window->draw(*m_button_back);
}

