#pragma once
#include "Libraries.h"
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
	int SP;
	int MONEY;
	int HPPOTION;
	std::string LOCATION;
	bool SANDSPASS;

	void menu_stats();
};

