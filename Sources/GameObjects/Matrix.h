#pragma once
#include "Piece.h"

class Matrix {
private:
	sf::RectangleShape* m_frame;
	sf::RectangleShape* m_board;
	Piece* m_matrix[15][15];

	sf::Vector2f m_rootBoard;
	sf::Vector2f m_sizePiece;

	//int randomPiece(int r, int c);
	
	void InitMatrixPiece();
	void UpdateBoard(float deltatime);
	int m_row, m_column;
	
public:
	Matrix();
	~Matrix();

	sf::Vector2f getSize();
	sf::Vector2f getPosition();
	int getPieceType(int row, int column);
	void resetCoin(int row, int column);
	bool checkCoin();
	void setRow(int row);
	int getRow();
	void setColumn(int column);
	int getColumn();

	sf::Vector2f getPiecePosition(int row, int column);

	Coin* getCoin(int row, int column);

	void InitMatrix();
	void UpdateMatrix(float deltatime);
	void RenderMatrix(sf::RenderWindow* window);
};