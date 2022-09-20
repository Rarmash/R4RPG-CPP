#pragma once
#include <string>
class Player
{
public:
	std::string NAME = "Player";
	std::string CLS = "Warrior";
	int LEVEL = 1;
	int XP = 0;
	int MAXXP = 5;	
	int HP = 10;
	int MAXHP = 10;
	int PW = 2;
	int HEALING = 2;

	void menu_stats();
};

