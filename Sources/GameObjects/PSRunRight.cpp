#include "PSRunRight.h"

PSRunRight::PSRunRight(IPlayer* player)
{
	m_Player = player;
}

void PSRunRight::Init()
{
	m_Animation = new Animation(*DATA->getTexture("runright"), sf::Vector2i(3, 1), 0.3f);
	m_Animation->setScale(0.6f, 0.6f);
}

void PSRunRight::Update(float deltatime)
{
	m_Animation->Update(deltatime);
	m_currentTime += deltatime;
	if (m_Player->getHitBox()->getVelocity().x * m_currentTime > m_Player->getPath())
	{
		std::ifstream fin("../Data/Text/sizelevel_" + std::to_string(DATA->getMapLevel()) + ".txt");
		
		int x; fin >> x;
		int y; fin >> y;
		DATA->getSound("walking")->stop();
		m_Player->getHitBox()->setPosition(x + (m_Player->getColumn() + 0.5f) * 80, y + (m_Player->getRow() + 0.5f) * 80);
		m_Player->changeNextStage(IDLE);
		m_currentTime = 0.f;
	}
	else
		m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltatime, 0);
	
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSRunRight::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}
