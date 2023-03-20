#include "GSPause.h"

GSPause::GSPause()
{
	m_frame = new sf::RectangleShape();
	m_button_home = new GameButton();
	m_button_music = new GameButton();
	m_button_resume = new GameButton();
	m_button_sound = new GameButton();
}

GSPause::~GSPause()
{
	if (m_frame != nullptr)
		delete m_frame;
	if (m_button_home != nullptr)
		delete m_button_home;
	if (m_button_music != nullptr)
		delete m_button_music;
	if (m_button_resume != nullptr)
		delete m_button_resume;
	if (m_button_sound != nullptr)
		delete m_button_sound;
}

void GSPause::Exit()
{
}

void GSPause::Pause()
{
}

void GSPause::Resume()
{
}

StateTypes GSPause::getTypeState()
{
	return StateTypes::PAUSE;
}
void GSPause::initBoard()
{
	m_frame->setSize(sf::Vector2f(660.f, 660.f));
	m_frame->setTexture(DATA->getTexture("Frame/Pause"));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(screenWidth / 2.f, screenHeight / 2.f + 10.f);
}

void GSPause::initButtonSound()
{
	m_button_sound->Init(sf::Vector2f(120.f, 120.f), "ButtonSoundOn");
	m_button_sound->setPosition(m_frame->getPosition() + sf::Vector2f(80.f, -100.f));
	m_button_sound->setOnClick([]() { DATA->setAllowSound(true - DATA->isAllowSound()); });
	
}

void GSPause::initButtonMusic()
{
	m_button_music->Init(m_button_sound->getSize(), "ButtonMusicOn");
	m_button_music->setPosition(m_frame->getPosition() + sf::Vector2f(-100.f, -100.f));
	m_button_music->setOnClick([]() { DATA->setAllowMusic(true - DATA->isAllowMusic()); });
}

void GSPause::initButtonResume()
{
	m_button_resume->Init(sf::Vector2f(274.f, 115.f), "bar_Resume");
	m_button_resume->setPosition(m_frame->getPosition() + sf::Vector2f(-10.f, 35.f));
	m_button_resume->setOnClick([]() { GSM->PopState(); });
}

void GSPause::initButtonHome()
{
	m_button_home->Init(m_button_resume->getSize(), "bar_Home");
	m_button_home->setPosition(m_button_resume->getPosition() + sf::Vector2f(0.f, 120.f));
	m_button_home->setOnClick([]() { GSM->ChangeState(StateTypes::WARNING_HOME); });
}

void GSPause::updateButtonSound(float deltatime)
{
	m_button_sound->Update(deltatime);
	if (DATA->isAllowSound())
	{
		m_button_sound->setTexture(DATA->getTexture("Button/ButtonSoundOn"));

	}
	else
		m_button_sound->setTexture(DATA->getTexture("Button/ButtonSoundOff"));
	
}

void GSPause::updateButtonMusic(float deltatime)
{
	m_button_music->Update(deltatime);
	if (DATA->isAllowMusic())
		m_button_music->setTexture(DATA->getTexture("Button/ButtonMusicOn"));
	else
		m_button_music->setTexture(DATA->getTexture("Button/ButtonMusicOff"));
}

void GSPause::Init()
{
	//Background
	sf::Texture* texture = DATA->getTexture("bgameplay1");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);
	m_Background.setScale(1.f, 1.f);

	this->initBoard();
	this->initButtonSound();
	this->initButtonMusic();
	this->initButtonResume();
	this->initButtonHome();
}

void GSPause::Update(float deltatime)
{
	DATA->UpdateMusic("backmusic");
	this->updateButtonMusic(deltatime);
	this->updateButtonSound(deltatime);
	m_button_home->Update(deltatime);
	m_button_resume->Update(deltatime);
}

void GSPause::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(*m_frame);
	window->draw(*m_button_home);
	window->draw(*m_button_music);
	window->draw(*m_button_resume);
	window->draw(*m_button_sound);
}

