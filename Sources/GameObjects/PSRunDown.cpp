#include "PSRunDown.h"

PSRunDown::PSRunDown(IPlayer* player)
{
	m_Player = player;
}

void PSRunDown::Init()
{
	m_Animation = new Animation(*DATA->getTexture("rundown"), sf::Vector2i(3, 1), 0.3f);
	m_Animation->setScale(0.6f, 0.6f);
}

void PSRunDown::Update(float deltatime)
{
	m_Animation->Update(deltatime);
	m_currentTime += deltatime;
	if (m_Player->getHitBox()->getVelocity().y * m_currentTime > m_Player->getPath())
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
		m_Player->getHitBox()->move(0, m_Player->getHitBox()->getVelocity().y * deltatime);
	

	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSRunDown::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}
