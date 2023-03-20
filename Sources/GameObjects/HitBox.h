#pragma once
#include"../GameManager/ResourceManager.h"

enum TAG {
	PLAYER,
	COINS,
};

class HitBox :public sf::RectangleShape{
public:
	HitBox(sf::Vector2f size);
	~HitBox();

	void Init(sf::Vector2f velocity);
	sf::Vector2f getVelocity();
	TAG getTag() { return m_tag; }
	void setTag(TAG tag) { m_tag = tag; }

	bool isAlive() { return m_isAlive; }
	void setAlive(bool alive) { m_isAlive = alive; }

private:
	sf::Vector2f m_velocity;
	bool m_isAlive;
	TAG m_tag;
};
