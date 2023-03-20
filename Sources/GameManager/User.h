#pragma once
#include"Singleton.h"
#include<string>

#define USER User::GetInstance()

class User :public CSingleton<User> {
private:
	std::string m_user_name;
	int m_level;
public:
	User();
	~User();
	void InitUser(std::string name, int level);
	std::string getName();
	void setLevel(int level);
	int getlevel();
};