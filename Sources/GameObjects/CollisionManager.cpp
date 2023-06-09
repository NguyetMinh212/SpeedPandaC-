#include "CollisionManager.h"

void CollisionManager::addObj(HitBox* hitBox)
{
	m_listObj.push_back(hitBox);
}

bool CollisionManager::checkCollision(HitBox* a, HitBox* b)
{
	return a->getGlobalBounds().intersects(b->getGlobalBounds());
}

void CollisionManager::Update()
{
	for (auto a : m_listObj)
	{
		for (auto b : m_listObj)
		{
			if (a->getTag() == b->getTag()) continue;
			if (!checkCollision(a, b)) continue;
			if (a->getTag() == PLAYER && b->getTag() == COINS)
			{
				b->setAlive(false);
				//DATA->getSound("coinswin")->play();
			}
		}
			//DATA->getSound("coinswin")->stop();
	}
}
