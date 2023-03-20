#include "Player.h"


Player::Player()
{
	m_idleState = new PSIdle(this);
	m_runupState = new PSRunUp(this);
	m_rundownState = new PSRunDown(this);
	m_runleftState = new PSRunLeft(this);
	m_runrightState = new PSRunRight(this);
	m_currentState = m_idleState;
}

Player::~Player()
{
	if (m_idleState != nullptr)
		delete m_idleState;
	if (m_runupState != nullptr)
		delete m_runupState;
	if (m_rundownState != nullptr)
		delete m_rundownState;
	if (m_runleftState != nullptr)
		delete m_runleftState;
	if (m_runrightState != nullptr)
		delete m_runrightState;
	m_currentState = nullptr;
}

void Player::changeNextStage(IPState::State nextState)
{
	m_nextState = nextState;
}

void Player::Init()
{
	m_idleState->Init();
	m_runupState->Init();
	m_rundownState->Init();
	m_runleftState->Init();
	m_runrightState->Init();

	m_HitBox = new HitBox(sf::Vector2f(75.f, 75.f));
	std::ifstream fin("../Data/Text/sizelevel_" + std::to_string(DATA->getMapLevel()) + ".txt");
	int x; fin >> x;
	int y; fin >> y;
	int r; fin >> r;
	int c; fin >> c;
	m_HitBox->setPosition(x+(c+0.5f)*80, y+(r+0.5f)*80);
	m_HitBox->Init(sf::Vector2f(400.f, 400.f));
	m_HitBox->setTag(PLAYER);
}

void Player::Update(float deltatime)
{
	performStateChange();
	m_currentState->Update(deltatime);
}

void Player::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	window->draw(*m_HitBox);
}

HitBox* Player::getHitBox()
{
	return m_HitBox;
}

IPState::State Player::getCurrentState()
{
	IPState::State state = m_currentState->getState();
	return state;
}

void Player::performStateChange()
{
	if (m_nextState != IPState::SNULL)
	{
		switch (m_nextState)
		{
		case IPState::IDLE:
			m_currentState = m_idleState;
			break;
		case IPState::RUNUP:
			m_currentState = m_runupState;
			break;
		case IPState::RUNDOWN:
			m_currentState = m_rundownState;
			break;
		case IPState::RUNLEFT:
			m_currentState = m_runleftState;
			break;
		case IPState::RUNRIGHT:
			m_currentState = m_runrightState;
			break;
		default:
			break;
		}
		m_nextState = IPState::SNULL;
	}
}

void Player::setPath(int path)
{
	m_path = path;
}

int Player::getPath()
{
	return m_path;
}

void Player::setRow(int r)
{
	m_row = r;
}

int Player::getRow()
{
	return m_row;
}

void Player::setColumn(int c)
{
	m_column = c;
}

int Player::getColumn()
{
	return m_column;
}
