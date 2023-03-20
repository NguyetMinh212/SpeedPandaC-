#include "GSWarningHome.h"

GSWarningHome::GSWarningHome()
{
	m_frame = new sf::RectangleShape();
	m_button_accept = new GameButton();
	m_button_cancel = new GameButton();
}

GSWarningHome::~GSWarningHome()
{
	if (m_frame != nullptr)
		delete m_frame;
	if (m_button_accept != nullptr)
		delete m_button_accept;
	if (m_button_cancel != nullptr)
		delete m_button_cancel;
}

StateTypes GSWarningHome::getTypeState()
{
	return StateTypes::WARNING_HOME;
}

void GSWarningHome::initBoard()
{
	m_frame->setSize(sf::Vector2f(780.f, 627.f));
	m_frame->setTexture(DATA->getTexture("Frame/WARNING"));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(screenWidth / 2.f, screenHeight / 2.f);
}

void GSWarningHome::initButton()
{
	// accept button
	m_button_accept->Init(sf::Vector2f(120.f, 120.f), "ButtonAccept");
	m_button_accept->setPosition(m_frame->getPosition() + sf::Vector2f(-150.f, m_frame->getSize().y / 2.f-70.f));
	m_button_accept->setOnClick([]() {
		while (GSM->currentState()->getTypeState() != StateTypes::MENU) {
			GSM->PopState();
		}
		});

	// cancel button
	m_button_cancel->Init(sf::Vector2f(120.f, 120.f), "ButtonCancel1");
	m_button_cancel->setPosition(m_frame->getPosition() + sf::Vector2f(140.f, m_frame->getSize().y / 2.f-70.f));
	m_button_cancel->setOnClick([]() { GSM->PopState(); });

}


void GSWarningHome::Exit()
{
}

void GSWarningHome::Pause()
{
}

void GSWarningHome::Resume()
{
}

void GSWarningHome::Init()
{
	//Background
	sf::Texture* texture = DATA->getTexture("bgameplay1");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);
	m_Background.setScale(1.f, 1.f);

	this->initBoard();
	this->initButton();
}

void GSWarningHome::Update(float deltatime)
{
	DATA->UpdateMusic("backmusic");
	m_button_accept->Update(deltatime);
	m_button_cancel->Update(deltatime);
}

void GSWarningHome::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(*m_frame);
	window->draw(*m_button_accept);
	window->draw(*m_button_cancel);
}

