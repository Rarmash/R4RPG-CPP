#pragma once
#include "Player.h"
using namespace std;

void mainmenu(Player &p);
void menu_fight(Player &p);
void menu_upgrade(Player& p);

void save(Player& p);
void load(Player& p);
void saveCreate(Player& p);