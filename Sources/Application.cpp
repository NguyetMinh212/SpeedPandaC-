#include "Application.h"
#include "GameStateManager/GameStateBase.h"


Application::~Application()
{
	if (m_window != nullptr)
		delete m_window;
}

void Application::Init()
{
	m_window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), gameTiltle, sf::Style::Close);
	m_window->setFramerateLimit(60);
	m_window->setVerticalSyncEnabled(false); 
	GameStateMachine::GetInstance()->ChangeState(StateTypes::INTRO);
	WConnect->setWindow(m_window);
}

void Application::Run()
{
	Init();
	sf::Clock clock;
	float deltatime = 0.f;
	while (m_window->isOpen())
	{
		deltatime = clock.restart().asSeconds();
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window->close();
		}
		Update(deltatime);
		Render();
	}
}

void Application::Update(float deltatime)
{
	//Doing something
	//if (GameStateMachine::GetInstance()->NeedToChangeState()) {
		//GameStateMachine::GetInstance()->PerformStateChange();
	//}
	//GameStateMachine::GetInstance()->currentState()->Update(deltatime);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		//GameStateMachine::GetInstance()->ChangeState(StateTypes::MENU);
	//}
	if (GSM->NeedToChangeState()) {
		GSM->PushState();
	}
	GSM->currentState()->Update(deltatime);
}

void Application::Render()
{
	m_window->clear(sf::Color::White);
	//Drawing something
	GameStateMachine::GetInstance()->currentState()->Render(m_window);
	m_window->display();
}
