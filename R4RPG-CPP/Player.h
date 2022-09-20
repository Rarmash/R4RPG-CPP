#pragma once
#include <string>
class Player
{
public:
	std::string NAME;
	std::string CLS;
	int LEVEL;
	int XP;
	int MAXXP;	
	int HP;
	int MAXHP;
	int PW;
	int HEALING;

	void menu_stats();
};

