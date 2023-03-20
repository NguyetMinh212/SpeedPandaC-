#include "Matrix.h"

Matrix::Matrix()
{
	m_frame = new sf::RectangleShape();
	m_board = new sf::RectangleShape();
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			m_matrix[i][j] = new Piece();
		}
	}
}

Matrix::~Matrix()
{
	if (m_frame != nullptr)
		delete m_frame;
	if (m_board != nullptr)
		delete m_board;
	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < getColumn(); j++)
		{
			if (m_matrix[i][j] != nullptr)
				delete m_matrix[i][j];
		}
	}
}

sf::Vector2f Matrix::getSize()
{
	return m_frame->getSize();
}

sf::Vector2f Matrix::getPosition()
{
	return m_frame->getPosition();
}

int Matrix::getPieceType(int row, int column)
{
	return m_matrix[row][column]->getType();
}

void Matrix::resetCoin(int row, int column)
{
	m_matrix[row][column]->setPiece(1);
}

bool Matrix::checkCoin()
{
	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < getColumn(); j++)
		{
			if (m_matrix[i][j]->getType()==2) return false;
		}
	}
	return true;
}

void Matrix::setRow(int row)
{
	m_row = row;
}

int Matrix::getRow()
{
	return m_row;
}

void Matrix::setColumn(int column)
{
	m_column = column;
}

int Matrix::getColumn()
{
	return m_column;
}

sf::Vector2f Matrix::getPiecePosition(int row, int column)
{
	return m_matrix[row][column]->getPosition();
}

Coin* Matrix::getCoin(int row, int column)
{
	Coin* x = m_matrix[row][column]->getCoin();
	return x;
}

void Matrix::InitMatrixPiece()
{

	std::ifstream finn("../Data/Text/infolevel_" + std::to_string(DATA->getMapLevel()) + ".txt");
	

	int a; finn >> a;
	setRow(a);
	int b; finn >> b;
	setColumn(b);

	std::ifstream fin("../Data/Text/level_" + std::to_string(DATA->getMapLevel()) + ".txt");
	
	std::string f_frame; fin >> f_frame;
	int x; fin >> x;
	int y; fin >> y;
	m_frame->setTexture(DATA->getTexture(f_frame));
	m_frame->setSize(sf::Vector2f(x*1.f, y*1.f));
	m_frame->setScale(1.f, 1.f);
	m_frame->setPosition((screenWidth - m_frame->getSize().x) / 2.f, (screenHeight - m_frame->getSize().y) / 2.f);

	std::string f_board; fin >> f_board;
	int d; fin >> d;
	m_board->setTexture(DATA->getTexture(f_board));
	m_board->setSize(sf::Vector2f(80*1.f*getColumn(), 80*1.f*getRow()));
	m_board->setPosition((screenWidth - m_board->getSize().x) / 2.f, (screenHeight - m_frame->getSize().y) / 2.f+d*1.f);

	m_rootBoard = m_board->getPosition();
	m_sizePiece.x = m_board->getSize().x / (getColumn()*1.f);
	m_sizePiece.y = m_board->getSize().y / (getRow() * 1.f);

	printf("%f %f %f %f", m_rootBoard.x, m_rootBoard.y, m_sizePiece.x, m_sizePiece.y);

	


	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < getColumn(); j++)
		{
			
			int z;
			fin >> z;
			m_matrix[i][j]->InitPiece(z, i, j, m_rootBoard, m_sizePiece);
		}
	}
}


void Matrix::UpdateBoard(float deltatime)
{
	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < getColumn(); j++)
		{
			m_matrix[i][j]->UpdatePiece(deltatime);
		}
	}
}


void Matrix::InitMatrix()
{
	
	this->InitMatrixPiece();
}

void Matrix::UpdateMatrix(float deltatime)
{
	this->UpdateBoard(deltatime);
}

void Matrix::RenderMatrix(sf::RenderWindow* window)
{
	window->draw(*m_frame);
	window->draw(*m_board);
	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < getColumn(); j++)
		{
			m_matrix[i][j]->RenderPeice(window);
		}
	}
}
