#include "GSSelectLevel.h"

GSSelectLevel::GSSelectLevel()
{
	m_button_back = new GameButton();
	m_frame = new sf::RectangleShape();
	m_count_map = 9;
	m_listBtn.resize(m_count_map+1, nullptr);
	for (int i = 1; i <= m_count_map; i++)
	{
		m_listBtn[i] = new GameButton();
	}
}

GSSelectLevel::~GSSelectLevel()
{
	if (m_button_back != nullptr)
		delete m_button_back;
	if (m_frame != nullptr)
		delete m_frame;
	for (int i = 1; i <= m_count_map; i++)
	{
		if (m_listBtn[i] != nullptr)
			delete m_listBtn[i];
	}
	m_listBtn.clear();
}

StateTypes GSSelectLevel::getTypeState()
{
	return StateTypes::SELECT_LEVEL;
}

void GSSelectLevel::Exit()
{
}

void GSSelectLevel::Pause()
{
}

void GSSelectLevel::Resume()
{
}

void GSSelectLevel::initBoard()
{
	// frame
	m_frame->setSize(sf::Vector2f(600.f, 750.f));
	m_frame->setTexture(DATA->getTexture("Frame/level_select"));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(screenWidth / 2.f+ screenWidth / 20.f +30.f, screenHeight / 2.f);
}

void GSSelectLevel::initButtonBack()
{
	m_button_back->Init(sf::Vector2f(260.f, 100.f), "ButtonBack1");
	m_button_back->setPosition(m_frame->getPosition() + sf::Vector2f(0.f, m_frame->getSize().x / 2.f+10.f));
	m_button_back->setOnClick([]() {GSM->PopState(); });
}

void GSSelectLevel::initListButton()
{
	for (int i = 1; i <= m_count_map; i++) {
		m_listBtn[i]->Init(sf::Vector2f(120.f, 120.f), "ButtonLocked");
		m_listBtn[i]->setOnClick([]() { GSM->ChangeState(StateTypes::PLAY); });
	}

	m_listBtn[1]->setPosition(m_frame->getPosition() + sf::Vector2f(-170.f, -130.f));
	m_listBtn[2]->setPosition(m_frame->getPosition() + sf::Vector2f(-20.f, -130.f));
	m_listBtn[3]->setPosition(m_frame->getPosition() + sf::Vector2f(130.f, -130.f));
	m_listBtn[4]->setPosition(m_frame->getPosition() + sf::Vector2f(-170.f, 20.f));
	m_listBtn[5]->setPosition(m_frame->getPosition() + sf::Vector2f(-20.f, 20.f));
	m_listBtn[6]->setPosition(m_frame->getPosition() + sf::Vector2f(130.f, 20.f));
	m_listBtn[7]->setPosition(m_frame->getPosition() + sf::Vector2f(-170.f, 170.f));
	m_listBtn[8]->setPosition(m_frame->getPosition() + sf::Vector2f(-20.f, 170.f));
	m_listBtn[9]->setPosition(m_frame->getPosition() + sf::Vector2f(130.f, 170.f));
}

void GSSelectLevel::updateListButton(float deltatime)
{
	for (int i = 1; i <= m_count_map; i++)
	{
		if (USER->getlevel() < i)
		{
			m_listBtn[i]->setTexture(DATA->getTexture("Button/ButtonLocked"));
			return;
		}
		if (USER->getlevel() == i)
		{
			m_listBtn[i]->setTexture(DATA->getTexture("Button/ButtonNumRed_"+std::to_string(i)));
		}
		else {
			m_listBtn[i]->setTexture(DATA->getTexture("Button/ButtonNumGreen_" + std::to_string(i)));
		}

		m_listBtn[i]->Update(deltatime);
		if (m_listBtn[i]->IsHandle()) {
			DATA->setMapLevel(i);
		}
	}
}

void GSSelectLevel::Init()
{
	//Background
	sf::Texture* texture = DATA->getTexture("background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);
	m_Background.setScale(1.f, 1.f);

	this->initBoard();
	this->initButtonBack();
	this->initListButton();

}

void GSSelectLevel::Update(float deltatime)
{
	DATA->UpdateMusic("backmusic");
	m_button_back->Update(deltatime);
	this->updateListButton(deltatime);
}

void GSSelectLevel::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(*m_frame);
	m_button_back->Render(window);
	for (int i = 1; i <= m_count_map; i++)
	{
		m_listBtn[i]->Render(window);
	}
}


