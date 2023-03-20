#include "Piece.h"

Piece::Piece()
{
    m_Type = PieceType::PATH;
    m_x = m_y = 0;
    m_r = m_c = 0;
    //m_ani = new Animation(*DATA->getTexture("Pieces/coins"), sf::Vector2i(16, 1), 0.05f);
   // m_ani->setScale(0.5f, 0.5f);
    //m_coin.Init();
}

Piece::~Piece()
{
}

int Piece::getType()
{
    switch (m_Type)
    {
    case PieceType::TREEBLOCK:
        return 0;
    case PieceType::PATH:
        return 1;
    case PieceType::COIN:
        return 2;
    default:
        break;
    }
    return 0;
}

void Piece::setX(float x)
{
    m_x = x;
}

float Piece::getX()
{
    return m_x;
}

void Piece::setY(float y)
{
    m_y = y;
}

float Piece::getY()
{
    return m_y;
}

void Piece::setR(int r)
{
    m_r = r;
}

int Piece::getR()
{
    return m_r;
}

void Piece::setC(int c)
{
    m_c = c;
}

int Piece::getC()
{
    return m_c;
}

Coin* Piece::getCoin()
{
    Coin* x = m_checklistCoin.front();
    m_checklistCoin.pop_front();
    return x;
}


void Piece::setPiece(int type)
{
   std::string path = "Pieces/";
   switch (type)
   {
   case 0:
       m_Type = PieceType::TREEBLOCK;
       //sf::Texture* texture = DATA->getTexture(path + "treeblock");
       setTexture(DATA->getTexture(path + "Untitled design (10)"));
       break;
   case 1:
       m_Type = PieceType::PATH;
       setTexture(DATA->getTexture(path + "Untitled design (6)"));
       break;
   case 2:
       m_Type = PieceType::COIN;
       setTexture(DATA->getTexture(path + "Untitled design (6)"));
       Coin* coin = new Coin();
       coin->Init();
      coin->getHitBox()->setPosition(sf::Vector2f(m_root.x + m_x, m_root.y + m_y));
       m_listCoin.push_back(coin);
       m_checklistCoin.push_back(coin);
       break;
   //default:
       //break;
   }
}

void Piece::InitPiece(int type, int row, int column, sf::Vector2f root, sf::Vector2f size)
{
    m_root = root;
    m_size = size;
    m_r = row;
    m_c = column;
    m_x = m_size.x * (m_c + 0.5f);
    m_y = m_size.y * (m_r + 0.5f);

    this->setPiece(type);
    this->setSize(sf::Vector2f(80.f, 80.f));
    this->setOrigin(this->getSize() / 2.f);

   // this->setOutlineThickness(5.f);
    this->setPosition(sf::Vector2f(m_root.x + m_x, m_root.y + m_y));
}

void Piece::UpdatePiece(float deltatime)
{
    this->setPosition(sf::Vector2f(m_root.x + m_x, m_root.y + m_y));
    //m_coin.Update(deltatime);
    for (auto it : m_listCoin)
    {
        it->Update(deltatime);
    }
    this->setFillColor(sf::Color(255, 255, 255, 255));
}

void Piece::RenderPeice(sf::RenderWindow* window)
{
    window->draw(*this);
    //m_coin.Render(window);
    for (auto it : m_listCoin)
    {
        if (!it->getHitBox()->isAlive())
        {
            if (this->getType() == 2)
            {
                DATA->playSound("coinswin");
                this->setPiece(1);
            }
            continue;
        }
        it->Render(window);
    }
}
