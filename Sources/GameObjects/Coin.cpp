#include "Coin.h"

Coin::Coin()
{
	
}

Coin::~Coin()
{
	if (m_ani != nullptr)
		delete m_ani;
	if (m_HitBox != nullptr)
		delete m_HitBox;
}

void Coin::Init()
{
	m_ani = new Animation(*DATA->getTexture("Pieces/coins"), sf::Vector2i(16, 1), 0.05f);
	m_ani->setScale(0.5f, 0.5f);
	m_HitBox = new HitBox(sf::Vector2f(30.f,30.f));
	m_HitBox->setTag(COINS);
}

void Coin::Update(float deltatime)
{
	m_ani->Update(deltatime);
	m_ani->setPosition(getHitBox()->getPosition());
}

void Coin::Render(sf::RenderWindow* window)
{
	window->draw(*m_ani);
	window->draw(*m_HitBox);
}