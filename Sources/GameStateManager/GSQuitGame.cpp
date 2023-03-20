#include "GSQuitGame.h"

GSQuitGame::GSQuitGame()
{
	m_frame = new sf::RectangleShape();
	m_button_accept = new GameButton();
	m_button_cancel = new GameButton();
}

GSQuitGame::~GSQuitGame()
{
	if (m_frame != nullptr)
		delete m_frame;
	if (m_button_accept != nullptr)
		delete m_button_accept;
	if (m_button_cancel != nullptr)
		delete m_button_cancel;
}

StateTypes GSQuitGame::getTypeState()
{
	return StateTypes::QUIT_GAME;
}

void GSQuitGame::Exit()
{
}

void GSQuitGame::Pause()
{
}

void GSQuitGame::Resume()
{
}

void GSQuitGame::initBoard()
{
	m_frame->setSize(sf::Vector2f(705.f, 570.f));
	m_frame->setTexture(DATA->getTexture("Frame/WARNING"));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(screenWidth / 2.f + screenWidth / 20.f + 30.f, screenHeight / 2.f);
}

void GSQuitGame::initButton()
{
	// accept button
	//WConnect->getWindow()->close(); }
	m_button_accept->Init(sf::Vector2f(120.f, 120.f), "ButtonAccept");
	m_button_accept->setPosition(m_frame->getPosition() + sf::Vector2f(-105.f, m_frame->getSize().y / 3.f+20.f));
	m_button_accept->setOnClick([]() {WConnect->getWindow()->close(); });

	// cancel button
	m_button_cancel->Init(sf::Vector2f(120.f, 120.f), "ButtonCancel1");
	m_button_cancel->setPosition(m_frame->getPosition() + sf::Vector2f(105.f, m_frame->getSize().y / 3.f + 20.f));
	m_button_cancel->setOnClick([]() { GSM->PopState(); });
}

void GSQuitGame::Init()
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

void GSQuitGame::Update(float deltatime)
{
	DATA->UpdateMusic("backmusic");
	m_button_accept->Update(deltatime);
	m_button_cancel->Update(deltatime);
}

void GSQuitGame::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(*m_frame);
	window->draw(*m_button_accept);
	window->draw(*m_button_cancel);
}

