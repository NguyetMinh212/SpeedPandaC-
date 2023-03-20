#include "PSIdle.h"

PSIdle::PSIdle(IPlayer* player)
{
	m_Player = player;
}

void PSIdle::Init()
{
	m_Animation = new Animation(*DATA->getTexture("idledown"), sf::Vector2i(3, 1), 0.3f);
	m_Animation->setScale(0.6f, 0.6f);
}

void PSIdle::Update(float deltatime)
{
	m_Animation->Update(deltatime);

	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSIdle::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}
