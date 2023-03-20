#include "GSPlay.h"

GSPlay::GSPlay()
{
	m_matrix = new Matrix();
	m_button_pause = new GameButton();
}

GSPlay::~GSPlay()
{
	if (m_matrix != nullptr)
		delete m_matrix;
	if (m_button_pause != nullptr)
		delete m_button_pause;
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

StateTypes GSPlay::getTypeState()
{
	return StateTypes::PLAY;
}

void GSPlay::InitButton()
{
	m_button_pause->Init(sf::Vector2f(90.f, 90.f), "ButtonGSPlay");
	m_button_pause->setPosition(sf::Vector2f(m_button_pause->getSize().x / 2.f + 30.f, m_button_pause->getSize().y / 2.f + 30.f));
	m_button_pause->setOnClick([]() { GSM->ChangeState(StateTypes::PAUSE); });
}


void GSPlay::Init()
{
	//Background
	sf::Texture* texture = DATA->getTexture("bgameplay1");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);
	m_Background.setScale(1.f, 1.f);

	InitButton();
	m_matrix->InitMatrix();
	m_player.Init();
	m_CollisionManager.addObj(m_player.getHitBox());
	for (int i = 0; i < m_matrix->getRow(); i++)
	{
		for (int j = 0; j < m_matrix->getColumn(); j++)
		{
			if (m_matrix->getPieceType(i, j) == 2)
			{
				m_CollisionManager.addObj(m_matrix->getCoin(i, j)->getHitBox());
			}
		}
	}

}

bool isPerforming = false;
float m_currentTime = 0;

bool iswin = false;
float m_checkTime = 0;

void GSPlay::Update(float deltatime)
{
	DATA->UpdateMusic("backmusic");
	if (isPerforming && m_currentTime < 0.5f) {
		m_currentTime += deltatime;
		m_matrix->UpdateMatrix(deltatime);
		m_player.Update(deltatime);
		m_button_pause->Update(deltatime);
		m_CollisionManager.Update();
		return;
	}
	else m_currentTime = 0, isPerforming = false;

	m_matrix->UpdateMatrix(deltatime);
	m_player.Update(deltatime);
	m_button_pause->Update(deltatime);
	std::ifstream fin("../Data/Text/sizelevel_" + std::to_string(DATA->getMapLevel()) + ".txt");
	int x; fin >> x;
	int y; fin >> y;
	int posx, posy;
	 posy = (int)((m_player.getHitBox()->getPosition().x - x) / 80-0.5f);
	 posx = (int)((m_player.getHitBox()->getPosition().y - y) / 80-0.5f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		DATA->playSound("walking");
		for (int i = 1; i <= m_matrix->getColumn(); i++)
		{
			if ((posx >= 0 && posx < m_matrix->getRow() && (posy + i) >= 0 && (posy + i < m_matrix->getColumn()))&&
				(m_matrix->getPieceType(posx, posy + i) == 1 || m_matrix->getPieceType(posx, posy + i) == 2))
			{
				continue;
			}
			else {
				m_player.setRow(posx);
				m_player.setColumn(posy+i-1);
				m_player.setPath(abs((i - 1) * 80));
				m_player.changeNextStage(IPState::State::RUNRIGHT);
				isPerforming = true;
				break;
			}

		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		DATA->playSound("walking");
		for (int i = 1; i <= m_matrix->getColumn(); i++)
		{
			if ((posx >= 0 && posx < m_matrix->getRow() && (posy - i) >= 0 && (posy - i < m_matrix->getColumn()))
				&& (m_matrix->getPieceType(posx, posy - i) == 1 || m_matrix->getPieceType(posx, posy - i) == 2))
			{
				
				continue;
			}
			else {
				m_player.setRow(posx);
				m_player.setColumn(posy-i+1);
				m_player.setPath(abs((-i + 1) * 80));
				m_player.changeNextStage(IPState::State::RUNLEFT);
				isPerforming = true;
				break;
			}
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		DATA->playSound("walking");
		for (int i = 1; i <= m_matrix->getRow(); i++)
		{
			if ((posx - i >= 0 && posx - i < m_matrix->getRow() && posy >= 0 && posy < m_matrix->getColumn())
				&& (m_matrix->getPieceType(posx - i, posy) == 1 || m_matrix->getPieceType(posx - i, posy) == 2))
			{
				
				continue;
			}
			else{
				
				m_player.setRow(posx - i + 1);
				m_player.setColumn(posy);
				m_player.setPath(abs((-i + 1) * 80));
				m_player.changeNextStage(IPState::State::RUNUP);
				
				isPerforming = true;
				break;
			}
		}
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		DATA->playSound("walking");
		for (int i = 1; i <= m_matrix->getRow(); i++)
		{
			if ((posx + i >= 0 && posx + i < m_matrix->getRow() && posy >= 0 && posy < m_matrix->getColumn())
				&& (m_matrix->getPieceType(posx + i, posy) == 1 || m_matrix->getPieceType(posx + i, posy) == 2))
			{
				
				continue;
			}
			else
			{
				
				m_player.setRow(posx + i - 1);
				m_player.setColumn(posy);
				m_player.setPath(abs((i - 1) * 80));
				m_player.changeNextStage(IPState::State::RUNDOWN);
				isPerforming = true;
				break;
			}
		}
			
		
	}
	if (m_matrix->checkCoin())
	{
		iswin = true;
		DATA->setResultGame(iswin);
		m_checkTime += deltatime;
		if (m_checkTime >= 1.5f)
		{
			m_checkTime = 0.f;
			DATA->playSound("mixkit-achievement-bell-600");
			GSM->ChangeState(StateTypes::END);
		}
	}
		
	m_CollisionManager.Update();
	
}

void GSPlay::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	m_matrix->RenderMatrix(window);
	m_player.Render(window);
	m_button_pause->Render(window);
}
