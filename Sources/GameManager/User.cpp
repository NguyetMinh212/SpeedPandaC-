#include "User.h"

User::User()
{
	m_level = 1;
	m_user_name = "Nguyet Minh";
}

User::~User()
{
}

void User::InitUser(std::string name, int level)
{
	m_user_name = name;
	m_level = level;
}

std::string User::getName()
{
	return m_user_name;
}

void User::setLevel(int level)
{
	m_level = level;
}

int User::getlevel()
{
	return m_level;
}
