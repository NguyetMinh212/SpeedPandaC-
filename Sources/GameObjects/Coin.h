#pragma once
#include"../GameManager/ResourceManager.h"
#include"HitBox.h"

class Coin {
public:
	Coin();
	~Coin();
	void Init();
	void Update(float deltatime);
	void Render(sf::RenderWindow* window);

	HitBox* getHitBox() { return m_HitBox; };
private:
	HitBox* m_HitBox;
	Animation* m_ani;
};
