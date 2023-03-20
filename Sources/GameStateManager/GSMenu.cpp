#include "GSMenu.h"

GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

StateTypes GSMenu::getTypeState()
{
	return StateTypes::MENU;
}

void GSMenu::Init()
{
	GameButton* button;

	//Play Button
	button = new GameButton();
	button->Init(sf::Vector2f(300,108),"ButtonPlay1");
	button->setOnClick([]() {GSM->ChangeState(StateTypes::SELECT_LEVEL); });
	button->setPosition(screenWidth / 2 +screenWidth/20 , screenHeight /2-screenHeight/10);
	button->setOrigin(button->getSize() / 2.f);
	m_listBtn.push_back(button);

	// Exit Button
	button = new GameButton();
	button->Init(sf::Vector2f(290,108),"ButtonCancel");
	button->setOnClick([]() {GSM->ChangeState(StateTypes::QUIT_GAME); });
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2+screenWidth/20+5.f, screenHeight - screenHeight / 4 + 20.f);
	m_listBtn.push_back(button);

	//About Button
	button = new GameButton();
	button->Init(sf::Vector2f(290, 108), "ButtonAbout1");
	button->setOnClick([]() {GSM->ChangeState(StateTypes::HELP); });
	button->setPosition(screenWidth / 2 + screenWidth / 20, screenHeight/2 + screenHeight / 6-15.f);
	button->setOrigin(button->getSize() / 2.f);
	m_listBtn.push_back(button);

	//Settings Button
	button = new GameButton();
	button->Init(sf::Vector2f(280, 108), "ButtonSetting1");
	button->setOnClick([]() {GSM->ChangeState(StateTypes::SETTINGS); });
	button->setPosition(screenWidth / 2 + screenWidth / 20, screenHeight/2+ screenHeight/30-5.f);
	button->setOrigin(button->getSize() / 2.f);
	m_listBtn.push_back(button);

	//Option Button
	//button = new GameButton();
	//button->Init(sf::Vector2f(290, 108), "ButtonOption1");
	//button->setOnClick([]() {GSM->ChangeState(StateTypes::SELECT_LEVEL); });
	//button->setPosition(screenWidth / 2 + screenWidth / 20, screenHeight - screenHeight / 4+20.f);
	//button->setOrigin(button->getSize() / 2.f);
	//m_listBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("background1");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);
	m_Background.setScale(1.f, 1.f);

}

void GSMenu::Update(float deltatime)
{
	DATA->UpdateMusic("backmusic");
	for (auto btn : m_listBtn)
	{
		btn->Update(deltatime);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_listBtn)
	{
		btn->Render(window);
	}

}
