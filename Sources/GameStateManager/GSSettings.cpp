#include "GSSettings.h"

GSSettings::GSSettings()
{
	m_frame = new sf::RectangleShape();
	m_button_home = new GameButton();
	m_button_music = new GameButton();
	m_button_sound = new GameButton();
}

GSSettings::~GSSettings()
{
	if (m_frame != nullptr)
		delete m_frame;
	if (m_button_home != nullptr)
		delete m_button_home;
	if (m_button_music != nullptr)
		delete m_button_music;
	if (m_button_sound != nullptr)
		delete m_button_sound;
}

void GSSettings::Exit()
{
}

void GSSettings::Pause()
{
}

void GSSettings::Resume()
{
}

StateTypes GSSettings::getTypeState()
{
	return StateTypes::SETTINGS;
}

void GSSettings::Init()
{
	//Background
	sf::Texture* texture = DATA->getTexture("background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);
	m_Background.setScale(1.f, 1.f);

	this->initBoard();
	this->initButtonSound();
	this->initButtonMusic();
	this->initButtonHome();
}

void GSSettings::Update(float deltatime)
{
	DATA->UpdateMusic("backmusic");
	this->updateButtonMusic(deltatime);
	this->updateButtonSound(deltatime);
	m_button_home->Update(deltatime);
}

void GSSettings::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(*m_frame);
	window->draw(*m_button_home);
	window->draw(*m_button_music);
	window->draw(*m_button_sound);
}

void GSSettings::initBoard()
{
	m_frame->setSize(sf::Vector2f(660.f, 660.f));
	m_frame->setTexture(DATA->getTexture("Frame/Pause"));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(screenWidth / 2.f, screenHeight / 2.f + 10.f);
}

void GSSettings::initButtonSound()
{
	m_button_sound->Init(sf::Vector2f(120.f, 120.f), "ButtonSoundOn");
	m_button_sound->setPosition(m_frame->getPosition() + sf::Vector2f(80.f, -60.f));
	m_button_sound->setOnClick([]() { DATA->setAllowSound(true - DATA->isAllowSound()); });
}

void GSSettings::initButtonMusic()
{
	m_button_music->Init(m_button_sound->getSize(), "ButtonMusicOn");
	m_button_music->setPosition(m_frame->getPosition() + sf::Vector2f(-100.f, -60.f));
	m_button_music->setOnClick([]() { DATA->setAllowMusic(true - DATA->isAllowMusic()); });
}

void GSSettings::initButtonHome()
{
	m_button_home->Init(sf::Vector2f(274.f, 115.f), "bar_Home");
	m_button_home->setPosition(m_frame->getPosition() + sf::Vector2f(-20.f, 120.f));
	m_button_home->setOnClick([]() { GSM->PopState(); });
}

void GSSettings::updateButtonSound(float deltatime)
{
	m_button_sound->Update(deltatime);
	if (DATA->isAllowSound())
		m_button_sound->setTexture(DATA->getTexture("Button/ButtonSoundOn"));
	else
		m_button_sound->setTexture(DATA->getTexture("Button/ButtonSoundOff"));
}

void GSSettings::updateButtonMusic(float deltatime)
{
	m_button_music->Update(deltatime);
	if (DATA->isAllowMusic())
		m_button_music->setTexture(DATA->getTexture("Button/ButtonMusicOn"));
	else
		m_button_music->setTexture(DATA->getTexture("Button/ButtonMusicOff"));
}
