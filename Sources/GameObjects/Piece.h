#pragma once
#include "../GameManager/ResourceManager.h"
#include "../Application.h"
#include"Coin.h"
 
enum class PieceType {
	TREEBLOCK = 0,
	PATH,
	COIN,
};

class Piece : public sf::RectangleShape {
private:
	PieceType m_Type;
	sf::Vector2f m_root, m_size;
	float m_x, m_y;
	int m_r, m_c;
	//Animation* m_ani;
	//Coin m_coin;
	std::list<Coin*> m_listCoin;
	std::list<Coin*> m_checklistCoin;

public:
	Piece();
	~Piece();

	int getType();

	void setX(float x);
	float getX();

	void setY(float y);
	float getY();

	void setR(int r);
	int getR();

	void setC(int c);
	int getC();

	Coin* getCoin();


	void setPiece(int type);
	void InitPiece(int type, int row, int column, sf::Vector2f root, sf::Vector2f size);
	void UpdatePiece(float deltatime);
	void RenderPeice(sf::RenderWindow* window);
};