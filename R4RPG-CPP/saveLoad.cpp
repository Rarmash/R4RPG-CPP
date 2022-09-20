#include <iostream>
#include <fstream>
#include <stdio.h>
#include <Windows.h>
#include "Menus.h"
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

void save(Player &p) {
	json j;
	j["name"] = p.NAME;
	j["cls"] = p.CLS;
	j["level"] = p.LEVEL;
	j["xp"] = p.XP;
	j["maxxp"] = p.MAXXP;
	j["hp"] = p.HP;
	j["maxhp"] = p.MAXHP;
	j["pw"] = p.PW;
	j["healing"] = p.HEALING;
	remove("saves.json");
	ofstream o("saves.json");
	o << setw(4) << j << endl;
	BOOL result = SetFileAttributes(L"saves.json", FILE_ATTRIBUTE_HIDDEN);
	o.close();
}

void load(Player& p) {
	ifstream i("saves.json");
	json j;
	i >> j;
	p.NAME = j["name"];
	p.CLS = j["cls"];
	p.LEVEL = j["level"];
	p.XP = j["xp"];
	p.MAXXP = j["maxxp"];
	p.HP = j["hp"];
	p.MAXHP = j["maxhp"];
	p.PW = j["pw"];
	p.HEALING = j["healing"];
}